class Solution:
    def pivotInteger(self, n: int) -> int:
        for i in range(n+1):
            if(int(i*(i+1)/2)==int(int(n*(n+1)/2)-int(i*(i-1)/2))):
                return i
        return -1
    