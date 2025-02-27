function fourSum(nums: number[], target: number): number[][] {
    nums.sort((a,b)=>a-b)
    let answ = []
    let set = new Set()
    for(let leftMost = 0; leftMost<nums.length - 3; leftMost++){
        for(let left = leftMost + 1; left < nums.length - 2; left++){
            let right = left + 1;
            let rightMost = nums.length - 1;
            while(right < rightMost){
                let currentSum = nums[leftMost] + nums[left] + nums[right] + nums[rightMost]
                if(currentSum == target){
                    let currentKey = nums[leftMost].toString()+nums[left].toString()+nums[right].toString()+nums[rightMost].toString()
                    if(!set.has(currentKey)){
                        answ.push([nums[leftMost], nums[left],nums[right],nums[rightMost]])
                        set.add(currentKey)
                    }
                    right++;
                    rightMost--;
                }else if(currentSum > target){
                    rightMost--;
                }else{
                    right++
                }
            }
        }
    }
    return answ; 
};