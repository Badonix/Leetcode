function simplifyPath(path: string): string {
    let pathArray = path.split("/")
    let stack = []
    for(let i = 0; i < pathArray.length; i++){
        if(pathArray[i] == "." || pathArray[i] == ""){
        }else if(pathArray[i] == ".."){
            stack.pop()
        }else{
            stack.push(pathArray[i])
        }
    }
    return "/" + stack.join("/")
};