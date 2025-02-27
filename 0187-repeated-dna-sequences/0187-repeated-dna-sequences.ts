function findRepeatedDnaSequences(s: string): string[] {
    let map = {}
    for(let i = s.length - 1; i > 8; i--){
        let j = i - 9;
        let sequence = ""
        for(let k = j; k <= i; k++){
            sequence += s[k]
        }
        if(map[sequence] == undefined){
            map[sequence] = 1
        }else{
            map[sequence]++
        }
    }
    let answ = []
    for(let key in map){
        if(map[key] > 1){
            answ.push(key)
        }
    }
    return answ
};