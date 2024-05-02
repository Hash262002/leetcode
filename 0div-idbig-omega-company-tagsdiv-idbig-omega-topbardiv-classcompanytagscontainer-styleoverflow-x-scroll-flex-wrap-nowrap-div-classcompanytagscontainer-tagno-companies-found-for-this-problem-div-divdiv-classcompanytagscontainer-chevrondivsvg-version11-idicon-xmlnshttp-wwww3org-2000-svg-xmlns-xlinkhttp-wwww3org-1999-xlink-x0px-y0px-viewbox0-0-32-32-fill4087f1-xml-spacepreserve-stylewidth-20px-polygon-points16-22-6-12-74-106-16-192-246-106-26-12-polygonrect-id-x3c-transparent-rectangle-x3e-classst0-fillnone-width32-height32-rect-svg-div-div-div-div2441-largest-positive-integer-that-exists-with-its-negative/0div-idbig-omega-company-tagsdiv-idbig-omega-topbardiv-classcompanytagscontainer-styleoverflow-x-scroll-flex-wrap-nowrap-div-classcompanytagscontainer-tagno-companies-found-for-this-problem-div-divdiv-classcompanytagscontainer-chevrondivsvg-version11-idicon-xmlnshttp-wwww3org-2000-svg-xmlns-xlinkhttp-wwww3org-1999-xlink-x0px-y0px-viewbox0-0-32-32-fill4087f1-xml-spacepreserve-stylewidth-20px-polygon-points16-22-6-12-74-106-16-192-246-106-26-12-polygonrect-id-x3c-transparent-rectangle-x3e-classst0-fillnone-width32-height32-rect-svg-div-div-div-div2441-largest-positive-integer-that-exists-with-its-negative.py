class Solution:
    def findMaxK(self, nums: List[int]) -> int:
        nums.sort()
        i=0
        j=len(nums)-1
        while(i<j):
            if(nums[i]>0):
                break
            if(nums[j]>-nums[i]):
                j-=1
            elif(nums[j]<-nums[i]):
                i+=1
            elif(nums[j]==-nums[i]):
                return  nums[j]
        return -1