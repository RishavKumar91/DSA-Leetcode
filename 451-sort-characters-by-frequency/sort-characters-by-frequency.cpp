class Solution {
public:
    string frequencySort(string s) {
        map<char,int  > mp;
        for(char &ch : s){
            mp[ch]++;
        }
        vector<pair<int,char >> mpp;
        for(auto &m : mp){
            mpp.push_back({m.second,m.first});
        }
        sort(mpp.begin(),mpp.end(),greater<pair<int,char>>());
        string ans = "";
        for(auto &m : mpp){
            ans = ans + string(m.first,m.second);
        }
    return ans;
    }
};