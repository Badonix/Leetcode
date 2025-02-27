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

function middleNode(head: ListNode | null): ListNode | null {
    let length = 0
    let counterHead = head
    let target
    let targetHead
    while(counterHead){
        counterHead = counterHead.next
        length++
    }
    if(length % 2 == 0){
        target = (length + 2) / 2
    }else{
        target = (length + 1) / 2
    }
    for(let i = 0; i<= target; i++){
        if(i == target - 1){
            targetHead = head
            break
        }
        head = head.next
    }
    return targetHead
};