function kidsWithCandies(candies: number[], extraCandies: number): boolean[] {
    let max = Math.max(...candies)
    let answ = []
    candies.forEach((el)=>{
        if(el+extraCandies >= max){
            answ.push(true)
        }else{
            answ.push(false)
        }
    })    
    return answ
};