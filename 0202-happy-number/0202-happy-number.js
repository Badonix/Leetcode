/**
 * @param {number} n
 * @return {boolean}
 */
var isHappy = function(n) {
    let seen = []
    let m = n;
    while(!seen.includes(m) && m != 1){
        seen.push(m)
        m = operation(m)
    }
    if(m == 1){
        return true
    }else{
        return false
    }

};

const operation = (n)=>{
    let count = 0
    n.toString().split("").forEach((el)=>{
        count += Number(el) ** 2
    })
    return count
}