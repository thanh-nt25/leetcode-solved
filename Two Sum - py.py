class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        numMap = {}
        n = len(nums)

        # build hash table
        # for i in range(n):
        #     numMap[nums[i]] = i
        # for i, j in numMap.items():
        #     print(i, j) # i la gia tri cua nums, j la index
        for i in range(n):
            complement = target - nums[i]
            if complement in numMap:
                return numMap[complement], i
            numMap[nums[i]] = i
        return []