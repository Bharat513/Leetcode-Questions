class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        size = len(nums)
        for idx1 in range(size):
            for idx2 in range(size):
                if idx1 != idx2 and nums[idx1] + nums[idx2] == target:
                    return [idx1, idx2]

        