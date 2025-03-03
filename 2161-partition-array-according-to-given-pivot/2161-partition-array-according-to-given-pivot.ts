function pivotArray(nums: number[], pivot: number): number[] {
    let smaller = []
    let bigger = []
    let mid = [];
    nums.forEach((el)=>{
        if(el < pivot){
            smaller.push(el)
        }else if(el > pivot){
            bigger.push(el)
        }else{
            mid.push(pivot)
        }
    })
    return [...smaller, ...mid, ...bigger]
};