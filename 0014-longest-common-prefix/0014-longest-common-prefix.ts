function longestCommonPrefix(strs: string[]): string {
    let count = 0
    let prefix = ""
    if(strs[0] == ""){
        return ""
    }
    while(true){
        let isPrefix = true
        let currentLetter = strs[0][count]
        for(let i = 0; i < strs.length; i++){
            if (strs[i][count] != currentLetter){
                isPrefix = false
                break
            }
        }
        if(isPrefix == false){
            break
        }else if (count == strs[0].length - 1){
            prefix += strs[0][count]
            break
        }else{
            prefix += strs[0][count]
        }
        count++
    }
    return prefix
};