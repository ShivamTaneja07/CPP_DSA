class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int>mp;
        int n=s.size();
        int ans=0;
        int j=0;
        for(int i=0;i<s.size();i++)
        {
            while(j<s.size() && mp.size()<3){
                mp[s[j]]++;
                j++;
            }
            if(mp.size()<3)break;
            ans+=n-j+1;
            mp[s[i]]--;
            if(mp[s[i]]==0)mp.erase(s[i]);
        }
        return ans;
    }
};