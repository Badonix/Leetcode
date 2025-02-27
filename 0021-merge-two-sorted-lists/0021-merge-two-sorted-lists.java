class Solution {
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        ListNode dummy = new ListNode();
        ListNode newList = dummy;

        while (list1 != null && list2 != null) {
            if (list1.val <= list2.val) {
                newList.next = list1;
                list1 = list1.next;
            } else {
                newList.next = list2;
                list2 = list2.next;
            }
            newList = newList.next;
        }

        if (list1 != null) {
            newList.next = list1;
        } else {
            newList.next = list2;
        }

        return dummy.next;
    }
}
