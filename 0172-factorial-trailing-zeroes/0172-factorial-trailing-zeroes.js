/**
 * @param {number} n
 * @return {number}
 */
var trailingZeroes = function(n) {
    let count = 0;
    for(let i = 5; i <= n; i+= 5){
        let n = i
        while(n%5 == 0){
            n /= 5
            count++
        }
    }
    return count
};