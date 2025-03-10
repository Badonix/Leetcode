function countOfSubstrings(word: string, k: number): number {
    function atLeast(k){
        let vowels = "aeiou"
        let vowelMap = {a:0, e:0, i:0, o:0, u:0}
        let notVowel = 0
        let res = 0
        let left = 0;
        for(let right = 0; right < word.length; right++){
            if(vowels.includes(word[right])){
                vowelMap[word[right]]++
            }else{
                notVowel++
            }
            while(vowelMap.a != 0 && vowelMap.e != 0 &&vowelMap.i != 0 &&vowelMap.o != 0 &&vowelMap.u != 0 && notVowel >= k){
                res += word.length - right
                if(vowels.includes(word[left])){
                    vowelMap[word[left]]--
                }else{
                    notVowel--
                }
                left ++
            }
        }
        return res
    }
    return atLeast(k) - atLeast(k+1)
};