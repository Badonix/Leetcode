function finalValueAfterOperations(operations: string[]): number {
    let value = 0
    operations.forEach((el)=>{
        if(el[0] == "+" || el[2] == "+"){
            value++
        }else{
            value--
        }
    })
    return value
};