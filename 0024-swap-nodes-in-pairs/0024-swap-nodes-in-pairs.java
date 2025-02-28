class Solution {
    public ListNode swapPairs(ListNode head) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode previous = dummy;
        ListNode current = head;
        
        while (current != null && current.next != null) {
            ListNode nextPair = current.next.next;
            
            ListNode second = current.next;
            second.next = current;
            current.next = nextPair;
            previous.next = second;
            
            previous = current;
            current = nextPair;
        }
        
        return dummy.next;
    }
}
