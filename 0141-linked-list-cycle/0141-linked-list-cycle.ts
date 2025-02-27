/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

function hasCycle(head: ListNode | null): boolean {
    let slow = head
    let fast = head
    let isCycle = false
    while(slow && slow.next != undefined){
        if(slow.next == undefined || fast.next == undefined || fast.next.next == undefined){
            break
        }
        slow = slow.next
        fast = fast.next.next
        if(slow == fast){
            isCycle = true
            break
        }
    }
    return isCycle
};