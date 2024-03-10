class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:

        if(len(nums1) == 0 or len(nums2) == 0):
            return []
        sorted(nums1)
        sorted(nums2)

        st = set()
        for i in nums1:
            if i in nums2:
                st.add(i)

        lst = []
        for i in st:
            lst.append(i)

        return list(st)