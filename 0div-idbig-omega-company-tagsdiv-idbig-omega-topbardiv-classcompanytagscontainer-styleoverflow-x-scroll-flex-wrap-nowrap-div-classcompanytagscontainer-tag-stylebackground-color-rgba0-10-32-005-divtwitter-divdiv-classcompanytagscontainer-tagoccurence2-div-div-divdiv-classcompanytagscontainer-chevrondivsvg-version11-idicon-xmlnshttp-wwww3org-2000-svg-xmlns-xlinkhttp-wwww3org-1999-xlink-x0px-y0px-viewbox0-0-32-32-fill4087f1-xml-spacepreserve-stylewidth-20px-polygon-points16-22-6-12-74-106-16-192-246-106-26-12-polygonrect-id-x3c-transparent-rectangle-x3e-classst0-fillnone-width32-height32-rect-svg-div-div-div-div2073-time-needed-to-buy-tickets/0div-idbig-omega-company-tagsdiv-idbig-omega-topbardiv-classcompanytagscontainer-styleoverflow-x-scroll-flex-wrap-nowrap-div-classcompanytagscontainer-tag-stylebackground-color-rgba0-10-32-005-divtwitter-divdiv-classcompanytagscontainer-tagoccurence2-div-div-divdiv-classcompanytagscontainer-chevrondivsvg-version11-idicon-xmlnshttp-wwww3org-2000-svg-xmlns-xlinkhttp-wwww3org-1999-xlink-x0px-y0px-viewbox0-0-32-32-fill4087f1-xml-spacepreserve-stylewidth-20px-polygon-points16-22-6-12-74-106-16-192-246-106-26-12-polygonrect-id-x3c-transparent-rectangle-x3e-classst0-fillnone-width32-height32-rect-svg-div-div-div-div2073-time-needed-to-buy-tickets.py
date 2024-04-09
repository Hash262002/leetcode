class Solution:
    def timeRequiredToBuy(self, tickets: List[int], k: int) -> int:
        num=tickets[k]
        n=len(tickets)
        ans=0
        for i in range(k+1):
            ans+=min(tickets[i],num)
        for i in range(k+1,n):
            ans+=min(tickets[i],num-1)
        return ans