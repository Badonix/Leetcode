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
    public ListNode modifiedList(int[] nums, ListNode head) {
        HashSet<Integer> hashset = new HashSet<>();     
        for(int num : nums){
            hashset.add(num);
        }        
        ListNode left = new ListNode();
        ListNode dummy = left;
        ListNode right = head;
        left.next = head;
        while(left.next != null){
            if(right == null){
                break;
            }
            while(hashset.contains(right.val)){
                right = right.next;
                if(right == null){
                    break;
                }
            }
            left.next = right;
            if(right == null){
                break;
            }
            right = right.next;
            left = left.next;
        }        
        return dummy.next;
    }
}