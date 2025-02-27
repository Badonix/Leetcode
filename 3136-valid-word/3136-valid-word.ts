function isValid(word: string): boolean {
    if(word.length < 3){
        return false
    }
    let vowel = "aeiou"
    let consonants = "bcdfghjklmnpqrstvwxyz"
    let numbers = "0123456789"
    let hasConsonant = false
    let hasVowel = false
    let containsOther = false
    word.split("").forEach((el)=>{
        if(vowel.includes(el.toLowerCase())){
            hasVowel = true
        }else if(consonants.includes(el.toLowerCase())){
            hasConsonant = true
        }else if(!numbers.includes(el)){
            containsOther = true
        }
    })
    if(hasConsonant && hasVowel && !containsOther){
        return true
    }else{
        return false
    }
};