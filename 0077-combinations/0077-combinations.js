/**
 * @param {number} n
 * @param {number} k
 * @return {number[][]}
 */
var combine = function(n, k) {
    let answ = []
    
    function backtrack(start, curr) {
        if (curr.length === k) {
            answ.push([...curr])
            return
        }
        for (let i = start; i <= n; i++) {
            curr.push(i)
            backtrack(i + 1, curr)
            curr.pop()
        }
    }
    
    backtrack(1, [])
    return answ
};
