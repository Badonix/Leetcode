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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        } 
        ListNode* temp = slow->next;
        slow->next = nullptr;
        ListNode* secondPart = reverse(temp);
        head = mergeAlternating(head, secondPart);
    }
    ListNode* mergeAlternating(ListNode* first, ListNode* second) {
        if (!first) return second;
        if (!second) return first;
        ListNode* head = first;
        while (first && second) {
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;
            first->next = second;
            if (temp1) {
                second->next = temp1;
            }
            first = temp1;
            second = temp2;
        }
    
        return head;
    }

    ListNode* reverse(ListNode* node){
        ListNode* prev = nullptr;
        ListNode* dummy = node;
        while(dummy){
            ListNode* temp = dummy->next;
            dummy->next = prev;
            prev = dummy;
            dummy = temp;
        }
        return prev;
    }
};