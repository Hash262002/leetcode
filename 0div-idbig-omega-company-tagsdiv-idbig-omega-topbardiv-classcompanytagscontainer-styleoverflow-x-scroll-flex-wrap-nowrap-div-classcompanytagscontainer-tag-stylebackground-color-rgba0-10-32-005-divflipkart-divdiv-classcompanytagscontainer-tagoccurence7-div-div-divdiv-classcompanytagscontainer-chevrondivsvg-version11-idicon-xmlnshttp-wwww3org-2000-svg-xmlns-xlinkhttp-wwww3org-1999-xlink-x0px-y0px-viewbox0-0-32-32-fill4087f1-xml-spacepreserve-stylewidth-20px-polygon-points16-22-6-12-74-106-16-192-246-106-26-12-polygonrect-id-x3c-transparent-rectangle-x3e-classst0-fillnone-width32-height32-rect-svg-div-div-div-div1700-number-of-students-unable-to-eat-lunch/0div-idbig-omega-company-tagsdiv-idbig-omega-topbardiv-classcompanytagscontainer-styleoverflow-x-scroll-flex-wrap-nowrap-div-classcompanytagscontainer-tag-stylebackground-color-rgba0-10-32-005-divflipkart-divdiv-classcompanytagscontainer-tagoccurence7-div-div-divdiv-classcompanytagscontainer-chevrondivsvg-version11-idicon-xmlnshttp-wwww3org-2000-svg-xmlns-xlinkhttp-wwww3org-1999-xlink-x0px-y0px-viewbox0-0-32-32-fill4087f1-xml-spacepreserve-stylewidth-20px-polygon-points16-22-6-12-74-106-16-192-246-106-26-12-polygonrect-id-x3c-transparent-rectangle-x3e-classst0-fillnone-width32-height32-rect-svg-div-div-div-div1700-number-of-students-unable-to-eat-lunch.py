class Solution:
    def countStudents(self, students: List[int], sandwiches: List[int]) -> int:
        n=len(students)
        count=[0]*2
        for i in range(n):
            if students[i]==1:
                count[1]+=1
            else:
                count[0]+=1
        index=0
        while(index<n and count[sandwiches[index]]!=0):
            count[sandwiches[index]]-=1
            index+=1
        return n-index
        
          
             
            