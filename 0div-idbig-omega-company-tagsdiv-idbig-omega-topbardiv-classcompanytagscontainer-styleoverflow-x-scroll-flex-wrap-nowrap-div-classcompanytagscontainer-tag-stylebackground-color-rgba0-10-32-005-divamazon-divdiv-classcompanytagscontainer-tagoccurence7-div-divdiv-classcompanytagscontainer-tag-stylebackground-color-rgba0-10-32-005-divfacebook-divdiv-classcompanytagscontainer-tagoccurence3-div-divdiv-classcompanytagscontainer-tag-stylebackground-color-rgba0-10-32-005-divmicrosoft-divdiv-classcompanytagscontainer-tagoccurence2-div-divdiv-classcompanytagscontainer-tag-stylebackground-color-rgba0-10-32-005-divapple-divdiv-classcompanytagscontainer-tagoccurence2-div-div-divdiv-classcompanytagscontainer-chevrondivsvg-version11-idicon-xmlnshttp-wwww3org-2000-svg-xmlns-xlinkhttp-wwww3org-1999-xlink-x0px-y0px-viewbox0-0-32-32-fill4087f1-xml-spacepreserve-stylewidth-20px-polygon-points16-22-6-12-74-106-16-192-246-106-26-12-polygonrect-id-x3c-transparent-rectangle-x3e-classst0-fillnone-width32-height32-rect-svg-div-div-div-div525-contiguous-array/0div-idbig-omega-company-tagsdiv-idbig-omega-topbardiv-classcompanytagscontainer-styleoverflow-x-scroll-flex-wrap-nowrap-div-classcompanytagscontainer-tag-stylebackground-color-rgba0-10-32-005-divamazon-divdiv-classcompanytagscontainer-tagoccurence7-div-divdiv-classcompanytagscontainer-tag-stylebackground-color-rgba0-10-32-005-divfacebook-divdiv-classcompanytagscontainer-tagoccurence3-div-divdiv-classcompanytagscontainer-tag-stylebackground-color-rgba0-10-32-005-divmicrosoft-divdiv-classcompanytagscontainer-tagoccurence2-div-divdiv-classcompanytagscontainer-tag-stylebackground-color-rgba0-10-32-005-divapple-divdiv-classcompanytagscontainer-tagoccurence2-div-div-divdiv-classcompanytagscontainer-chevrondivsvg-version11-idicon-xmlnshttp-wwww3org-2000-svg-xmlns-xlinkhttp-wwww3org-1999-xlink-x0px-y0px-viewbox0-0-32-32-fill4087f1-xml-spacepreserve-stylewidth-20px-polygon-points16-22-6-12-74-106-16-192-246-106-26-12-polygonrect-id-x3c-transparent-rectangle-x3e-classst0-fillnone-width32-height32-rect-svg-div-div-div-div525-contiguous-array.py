class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        n=len(nums)
        dict1={}
        counter=0
        ans=0
        for i in range(n):
            if(nums[i]==1):
                counter+=1
            else:
                counter-=1
            if(counter==0):
                ans=max(ans,i+1)
            elif(counter in dict1.keys()):
                ans=max(ans,(i-dict1[counter]))
            else:
                dict1[counter]=i
        return ans