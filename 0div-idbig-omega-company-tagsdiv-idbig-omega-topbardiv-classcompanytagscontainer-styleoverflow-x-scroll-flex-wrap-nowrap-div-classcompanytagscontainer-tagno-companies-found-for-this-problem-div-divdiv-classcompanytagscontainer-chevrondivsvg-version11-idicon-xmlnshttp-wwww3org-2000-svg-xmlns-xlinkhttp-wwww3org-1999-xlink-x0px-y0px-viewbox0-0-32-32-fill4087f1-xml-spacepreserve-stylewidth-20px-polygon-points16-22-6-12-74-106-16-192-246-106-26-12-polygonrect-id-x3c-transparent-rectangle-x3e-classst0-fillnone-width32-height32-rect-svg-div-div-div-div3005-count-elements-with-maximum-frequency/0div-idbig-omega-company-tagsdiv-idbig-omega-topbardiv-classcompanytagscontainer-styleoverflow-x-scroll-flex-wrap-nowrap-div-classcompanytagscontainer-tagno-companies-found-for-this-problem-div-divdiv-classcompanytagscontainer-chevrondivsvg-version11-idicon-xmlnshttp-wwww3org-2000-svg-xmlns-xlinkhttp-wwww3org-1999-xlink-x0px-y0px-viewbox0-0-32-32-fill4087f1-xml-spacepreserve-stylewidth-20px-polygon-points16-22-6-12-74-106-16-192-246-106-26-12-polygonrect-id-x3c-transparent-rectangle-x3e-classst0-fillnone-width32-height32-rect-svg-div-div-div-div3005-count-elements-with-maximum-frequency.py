class Solution:
    def maxFrequencyElements(self, nums: List[int]) -> int:
        dict1={}
        freq=0
        for num in nums:
            if num in dict1.keys():
                dict1[num]+=1
            else:
                dict1[num]=1
            freq=max(freq,dict1[num])
        ans=0
        for i in nums:
            if dict1[i]==freq:
                ans+=1
        return ans