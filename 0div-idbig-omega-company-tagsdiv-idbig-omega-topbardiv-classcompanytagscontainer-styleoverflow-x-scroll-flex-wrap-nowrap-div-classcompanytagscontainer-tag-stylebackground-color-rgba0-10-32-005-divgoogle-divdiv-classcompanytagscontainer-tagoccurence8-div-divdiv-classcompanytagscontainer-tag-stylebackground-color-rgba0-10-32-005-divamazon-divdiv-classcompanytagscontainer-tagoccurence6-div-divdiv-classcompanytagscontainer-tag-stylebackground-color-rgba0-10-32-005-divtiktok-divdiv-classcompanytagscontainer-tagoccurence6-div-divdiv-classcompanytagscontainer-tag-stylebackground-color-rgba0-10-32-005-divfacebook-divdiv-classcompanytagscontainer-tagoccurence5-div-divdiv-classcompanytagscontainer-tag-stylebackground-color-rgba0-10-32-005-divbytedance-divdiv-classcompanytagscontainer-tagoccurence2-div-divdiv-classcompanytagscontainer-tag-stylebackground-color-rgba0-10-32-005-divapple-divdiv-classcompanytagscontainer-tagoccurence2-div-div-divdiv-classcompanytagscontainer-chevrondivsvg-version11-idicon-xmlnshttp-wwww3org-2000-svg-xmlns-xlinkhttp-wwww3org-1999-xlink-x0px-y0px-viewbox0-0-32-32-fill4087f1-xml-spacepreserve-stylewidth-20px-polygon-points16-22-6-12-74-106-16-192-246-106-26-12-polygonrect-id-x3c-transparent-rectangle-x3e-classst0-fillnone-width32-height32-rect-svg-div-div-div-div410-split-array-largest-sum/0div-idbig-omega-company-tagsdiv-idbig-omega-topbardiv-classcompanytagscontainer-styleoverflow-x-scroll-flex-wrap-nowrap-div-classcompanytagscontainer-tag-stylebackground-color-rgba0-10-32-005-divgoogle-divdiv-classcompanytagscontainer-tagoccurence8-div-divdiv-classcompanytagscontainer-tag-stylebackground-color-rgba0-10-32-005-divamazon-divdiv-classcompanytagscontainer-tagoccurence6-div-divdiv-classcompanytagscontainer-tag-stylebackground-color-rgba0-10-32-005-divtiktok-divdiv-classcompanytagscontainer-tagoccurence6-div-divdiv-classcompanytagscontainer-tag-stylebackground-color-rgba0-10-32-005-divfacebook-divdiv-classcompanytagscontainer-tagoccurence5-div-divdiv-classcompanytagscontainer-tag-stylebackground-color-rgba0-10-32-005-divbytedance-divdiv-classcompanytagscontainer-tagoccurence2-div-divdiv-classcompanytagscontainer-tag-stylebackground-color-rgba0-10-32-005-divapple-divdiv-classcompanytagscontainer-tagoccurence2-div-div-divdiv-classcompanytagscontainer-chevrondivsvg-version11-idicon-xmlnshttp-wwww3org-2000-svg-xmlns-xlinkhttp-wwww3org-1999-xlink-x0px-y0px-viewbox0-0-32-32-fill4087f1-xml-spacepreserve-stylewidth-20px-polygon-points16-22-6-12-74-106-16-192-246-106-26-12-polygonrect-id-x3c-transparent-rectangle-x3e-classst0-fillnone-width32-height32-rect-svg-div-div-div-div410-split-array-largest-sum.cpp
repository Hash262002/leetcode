class Solution {
public:
    bool isPossible(vector<int>nums,int k,int target){
        int temp=1;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]<=target){
                sum+=nums[i];
            }
            else{
                sum=nums[i];
                temp++;
            }
        }
        return temp<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int maxi=INT_MIN;
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
            sum+=nums[i];
        }
        int low=maxi,high=sum;
        int mid=(low+high)/2;
        int ans=high;
        while(low<=high){
            mid=(low+high)/2;
            if(isPossible(nums,k,mid)){
                ans=min(ans,mid);
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};