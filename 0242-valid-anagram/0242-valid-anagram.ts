function isAnagram(s: string, t: string): boolean {
    let first = {}
        let second = {}
        for(let i = 0; i < s.length; i++){
            if(first[s[i]]){
                first[s[i]] += 1
            }else{
                first[s[i]] = 1
            }
        }
        for(let i = 0; i < t.length; i++){
            if(second[t[i]]){
                second[t[i]] += 1
            }else{
                second[t[i]] = 1
            }
        }
        let isValid = true
        for(let property in first){
            if(first[property] != second[property]){
                isValid = false
            }
        }
                for (let property in first) {
            if (first[property] !== second[property]) {
                return false;
            }
        }
        
        for (let property in second) {
            if (second.hasOwnProperty(property) && first[property] !== second[property]) {
                return false;
            }
        }
        return isValid
};