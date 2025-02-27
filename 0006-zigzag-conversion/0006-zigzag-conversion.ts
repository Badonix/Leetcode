function convert(s: string, numRows: number): string {
    if (numRows === 1) return s;
    let arr = [];
    for (let i = 0; i < numRows; i++) {
        arr.push([]);
    }
    let cycle = numRows * 2 - 2;
    for (let i = 0; i < s.length; i++) {
        let mod = i % cycle;
        if (mod < numRows) {
            arr[mod].push(s[i]);
        } else {
            arr[cycle - mod].push(s[i]);
        }
    }
    let str = "";
    arr.forEach(el => {
        str += el.join("");
    });

    return str;
}
