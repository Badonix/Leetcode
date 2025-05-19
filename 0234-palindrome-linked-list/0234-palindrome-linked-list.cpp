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
    bool isPalindrome(ListNode* head) {
        queue<int> q;
        ListNode* dummy = head;
        if(!head || !(head->next)){
            return true;
        }

        ListNode* prev = nullptr;
        while(dummy){
            q.push(dummy->val);
            ListNode* temp = dummy->next;
            dummy->next = prev;
            prev = dummy;
            dummy = temp;
        } 
        while(prev){
            if(q.empty() || q.front() != prev->val){
                return false;
            }
            q.pop();
            prev = prev->next;
        }
        return true;
    }
};