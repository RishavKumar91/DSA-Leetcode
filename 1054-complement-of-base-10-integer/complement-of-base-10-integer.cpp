class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) return 1;
        int ans = 0;
        int countr = 0;
        while(n!=0){
            int r = n%2;
            ans += !r* (int)pow(2,countr);
            countr++;
            n = n/2;
        }
    return ans;
    }
};