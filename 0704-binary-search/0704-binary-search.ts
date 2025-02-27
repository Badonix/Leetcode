function search(nums: number[], target: number): number {
    let left = 0
    let right = nums.length - 1
    let index
    while(left <= right){
        let middle = Math.floor((left + right) / 2)
        if(nums[middle] == target){
            index = middle
            break
        }else if(nums[middle] > target){
            right = middle - 1
        }else{
            left = middle + 1
        }
    }
    if(index == undefined){
        return -1
    }else{
        return index
    }
};