function reverseWords(s: string): string {
    return s.split(" ").map(el=>el.split("").reverse().join("")).join(" ")
};