class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        n=len(nums)
        for i in range(n):
            ind=abs(nums[i])
            if nums[ind]<0:
                return ind
            nums[ind]=-nums[ind]
            
        return -1