/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var permute = function(nums) {
    let answ = []
    backtrack([], new Set(nums))
    function backtrack(current, left){
        if(current.length == nums.length){
            answ.push([...current])
            return
        }

        for(let i = 0; i < nums.length; i++){
            if(left.has(nums[i])){
                left.delete(nums[i])
                backtrack([...current, nums[i]], left)
                left.add(nums[i])
            }
        }
    }
    return answ
};
