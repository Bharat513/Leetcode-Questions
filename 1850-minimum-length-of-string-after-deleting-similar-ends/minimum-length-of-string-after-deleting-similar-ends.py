class Solution:
    def minimumLength(self, s: str) -> int:
        maxLen = len(s)
        if(maxLen <= 1):
            return maxLen
        left = 0
        right = len(s) - 1
        while right > left:
            pre = s[left]
            while (right >= left and pre == s[left]):
                left += 1
            
            if (s[right] != pre):
                return maxLen

            while(right >= left and pre == s[right]):
                right -= 1

            maxLen = min(maxLen, right - left + 1)

        return maxLen

        