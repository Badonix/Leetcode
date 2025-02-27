public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        int firstLength = 0;
        int secondLength = 0;
        ListNode headADummy = headA;
        ListNode headBDummy = headB;

        while (headADummy != null) {
            headADummy = headADummy.next;
            firstLength++;
        }
        while (headBDummy != null) {
            headBDummy = headBDummy.next;
            secondLength++;
        }

        if (firstLength > secondLength) {
            for (int i = 0; i < firstLength - secondLength; i++) {
                headA = headA.next;
            }
        } else {
            for (int i = 0; i < secondLength - firstLength; i++) {
                headB = headB.next;
            }
        }

        while (headA != null && headB != null) {
            if (headA == headB) {
                return headA;
            }
            headA = headA.next;
            headB = headB.next;
        }

        return null;
    }
}
