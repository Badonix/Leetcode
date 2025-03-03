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

function partition(head: ListNode | null, x: number): ListNode | null {
    if(head == null || head.next == null){
        return head
    }
    let arr = []
    let it = head
    let dummy = head;
    while(it != null){
        arr.push(it.val)
        it = it.next;
    }
    let smaller = []
    let mid = []
    let higher = []
    arr.forEach((el)=>{
        if(el < x){
            smaller.push(el)
        }else{
            higher.push(el)
        }
    })
    let newArr = [...smaller, ...mid, ...higher]
    newArr.forEach((el)=>{
        dummy.val = el
        dummy = dummy.next
    })
    return head
};