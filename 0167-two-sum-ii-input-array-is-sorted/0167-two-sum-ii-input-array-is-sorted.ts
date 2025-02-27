function twoSum(numbers: number[], target: number): number[] {
    let left = 0
    let right = numbers.length - 1
    let answer = []
    while(left <= right){
        let newTarget = target - numbers[left]
        if(numbers[right] == newTarget){
            answer.push(left + 1)
            answer.push(right + 1)
            break
        }else if(numbers[right] > newTarget){
            right--
        }else{
            left++
        }
    }
    return answer
};