class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode left = dummy;
        ListNode right = head;
        while (right != null) {
            boolean isDuplicate = false;
            while (right.next != null && right.val == right.next.val) {
                right = right.next;
                isDuplicate = true;
            }
            if (isDuplicate) {
                left.next = right.next;
            } else {
                left = left.next;
            }
            right = right.next;
        }
        return dummy.next;
    }
}
