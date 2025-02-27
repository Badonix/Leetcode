function containsDuplicate(nums: number[]): boolean {
    let hashmap = {}
    let contains = false
    for(let i = 0; i < nums.length; i++){
        if(hashmap[nums[i]]){
            contains = true
            break
        }else{
            hashmap[nums[i]] = 1
        }
    }
    return contains
};