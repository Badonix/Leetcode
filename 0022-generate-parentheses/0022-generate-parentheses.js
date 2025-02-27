/**
 * @param {number} n
 * @return {string[]}
 */
var generateParenthesis = function(n) {
    let answ = []
    backtrack("", 0, 0)
    
    function backtrack(curr, openingCount, closingCount){
        if(curr.length == 2*n){
            answ.push(curr)
            return
        }
        if(openingCount == n){
            backtrack(curr + ")", openingCount, closingCount + 1)
        }
        if(openingCount != n){
            backtrack(curr + "(", openingCount + 1, closingCount)
            if(closingCount < openingCount){
                backtrack(curr + ")", openingCount, closingCount + 1)
            }
        }
    }
    return answ;
};