class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        index1=0
        index2=0
        n1=len(version1)
        n2=len(version2)
        while(index1<n1 or index2<n2):
            num1=0
            num2=0
            while(index1<n1 and version1[index1]!='.'):
                num1=num1*10+int(version1[index1])
                index1+=1
            while(index2<n2 and version2[index2]!='.'):
                num2=num2*10+int(version2[index2])
                index2+=1
            if(num1>num2):
                return 1
            elif(num2>num1):
                return -1
            if(index1<n1 and version1[index1]=='.'):
                index1+=1
            if(index2<n2 and version2[index2]=='.'):
                index2+=1
        return 0