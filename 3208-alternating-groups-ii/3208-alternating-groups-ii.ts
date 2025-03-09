function numberOfAlternatingGroups(colors: number[], k: number): number {
   let left = 0;
   let count = 0;
   for(let i = 0; i < k-1; i++){
    colors.push(colors[i])
   }
    for (let right = 0; right < colors.length; right++) {
        if (right > 0 && colors[right] === colors[right - 1]) {
            left = right;  
        }
        if (right - left + 1 >= k) {
            count++;  
        }
    }
   return count
};