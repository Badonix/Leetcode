function checkIfExist(arr: number[]): boolean {
    let hashmap = {}
    let exists = false
    let zeroCount = 0
    arr.forEach((el)=>{
        if(el == 0){
            zeroCount++
        }else if(!hashmap[el]){
            hashmap[el] = el
        } 
    })
    if(zeroCount >= 2){
        exists = true
    }else{
    for(let i = 0; i <arr.length; i++){

        if((hashmap[arr[i]/2] || hashmap[arr[i]*2])){
            exists = true
            break
        }
    }
    }

    return exists
};