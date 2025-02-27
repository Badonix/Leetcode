function threeSumClosest(nums: number[], target: number): number {
    let answ = nums[0] + nums[1] + nums[2];
    let distance = Math.abs(target - answ);
    nums.sort((a, b) => a - b);
    
    for (let left = 0; left < nums.length - 2; left++) {
        let middle = left + 1;
        let right = nums.length - 1;

        while (middle < right) {
            let sum = nums[left] + nums[middle] + nums[right];
            let currDistance = Math.abs(target - sum);

            if (currDistance < distance) {
                distance = currDistance;
                answ = sum;
            }

            if (sum > target) {
                right--;
            } else if (sum < target) {
                middle++;
            } else {
                return target;
            }
        }
    }
    
    return answ;
}
