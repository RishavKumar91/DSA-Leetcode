class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        for(int i = 1 ; i < n ; i++){
            int j  = 0;
            int sz = ans.size();
            string nans = "";
            while(j < sz){
                int count = 1;
                while(j< sz && ans[j] == ans[j+1] ){
                    count++;
                    j++;
                }
                nans  =  nans + to_string(count) + ans[j];
            j++;
            }
            ans = nans;
        }
        return ans;
    }
};