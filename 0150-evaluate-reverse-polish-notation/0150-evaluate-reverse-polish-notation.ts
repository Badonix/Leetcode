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
            if(token == "/"){
                let result = first / second
                if(result > 0){
                    stack.push(Math.floor(result))
                }else{
                    stack.push(Math.ceil(result))
                }
            }else{
                let value 
                if(token == "-"){
                    value = first - second
                }else if(token == "+"){
                    value = first + second
                }else if(token == "*"){
                    value = first * second
                }
                stack.push(value)
            }
        }
    }
    return stack[0]
};