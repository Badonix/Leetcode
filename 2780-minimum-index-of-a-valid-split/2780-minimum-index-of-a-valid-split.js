/**
 * @param {number[]} nums
 * @return {number}
 */
var minimumIndex = function (nums) {
    let freqMap = {}
    nums.forEach((el) => {
        if (freqMap[el] == undefined) {
            freqMap[el] = 1;
        } else {
            freqMap[el]++;
        }
    })
    let x = -1;
    let maxCount = 0;
    for (let key in freqMap) {
        if (freqMap[key] > maxCount) {
            x = Number(key)
            maxCount = freqMap[key]
        }
    }
    let leftCount = 0;
    let rightCount = maxCount;
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] == x) {
            leftCount++
            rightCount--
        }
        if (leftCount * 2 > (i + 1) && rightCount * 2 > (nums.length - i - 1)) {
            return i
        }
    }
    return -1;
};