function lengthOfLongestSubstring(s: string): number {
    let left = 0;
    let chars = new Set()
    let max = 0
    for(let right = 0; right < s.length; right++){
        while(chars.has(s[right])){
            chars.delete(s[left])
            left++
        }
        chars.add(s[right])
        max = Math.max(max, right - left + 1)
    }
    return max
};
