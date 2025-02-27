function plusOne(digits: number[]): number[] {
    for (let i = digits.length; i--; i>=0){
        if (i == 0 && digits[i] == 9){
            digits[i] = 0
            digits.unshift(1)
            break
        } 
        if(digits[i] != 9){
            digits[i] = digits[i] + 1
            break
        }else{
            digits[i] = 0
        }
  
    }
    return digits
};