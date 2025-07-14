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
    int getDecimalValue(ListNode* head) {
        ListNode* reversed = reverse(head);
        int answ = 0;
        int curr = 1;
        while(reversed){
            answ += reversed->val * curr;
            reversed = reversed->next;
            curr *= 2;
        }
        return answ;
    }
    ListNode* reverse(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* dummy = head;
        while(dummy){
            ListNode* temp = dummy->next;
            dummy->next = prev;
            prev = dummy;
            dummy = temp;
        }
        return prev;
    }
};