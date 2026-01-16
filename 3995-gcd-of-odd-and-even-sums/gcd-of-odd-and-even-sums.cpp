class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int o =0, e=0,c=0;
        for(int i =0;i<2*n;i++){
            c++;
            if(c%2==0) e+=c;
            else o+=c;
        }
        int ans;
        for(int i = min(o,e);i>=1;i--){
            if(o%i==0 && e%i==0) {ans = i; break;}
        }
        return ans;
    }
};