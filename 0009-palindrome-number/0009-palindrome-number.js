/**
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function(x) {
    let arr = x.toString().split("")
    let arrReverse = arr.slice().reverse()
    var palindrome = true
    for(let i = 0; i < arr.length; i++){
        if(arrReverse[i] != arr[i]){
            palindrome = false
            break
        }
    }
    return palindrome
};
