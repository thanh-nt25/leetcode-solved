class Solution1:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        numMap = {}
        n = len(nums)

        for i in range(n):
            complement = target - nums[i]
            print(complement)
            if complement in numMap:
                return numMap[complement], i
            numMap[nums[i]] = i
            # print(numMap)
        return []