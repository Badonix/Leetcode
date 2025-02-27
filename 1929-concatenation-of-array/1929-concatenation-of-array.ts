function getConcatenation(nums: number[]): number[] {
    let answ = Array(nums.length * 2).fill(0)
    answ.forEach((el, i)=>{
        answ[i] = nums[i%nums.length]
    })
    return answ
};