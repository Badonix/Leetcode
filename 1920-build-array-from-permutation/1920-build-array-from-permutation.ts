function buildArray(nums: number[]): number[] {
    let answ = []
    nums.forEach((el, i)=>{
        answ[i] = nums[el]
    })
    return answ
};