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

function isPalindrome(head: ListNode | null): boolean {
    let arr = []
    while(head){
        arr.push(head.val)
        head = head.next
    }
    if(arr.reverse().join("") == arr.reverse().join("")){
        return true
    }else{
        return false
    }
};