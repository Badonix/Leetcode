/**
 * @param {string} s
 * @param {number} k
 * @return {number}
 */
var characterReplacement = function(s, k) {
    let l = 0;
    let count = {}
    let answ = 0
    let maxFrequency = 0
    for(let i = 0; i < s.length; i++){
        if(count[s[i]] == undefined){
            count[s[i]] = 1
        }else{
            count[s[i]]++
        }
        maxFrequency = Math.max(maxFrequency, count[s[i]])
        while((i-l+1) - maxFrequency > k){
            count[s[l]]--
            l++
        }
        answ = Math.max(answ, i-l+1)
    }
    return answ

};
