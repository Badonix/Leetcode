function sumOfGoodNumbers(nums: number[], k: number): number {
    let count = 0;
    for(let i = 0; i < nums.length; i++){
        let left = nums[i - k]
        let right = nums[i+k]
        if(left == undefined){
            left = -Infinity
        }
        if(right == undefined){
            right = -Infinity
        }
        if(nums[i] > left && nums[i] > right){
            count += nums[i]
        }
    }
    return count
};