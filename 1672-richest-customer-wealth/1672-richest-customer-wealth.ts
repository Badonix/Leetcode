function maximumWealth(accounts: number[][]): number {
    let money = []
    accounts.forEach((el)=>{
        let sum = 0;
        el.forEach(money=>sum+=money)
        money.push(sum)
    })
    return Math.max(...money)
};