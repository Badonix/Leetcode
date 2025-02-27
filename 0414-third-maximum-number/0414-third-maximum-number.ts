function thirdMax(nums: number[]): number {
    let first = null
    let second = null
    let third = null
    nums.forEach((el)=>{
        if(el == first || el == second || el == third){
            
        }else{

        if(first == null || el > first){
            third = second
            second = first
            first = el
        }else if(second == null || el > second){
            third = second
            second = el
        }else if(third == null || el > third){
            third = el
        }
        }

    })
    if(third != null){
        return third
    }else{
        return first
    }
};