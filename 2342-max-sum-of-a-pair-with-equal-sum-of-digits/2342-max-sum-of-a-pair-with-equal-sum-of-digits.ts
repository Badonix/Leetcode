function maximumSum(nums: number[]): number {
    let map = {}
    nums.forEach((el)=>{
        let str = el.toString()
        let sum = 0;
        for(let i = 0; i < str.length; i++){
            sum += parseInt(str[i])
        }
        if(map[sum] == undefined){
            map[sum] = [el]
        }else{
            map[sum].push(el)
        }
    })

    let max = -1;
    for(let key in map){
        let arr = map[key]
        if(arr.length != 1){
            let [first, second] = findTwoLargest(arr)
            if(first+second > max){
                max = first + second
            }
        }
    }
    return max;
};

function findTwoLargest(arr) {
    let first = -Infinity, second = -Infinity;

    for (let num of arr) {
        if (num > first) {
            second = first;
            first = num;
        } else if (num > second) {
            second = num;
        }
    }

    return [first, second];
}