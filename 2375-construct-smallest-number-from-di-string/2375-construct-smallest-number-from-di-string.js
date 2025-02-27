/**
 * @param {string} pattern
 * @return {string}
 */
var smallestNumber = function(pattern) {
    let stack = [];
    let res = "";
    for (let i = 0; i <= pattern.length; i++) {
        stack.push(i + 1);
        if (i === pattern.length || pattern[i] === "I") {
            while (stack.length) {
                res += stack.pop();
            }
        }
    }
    return res;
};
