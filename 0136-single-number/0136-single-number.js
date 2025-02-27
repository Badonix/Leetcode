/**
 * @param {number[]} nums
 * @return {number}
 */
var singleNumber = function(nums) {
    let seen = []
    let sum = 0;
    nums.forEach((el)=>{
        if(seen.includes(el)){
            sum -= el
        }else{
            seen.push(el)
            sum += el
        }
    })
    return sum
};