/**
 * @param {number} start
 * @param {number} finish
 * @param {number} limit
 * @param {string} s
 * @return {number}
 */
function numberOfPowerfulInt(start, finish, limit, suffix) {
    const suffixNum = BigInt(suffix);
    const suffixLen = suffix.length;

    function countValid(num) {
        if (num < suffixNum) return 0n;
        const numStr = num.toString();
        const memo = {};

        function dp(pos, tight) {
            const key = `${pos},${tight}`;
            if (key in memo) return memo[key];
            if (pos === numStr.length) return 1n;

            let res = 0n;
            const suffixStart = numStr.length - suffixLen;

            if (pos >= suffixStart) {
                const suffixIndex = pos - suffixStart;
                const digit = Number(suffix[suffixIndex]);
                if (tight && digit > Number(numStr[pos])) return 0n;
                if (digit <= limit) {
                    res += dp(pos + 1, tight && digit === Number(numStr[pos]));
                }
            } else {
                const maxDigit = tight ? Number(numStr[pos]) : 9;
                for (let d = 0; d <= Math.min(maxDigit, limit); d++) {
                    res += dp(pos + 1, tight && d === Number(numStr[pos]));
                }
            }
            memo[key] = res;
            return res;
        }
        return dp(0, true);
    }
    return Number(countValid(BigInt(finish)) - countValid(BigInt(start - 1)));
}