function myAtoi(s: string): number {
    let trimmed = s.trim();
    let isNegative = false;
    let nums = "1234567890"
    if(trimmed[0] == "-"){
        isNegative = true
    }
    if(trimmed[0] == "+" || trimmed[0] == "-"){
        trimmed = trimmed.substring(1)
    }
    let answ: string | number= ""
    for(let i = 0; i < trimmed.length; i++){
        if(!nums.includes(trimmed[i])){
            break
        }
        answ += trimmed[i]
    }
    if(answ.length == 0){
        answ = "0"
    }
    
    answ = parseInt(answ)
    if(isNegative){
        answ *= -1
    }

    if(answ < -1*2**31){
        answ = -1*2**31
    }else if(answ >= 2**31){
        answ = 2**31 - 1
    }
    return answ
};