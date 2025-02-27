function numJewelsInStones(jewels: string, stones: string): number {
    let hashmap = {}
    for(let i = 0; i < jewels.length; i++){
        hashmap[jewels[i]] = 1
    }
    let count = 0
    for(let i = 0; i < stones.length; i++){
        if(hashmap[stones[i]] == 1){
            count++
        }
    }
    return count
};
