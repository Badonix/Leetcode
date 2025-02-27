function findWordsContaining(words: string[], x: string): number[] {
    let indicies = []
    words.forEach((el, index)=>{
        for(let i = 0; i < el.length; i++){
            if(el[i] == x){
                indicies.push(index)
                break
            }
        }
    })
    return indicies
};