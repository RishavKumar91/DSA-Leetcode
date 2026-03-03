class Solution {
public:
    char findKthBit(int n, int k) {
        if(n==1) return '0';
        string ans = "0";
        for(int i =2;i<=n;i++){
        string r = "";
        for(int j  =  ans.size()-1;j>=0;j--){
            if(ans[j]=='1') r.push_back('0');
            else r.push_back('1');
        }
        ans = ans + "1" + r;
    }
    return ans[k-1];
    }
};