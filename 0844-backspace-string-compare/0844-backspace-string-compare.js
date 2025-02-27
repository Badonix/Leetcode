/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var backspaceCompare = function(s, t) {
    let firstStack = []
    let secondStack = []
    for(let i =0; i < s.length; i++){
        if(s[i] == "#"){
            firstStack.pop()
        }else{
            firstStack.push(s[i])
        }
    }
    for(let i =0; i <t.length; i++){
        if(t[i] == "#"){
            secondStack.pop()
        }else{
            secondStack.push(t[i])
        }
    }
    return firstStack.join("") == secondStack.join("")
}