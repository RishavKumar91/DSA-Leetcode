class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int ans = 0;
        for(string st : operations){
            if(st[1] == '+') ans++;
            else ans--;
        }
    return ans;
    }
};