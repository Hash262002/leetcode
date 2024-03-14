class Solution:
    def numSubarraysWithSum(self, nums: List[int], goal: int) -> int:
        n=len(nums)
        sum1=0
        ans=0
        dict1={}
        for i in nums:
            sum1+=i
            if(sum1==goal):
                ans+=1
            if((sum1-goal) in dict1.keys()):
                ans+=dict1[sum1-goal]
            if(sum1 in dict1.keys()):
                dict1[sum1]+=1
            else:
                dict1[sum1]=1
        return ans