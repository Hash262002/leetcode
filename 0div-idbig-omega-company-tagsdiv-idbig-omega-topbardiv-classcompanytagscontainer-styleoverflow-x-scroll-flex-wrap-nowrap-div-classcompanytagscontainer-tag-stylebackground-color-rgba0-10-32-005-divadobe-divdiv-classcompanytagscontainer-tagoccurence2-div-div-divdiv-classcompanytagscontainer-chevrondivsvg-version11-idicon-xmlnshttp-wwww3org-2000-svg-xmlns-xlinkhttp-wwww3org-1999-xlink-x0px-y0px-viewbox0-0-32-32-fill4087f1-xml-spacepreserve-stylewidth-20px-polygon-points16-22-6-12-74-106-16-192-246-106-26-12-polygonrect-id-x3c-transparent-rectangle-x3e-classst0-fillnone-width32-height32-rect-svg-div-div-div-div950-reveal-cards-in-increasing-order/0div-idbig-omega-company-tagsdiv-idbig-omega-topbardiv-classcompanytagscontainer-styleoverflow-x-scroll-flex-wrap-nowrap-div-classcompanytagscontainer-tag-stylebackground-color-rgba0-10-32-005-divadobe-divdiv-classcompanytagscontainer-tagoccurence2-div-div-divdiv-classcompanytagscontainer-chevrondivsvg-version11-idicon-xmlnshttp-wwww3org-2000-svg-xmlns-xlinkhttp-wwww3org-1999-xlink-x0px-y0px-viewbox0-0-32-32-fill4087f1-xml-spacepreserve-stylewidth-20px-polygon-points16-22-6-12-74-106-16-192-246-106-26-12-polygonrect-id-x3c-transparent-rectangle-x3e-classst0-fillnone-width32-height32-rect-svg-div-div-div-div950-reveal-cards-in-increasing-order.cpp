class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        int n=nums.size();
        if(n==1)return nums;
        queue<int>q;
        q.push(nums[n-1]);
        q.push(nums[n-2]);
        int index=n-3;
        while(index>=0){
            int num=q.front();
            q.pop();
            q.push(num);
            q.push(nums[index]);
            index--;
           
        }
        vector<int>ans;
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};