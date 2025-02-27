function evalRPN(tokens: string[]): number {
    let stack = []
    let operators = "+-/*"
    for(let i = 0; i < tokens.length; i++){
        let token = tokens[i]
        if(!operators.includes(token)){
            stack.push(token)
        }else{
            let second = Number(stack.pop())
            let first = Number(stack.pop())
            let value 
            if(token == "-"){
                value = first - second
            }else if(token == "+"){
                value = first + second
            }else if(token == "*"){
                value = first * second
            }else if(token == "/"){
                let result = first / second
                if(result > 0){
                    value = Math.floor(result)
                }else{
                    value = Math.ceil(result)
                }
            }
            stack.push(value)
        }
    }
    return stack[0]
};