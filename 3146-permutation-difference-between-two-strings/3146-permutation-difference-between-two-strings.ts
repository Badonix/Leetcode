function findPermutationDifference(s: string, t: string): number {
    let sum = 0;
    for(let i = 0; i < s.length; i++){
        const posInT = t.indexOf(s[i]);
        if (posInT !== -1) {
            sum += Math.abs(i - posInT);
        }
    }
    return sum;
}
