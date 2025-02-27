function mySqrt(x: number): number {
    let max = 1
    if(x == 0){
        max = 0
    }else{

    for(let i = 1; i < x/2; i++){
        if((i+1) * (i+1) == x){
            max = i+1
            break
        }
        if((i+1) * (i+1) > x){
            max = i
            break
        }
    }
    }

    return max
};