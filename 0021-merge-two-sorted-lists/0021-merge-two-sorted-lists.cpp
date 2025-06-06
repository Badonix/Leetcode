/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1 && !list2) return list1;
        if(list1 && !list2) return list1;
        if(!list1 && list2) return list2;

        ListNode* start = list1->val > list2->val ? list2 : list1;
        ListNode* tail = start;
        if(start == list1){
            list1 = list1->next;
        }
        if(start == list2){
            list1 = list2->next;
        }

        while(list1 && list2){
            if(list1->val >= list2->val){
                tail->next = list2;
                tail = tail->next;
                list2 = list2->next;
            }else{
                tail->next = list1;
                tail = tail->next;
                list1 = list1->next;
            }
        }

        if(list1){
            tail->next = list1;
        }
        if(list2){
            tail->next = list2;
        }
        return start;
    }
};