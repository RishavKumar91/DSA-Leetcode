class Solution {
public:
    bool isPalindrome(long long x) {

        if (x < 0) return 0;
        if(x%10==0 && x!=0 ) return 0;
        int sum = 0;
        while (sum < x) {
            int r = x % 10;
            sum = sum * 10 + r;
            x = x / 10;
        }
        return (x == sum || x == sum / 10);
    }
};
