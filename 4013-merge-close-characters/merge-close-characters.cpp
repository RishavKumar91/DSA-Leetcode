class Solution {
public:
    string mergeCharacters(string s, int k) {
        int n = s.size();
        unordered_map<char,int> mp;
        for(int i =0;i<n;i++){
            if(mp.count(s[i])==0) mp[s[i]] = i;
            else if (i-mp[s[i]]  <=k) {
                s = s.substr(0,i) + s.substr(i+1); n--; i--;
            }
            else mp[s[i]] =i;
        }
    return s;
    }
};