class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        nums.sort()
        count_k = 0
        greater = 0
        last_greater = None
        smaller_exist = False

        for num in nums:
            if num == k:
                count_k += 1
            elif num > k:
                if num != last_greater:
                    last_greater = num
                    greater += 1
            else:
                smaller_exist = True

        if count_k == len(nums):
            return 0
        if smaller_exist:
            return -1
        return greater