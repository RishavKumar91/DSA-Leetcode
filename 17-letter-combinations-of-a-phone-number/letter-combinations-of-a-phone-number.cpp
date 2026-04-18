class Solution {
public:
unordered_map<int,string> mp;
void solv(string &digits,vector<string> &ans , int ix,string &now){
    if(ix==digits.size()){
        ans.push_back(now);
        return ;
    }
    string curr = mp[digits[ix] - '0'];
    for(int i = 0 ;i < curr.size();i++){
        now.push_back(curr[i]);
        solv(digits,ans,ix+1,now);
        now.pop_back();
    }
}
    vector<string> letterCombinations(string digits) {
        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";
        string now = "";
        vector<string> ans;

        solv(digits,ans,0,now);
        return ans;
    }
};