class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        int ans = 0 ;
        bool st[1000] = {0};
        // unordered_set<int> st;
        for(int i = 0 ; i < n ; i++){
            if(!digits[i]  ) continue;
            for(int j = 0 ; j < n ; j++){
                if( i == j ) continue;
                for(int k = 0 ; k < n ; k++){
                    if( j==k || i==k || digits[k]&1 ) continue;
                    if(!st[digits[i]*100 + digits[j]*10 + digits[k]]){
                        ans++;
                        st[digits[i]*100 + digits[j]*10 + digits[k]] = 1;
                    }
                }
            }
        }
    return ans;
    }
};