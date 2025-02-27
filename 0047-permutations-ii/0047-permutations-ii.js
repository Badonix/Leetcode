/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var permuteUnique = function(nums) {
    let answ = [];
    let count = {}
    for(let i = 0; i < nums.length; i++){
        if(count[nums[i]] == undefined){
            count[nums[i]] = 1
        }else{
            count[nums[i]]++
        }
    }
    backtrack([]);

    function backtrack(curr) {
        if(curr.length == nums.length){
            answ.push([...curr])
            return
        }
        for(let key in count){
            if(count[key] > 0){
                count[key]--
                backtrack([...curr, Number(key)])
                count[key]++
            }
        }
    }
    
    return answ;
};