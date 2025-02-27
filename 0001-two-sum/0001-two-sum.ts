function twoSum(nums: number[], target: number): number[] {
    let left = 0
    let right = 1
    for (let i = 0; i < nums.length * nums.length - 1; i++){
        if(nums[left] + nums[right] == target){
            break
        }
        if(right == nums.length - 1){
            left++
            right = 0
        }else{
            if(left == right + 1){
                right += 2
            }else{
                right++
            }
        }

    }
    return [left, right]
};