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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* answ = head;
        ListNode* dummy = answ;
        ListNode* it = head->next;
        while(it){
            int sum = 0;
            while(it->val != 0){
                sum += it->val;
                it = it->next;
            }
            ListNode* curr = new ListNode(sum);
            dummy->next = curr;
            dummy = dummy->next;
            curr = curr->next;
            it = it->next;
        }
        return answ->next;
    }
};