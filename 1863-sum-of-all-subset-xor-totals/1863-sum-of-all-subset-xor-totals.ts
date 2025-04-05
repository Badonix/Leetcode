function subsetXORSum(nums: number[]): number {
    let total = 0;
    nums.forEach((el)=>{
        total |= el;
    })
    return total * (1 << (nums.length - 1))
};