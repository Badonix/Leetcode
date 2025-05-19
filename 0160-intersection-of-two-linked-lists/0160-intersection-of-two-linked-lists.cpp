/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        int firstSize = 0, secondSize = 0;
        ListNode* dummy1 = headA;
        ListNode* dummy2 = headB;
        while (dummy1) {
            firstSize++;
            dummy1 = dummy1->next;
        }
        while (dummy2) {
            secondSize++;
            dummy2 = dummy2->next;
        }
        if (firstSize > secondSize) {
            for (int i = 0; i < firstSize - secondSize; i++) {
                headA = headA->next;
            }
        } else if (firstSize < secondSize) {
            for (int i = 0; i < secondSize - firstSize; i++) {
                headB = headB->next;
            }
        }
        while (true) {
            if (headA == headB) {
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};