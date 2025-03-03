/**
 * Definition for singly-linked list.
 * public class ListNode {
 * int val;
 * ListNode next;
 * ListNode() {}
 * ListNode(int val) { this.val = val; }
 * ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if (head == null || head.next == null || k == 0) {
            return head;
        }
        ListNode dummy = head;
        ListNode secondHead = head;
        int length = 0;

        while (dummy != null) {
            dummy = dummy.next;
            length++;
        }

        int correct = k % length;
        if(correct == length || correct == 0){
            return head;
        }
        for (int i = 0; i < length - correct - 1; i++) {
            secondHead = secondHead.next;
        }
        ListNode rightPart = secondHead.next;
        ListNode toReturn = rightPart;
        secondHead.next = null;

        if (rightPart != null) {
            while (rightPart.next != null) {
                rightPart = rightPart.next;
            }
        }
        if(rightPart != null){
            rightPart.next = head;
        }

        return toReturn;
    }
}