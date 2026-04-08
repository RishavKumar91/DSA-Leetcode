class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        int n = words.size();
        for(string i : words){
            unordered_map<char,char> mp;
            unordered_map<char,char> mp1;
            bool flag = 1;
            for(int j = 0;j<pattern.size();j++){
                if((mp.count(i[j]) && pattern[j]!=mp[i[j]]) || (  mp1.count(pattern[j]) &&mp1[pattern[j]] != i[j] )) {
                    flag = 0;
                    break;
                }
                else {
                    mp[i[j]] = pattern[j];
                    mp1[pattern[j]] = i[j];
                }
            }
            if(flag == 1) ans.push_back(i);
        }
    return ans;
    }
};