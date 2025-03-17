function divideArray(nums: number[]): boolean {
    let map = {}
    nums.forEach((el)=>{
        if(map[el] == undefined){
            map[el] = 1;
        }else{
            map[el]++
        }
    })
    for(let key in map){
        if(map[key] % 2 == 1){
            return false
        }
    }
    return true
};