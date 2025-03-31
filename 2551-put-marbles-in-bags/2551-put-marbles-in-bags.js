/**
 * @param {number[]} weights
 * @param {number} k
 * @return {number}
 */
var putMarbles = function (weights, k) {
    let n = weights.length;
    if (k === 1) return 0;
    let pairSums = [];
    for (let i = 0; i < n - 1; i++) {
        pairSums.push(weights[i] + weights[i + 1]);
    }
    pairSums.sort((a, b) => a - b);
    let minScore = 0, maxScore = 0;
    for (let i = 0; i < k - 1; i++) {
        minScore += pairSums[i];
        maxScore += pairSums[n - 2 - i];
    }
    return maxScore - minScore;
};