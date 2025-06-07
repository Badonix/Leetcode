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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* prev = new ListNode(0);
        prev->next = head;
        ListNode* dummy = head;
        while(dummy && dummy->next){
            if(dummy->next->val >= dummy->val){
                dummy = dummy->next;
                continue;
            }
            ListNode* it = prev;
            while (it->next->val < dummy->next->val) {
                it = it->next;
            }
            ListNode* toInsert = dummy->next;
            dummy->next = toInsert->next;
            toInsert->next = it->next;
            it->next = toInsert;
        }
        return prev->next;
    }
};