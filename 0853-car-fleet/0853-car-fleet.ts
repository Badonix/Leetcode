function carFleet(target: number, position: number[], speed: number[]): number {
    let pairs = position.map((el, i)=>{
        return {position:el, speed:speed[i]}
    })
    pairs = pairs.sort((a, b)=>{
        return b.position - a.position
    })
    let stack = []
    for (let i = 0; i < pairs.length; i++) {
        let time = (target - pairs[i].position) / pairs[i].speed;
        
        if (stack.length === 0 || time > stack[stack.length - 1]) {
            stack.push(time);
        }
    }
    return stack.length
};