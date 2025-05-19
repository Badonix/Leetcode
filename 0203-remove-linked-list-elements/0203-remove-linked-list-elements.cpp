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
    ListNode* removeElements(ListNode* head, int val) {
       ListNode* prev = new ListNode(-1);
       prev->next = head;
       ListNode* answ = prev;
       ListNode* dummy = head;
       while(dummy){
        if(dummy->val != val){
            prev = dummy;
            dummy = dummy->next;
        }else{
           while(dummy && dummy->val == val){
            dummy = dummy->next;
           } 
           prev->next = dummy;
           prev = dummy;
        }
       } 
       return answ->next;
    }
};