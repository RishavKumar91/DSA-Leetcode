class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        string s="";
        string f = strs[0];
        string last = strs[strs.size()-1];
        for(int i =0;i<f.size();i++){

            if(f[i]==last[i]) s.push_back(f[i]);
            else return s;
        }
        return s;
    }
};