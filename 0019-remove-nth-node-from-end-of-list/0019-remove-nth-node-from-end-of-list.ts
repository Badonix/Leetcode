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

function removeNthFromEnd(head: ListNode | null, n: number): ListNode | null {
    let length = 0
    let prev = head
    let result = head
    while(prev){
        length++
        prev = prev.next
    }
    if(length == 1){
        return result.next
    }
    let indexToRemove = length - n - 1
    if(indexToRemove == -1){
        return result.next
    }
    for(let i = 0; i < indexToRemove; i++){
        head = head.next
    }
    if(head.next == undefined){
        return result
    }
    head.next = head.next.next
    return result
};