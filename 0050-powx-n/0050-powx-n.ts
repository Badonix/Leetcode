function myPow(x: number, n: number): number {
    let isNegative = n < 0
    if(isNegative){
        n *= -1
    }
    if(n == 0){
        return 1;
    }
    let y = 1;
    let z = n;
    while (z != 0){
        let r = z % 2;
        z = Math.floor(z / 2)
        if(r == 1){
            y = x*y
        }
        x = x * x
    }
    return isNegative ? 1 / y : y
};