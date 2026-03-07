class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        int j = 0 , i = 0;
        int f1 = 0 , f2 = 0;
        int ans = INT_MAX;
        while(j < 2*n){
            char e1 = j%2==0 ? '0' : '1';
            char e2 = j%2==0 ? '1' : '0';

            if(s[j%n] != e1) f1++;
            if(s[j%n] != e2) f2++;
            if(j-i+1==n){
                if(j-i+1 == n) ans = min(ans,min(f1,f2));
                e1 = i%2==0 ? '0' : '1';
                e2 = i%2==0 ? '1' : '0';
                if(s[i%n] != e1) f1--;
                if(s[i%n] != e2) f2--;
            i++;
            }
        j++;
        }
    return ans;
    }
};