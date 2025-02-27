function largestNumber(nums: number[]): string {
    let allZeros = true;
    for(let i = 0; i < nums.length; i++){
        if(nums[i] != 0){
            allZeros = false;
            break
        }
    }
    if(allZeros){
        return "0"
    }
    return nums.sort((a, b) => (b.toString() + a.toString()).localeCompare(a.toString() + b.toString())).join("");
};