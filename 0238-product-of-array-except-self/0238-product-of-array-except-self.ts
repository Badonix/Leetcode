function productExceptSelf(nums: number[]): number[] {
    let leftPrefixes = []
    let rightPrefixes = []
    let left = 1
    let right = 1
    for(let i = 0; i < nums.length; i++){
        if(nums[i - 1] != undefined){
            left *= nums[i - 1]
        }
        leftPrefixes.push(left)
    }
    for(let i = nums.length - 1; i >= 0; i--){
        if(nums[i + 1] != undefined){
            right *= nums[i + 1]
        }
        rightPrefixes.push(right)
    }
    let answArr = []
    for(let i = 0; i < nums.length; i++){
        answArr.push(leftPrefixes[i] * rightPrefixes[nums.length - i - 1])
    }
    return answArr
};