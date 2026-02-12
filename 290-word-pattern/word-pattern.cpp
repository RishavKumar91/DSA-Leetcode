class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int n = s.size();
        unordered_map<char,string> mp;
        unordered_map<string,char> mprv;
        int j =0;
        for(int i =0;i< pattern.size();i++){
            if(j>=n) return 0;
            string f = "";
            while( j<n && s[j]!=' ' ){
                f.push_back(s[j++]);
            }
            j++;
            if( mp.find(pattern[i])==mp.end() )mp[pattern[i]] = f;
            else if(mp[pattern[i]] != f) return 0;
            if( mprv.find(f)==mprv.end() )mprv[f] = pattern[i];
            else if(mprv[f] != pattern[i]) return 0;
        }
        if (j<n ) return 0;
        return 1;
    }
};