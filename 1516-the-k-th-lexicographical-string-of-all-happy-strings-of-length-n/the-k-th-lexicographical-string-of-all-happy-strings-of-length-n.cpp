class Solution {
public:
void solv(int n , string &ans,string &fill,int & k){
    if(!ans.empty()) return;
    if(fill.size()==n){
        k--;
        if(k==0) ans = fill;
        return ;
    }
    for(char ch = 'a';ch<='c';ch++){
        if(!fill.empty() && fill.back()==ch) continue;
        fill.push_back(ch);
        solv(n,ans,fill,k);
        fill.pop_back();
    }
}
    string getHappyString(int n, int k) {
        // vector<string> ans;
        string ans = "";
        string fill = "";
        solv(n,ans,fill,k);
        // if(k > ans.size()) return "";
        return ans;
    }
};