function countAndSay(n: number): string {
    let count = n;
    let current = "1";
    for(let i = 1; i < n; i++){
        current = rle(current)
    }
    return current
};
function rle(n:string):string{
    let str = ""
    for(let i = 0; i < n.length; i++){
        let count = 1;
        while(n[i+1] == n[i]){
            count++
            i++
        }
        str += count + n[i]
    }
    return str
}