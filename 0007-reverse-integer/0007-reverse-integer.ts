function reverse(x: number): number {
    let str = x + ""
    let isNegative = false
    if(str[0] == "-"){
        isNegative = true
    }
    if(isNegative){
        str = str.substring(1)
    }
    let answ = parseInt(str.split("").reverse().join(""))
    if(isNegative){
        answ *= -1
    }
    if(answ >= -1*(2**31) && answ < 2**31){
        return answ;
    }else{
        return 0;
    }
};