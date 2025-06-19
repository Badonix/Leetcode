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
    ListNode* sortList(ListNode* head) {
       if(!head || !head->next) return head;
       pair<ListNode*, ListNode*> p = split(head);
       ListNode* one = sortList(p.first); 
       ListNode* two = sortList(p.second); 
       return merge(one, two);
    }
    ListNode* merge(ListNode* one, ListNode* two){
        if(!two && !one) return {};
        if(!two) return one;
        if(!one) return two;
        ListNode* head;
        if(one->val > two->val){
            head = two;
            two = two->next;
        }else{
            head = one;
            one = one->next;
        }

        ListNode* dummy = head;
        while(one && two){
            if(one->val < two->val){
                dummy->next = one;
                one = one->next;
            }else{
                dummy->next = two;
                two = two->next;
            }            
            dummy = dummy->next;
        }
        if(one) dummy->next = one;
        if(two) dummy->next = two;
        return head;
    }
    pair<ListNode*, ListNode*> split(ListNode* head){
        pair<ListNode*, ListNode*> answ;
        answ.first = head;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        answ.second = slow->next;
        slow->next = nullptr;
        return answ;
    }
};