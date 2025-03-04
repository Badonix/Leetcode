function checkPowersOfThree(n: number): boolean {
    while(n != 0){
        let rem = n % 3 
        if(rem == 2){
            return false
        }
        n = Math.floor(n / 3)
    }
    return true
};