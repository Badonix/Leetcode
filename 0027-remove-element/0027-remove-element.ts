function removeElement(nums: number[], val: number): number {
    let count = 0
    let arr = []
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] != val) {
            nums[count] = nums[i]
            count++
        }
    }
    return count
};