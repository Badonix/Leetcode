/**
 * @param {number[]} nums
 * @param {number} minK
 * @param {number} maxK
 * @return {number}
 */
var countSubarrays = function(nums, minK, maxK) {
    let count = 0;
    const n = nums.length;
    let minKIndex = -1;
    let maxKIndex = -1;
    let leftBound = -1;
    for (let i = 0; i < n; i++) {
        if (nums[i] < minK || nums[i] > maxK) {
            leftBound = i;
            minKIndex = -1;
            maxKIndex = -1;
            continue;
        }
        if (nums[i] === minK) {
            minKIndex = i;
        }
        if (nums[i] === maxK) {
            maxKIndex = i;
        }
        if (minKIndex !== -1 && maxKIndex !== -1) {
            count += Math.min(minKIndex, maxKIndex) - leftBound;
        }
    }
    return count;
};