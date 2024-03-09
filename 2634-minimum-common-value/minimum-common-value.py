class Solution:
    def getCommon(self, nums1: List[int], nums2: List[int]) -> int:
        dct = {}
        for i in nums1:
            dct[i] = 1


        for i in nums2:
            if(dct.get(i) == 1):
                return i

        return -1