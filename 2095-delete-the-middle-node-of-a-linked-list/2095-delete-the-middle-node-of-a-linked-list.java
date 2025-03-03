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
    public ListNode deleteMiddle(ListNode head) {
        int length = 0;
        ListNode dummy = head;
        ListNode cl = head;
        if(head == null || head.next == null){
            return null;
        }
        while(dummy != null){
            dummy = dummy.next;
            length++;
        }
        int toGo = length / 2;
        int counter = 0;
        
        for(int i = 0; i < toGo - 1; i++){
            cl = cl.next;
        }
        cl.next = cl.next.next;
        return head;
    }
}