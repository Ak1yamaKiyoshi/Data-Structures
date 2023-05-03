#Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
#You may assume that each input would have exactly one solution, and you may not use the same element twice.
#You can return the answer in any order.
class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        for i in range(len(nums)):
            try: 
                return [i, nums.index(target - nums[i], i+1)]
            except:
                pass
s = Solution()

print(s.twoSum(nums=[3,2,2], target=6))