/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode insertGreatestCommonDivisors(ListNode head) {
        ListNode dummy = head;
        ListNode left = head;
        ListNode right = head.next;
        if(right == null || left == null){
            return left;
        }
        while(right != null){
            int currGcd = gcd(left.val, right.val);
            ListNode newNode = new ListNode(currGcd);
            left.next = newNode;
            newNode.next = right;
            left = right;
            right = right.next;
        }
        return dummy;     
    }
    private int gcd(int a, int b){
        return b == 0 ? a : gcd(b, a % b);    
    }
}