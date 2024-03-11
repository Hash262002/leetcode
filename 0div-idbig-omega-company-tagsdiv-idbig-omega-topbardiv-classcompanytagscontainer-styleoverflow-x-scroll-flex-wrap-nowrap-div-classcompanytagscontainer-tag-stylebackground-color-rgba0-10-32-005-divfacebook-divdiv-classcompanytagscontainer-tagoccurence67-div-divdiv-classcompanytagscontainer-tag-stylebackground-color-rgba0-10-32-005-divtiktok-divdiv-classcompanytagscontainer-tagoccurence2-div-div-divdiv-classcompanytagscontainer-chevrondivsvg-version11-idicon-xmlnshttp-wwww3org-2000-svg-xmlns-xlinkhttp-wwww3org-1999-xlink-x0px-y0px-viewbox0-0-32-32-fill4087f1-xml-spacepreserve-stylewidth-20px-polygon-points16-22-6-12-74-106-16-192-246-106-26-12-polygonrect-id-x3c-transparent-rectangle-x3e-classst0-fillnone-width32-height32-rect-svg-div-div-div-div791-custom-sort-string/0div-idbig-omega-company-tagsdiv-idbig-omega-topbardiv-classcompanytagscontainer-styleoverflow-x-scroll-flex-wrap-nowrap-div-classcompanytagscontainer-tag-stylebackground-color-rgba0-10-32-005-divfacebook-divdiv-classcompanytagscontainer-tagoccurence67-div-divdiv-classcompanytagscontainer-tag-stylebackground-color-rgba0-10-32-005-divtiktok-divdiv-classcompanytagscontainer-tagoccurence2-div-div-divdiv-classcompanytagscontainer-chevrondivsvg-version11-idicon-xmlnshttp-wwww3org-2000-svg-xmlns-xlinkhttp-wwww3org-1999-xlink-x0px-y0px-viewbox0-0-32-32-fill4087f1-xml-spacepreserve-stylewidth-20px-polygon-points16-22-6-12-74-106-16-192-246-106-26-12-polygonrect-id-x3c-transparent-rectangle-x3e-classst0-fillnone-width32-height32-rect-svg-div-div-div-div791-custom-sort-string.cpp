class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int>mp;
        int n=s.size();
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        string ans="";
        for(int i=0;i<order.size();i++){
            while(mp[order[i]]!=0){
                ans+=order[i];
                mp[order[i]]--;
            }
        }
        for(auto it : mp)
        {
            while(it.second!=0){
                ans+=it.first;
                it.second-=1;
            }
        }
        return ans;
    }
};