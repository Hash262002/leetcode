class Solution {
public:
    int longestIdealString(string s, int k) {
        int n=s.size();
        if(n==1)return 1;
        map<char,vector<int>>mp;
        for(int i=0;i<n;i++){
            mp[s[i]].push_back(i);
        }
        vector<int>temp(n,1);
        int ans=INT_MIN;
        for(int i=1;i<n;i++){
            char a=s[i];
            while(a>='a' && s[i]-a<=k){
                if(mp.find(a)!=mp.end()){
                    int index=lower_bound(mp[a].begin(),mp[a].end(),i)-mp[a].begin();
                    if(index>0 && mp[a][index-1]<i){
                        temp[i]=max(temp[i],1+temp[mp[a][index-1]]);
                    }
                    // cout<<a<<endl;
                }
                
                a--;
            }
            a=s[i];
            while(a<='z' && a-s[i]<=k){
                if(mp.find(a)!=mp.end()){
                    int index=lower_bound(mp[a].begin(),mp[a].end(),i)-mp[a].begin();
                    if(index>0 && mp[a][index-1]<i){
                        temp[i]=max(temp[i],1+temp[mp[a][index-1]]);
                    }
                    // cout<<a<<endl;
                }
                
                a++;
            }
            
            ans=max(ans,temp[i]);
        }
        return ans;
    }
};