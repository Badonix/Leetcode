/**
 * @param {string} word
 * @return {string}
 */
var compressedString = function(word) {
    let answ = "";
    let i = 0;

    while (i < word.length) {
        let count = 1;
        while (i + 1 < word.length && word[i] === word[i + 1]) {
            if (count === 9) break;
            count++;
            i++;
        }
        answ += count + word[i];
        i++;
    }

    return answ;
};
