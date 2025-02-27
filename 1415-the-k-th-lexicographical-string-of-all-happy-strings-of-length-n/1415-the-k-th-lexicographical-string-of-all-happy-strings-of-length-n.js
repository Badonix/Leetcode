/**
 * @param {number} n
 * @param {number} k
 * @return {string}
 */
var getHappyString = function(n, k) {
    let all = []
    let pos = ['a','b','c']
    backtrack("")

    function backtrack(curr){
        if(all.length == k){
            return
        }
        if(curr.length == n){
            all.push(curr)
            return
        }
        for(let i = 0; i < pos.length; i++){
            if(curr.length == 0){
                backtrack(pos[i])
            }else{
                if(curr[curr.length - 1] == pos[i]){
                    continue
                }
                backtrack(curr + pos[i])
            }

        }
    }
    if(all.length == k){
        return all[all.length - 1]
    }else{
        return ""
    }
};