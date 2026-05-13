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
        ListNode* dummy = head;
        
        while(dummy){
            ListNode* next_node = dummy->next;
            while(next_node && next_node->val == dummy->val){
                next_node = next_node->next;
            }
            dummy->next = next_node;
            dummy = dummy->next;
        }

        return head;
    }
};