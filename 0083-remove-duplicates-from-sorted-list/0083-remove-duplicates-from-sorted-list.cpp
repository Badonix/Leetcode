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
    ListNode* deleteDuplicates(ListNode* head) {
       ListNode* prev = head; 
       ListNode* dummy = head; 
       ListNode* answ = dummy;
       while(dummy){
        while(dummy && dummy->val == prev->val){
            dummy = dummy->next;
        }
        prev->next = dummy;
        prev = dummy;
       }
       return answ;
    }
};