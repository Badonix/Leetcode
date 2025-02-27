function shuffle(nums: number[], n: number): number[] {
    const buf = []
    for (let i = 0; i < n; i++){
        buf.push(nums[i], nums[i+n])
    }
    return buf
};