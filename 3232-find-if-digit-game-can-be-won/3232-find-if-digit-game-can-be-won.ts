function canAliceWin(nums: number[]): boolean {
    let doubleDigit = 0
    let singleDigit = 0
    for(let i = 0; i < nums.length; i++){
        if(nums[i] < 10){
            singleDigit += nums[i]
        }else{
            doubleDigit += nums[i]
        }
    }
    if(doubleDigit == singleDigit){
        return false
    }else{
        return true
    }
};