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
    public ListNode removeNodes(ListNode head) {
        int max = Integer.MIN_VALUE;
        ListNode prev = null;
        ListNode curr = head;
        if(head == null || head.next == null){
            return head;
        }
        while(curr != null){
            ListNode temp = curr.next;
            if(curr.val > max){
                max = curr.val;
            }
            curr.next = prev;
            prev = curr;
            curr = temp;
        }
        int currMax = prev.val;
        ListNode answ = prev;
        ListNode c = prev;
        ListNode n = c.next;
        while(c.next != null){
            if(n == null){
                c.next = null;
                break;
            }
            if(n.val < currMax){
                n = n.next;
                continue;
            }
            if(n.val >= currMax){
                currMax = n.val;
                c.next = n;
                n = n.next;
                c = c.next;
            }
        }
        ListNode prev2 = null;
        ListNode curr2 = answ;
        while(curr2 != null){
            ListNode temp = curr2.next;
            curr2.next = prev2;
            prev2 = curr2;
            curr2 = temp;
        }
        return prev2;
    }
}