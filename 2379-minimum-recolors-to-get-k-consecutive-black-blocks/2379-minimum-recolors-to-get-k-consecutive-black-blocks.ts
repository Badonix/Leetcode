function minimumRecolors(blocks: string, k: number): number {
    let left = 0;
    let right = left + k - 1;
    let blackCount = 0;
    let whiteCount = 0;
    let min = Infinity
    for(let i = 0; i <= right; i++){
        if(blocks[i] == "W"){
            whiteCount++
        }else{
            blackCount++
        }
    }
    while(right < blocks.length){
        if(whiteCount == 0){
            return 0;
        }
        if(whiteCount < min){
            min = whiteCount
        }
        if(blocks[left] == "W"){
            whiteCount--
        }else{
            blackCount++
        }
        left++
        right++
        if(blocks[right] == "W"){
            whiteCount++
        }else{
            blackCount++
        }
    }
    return min
};