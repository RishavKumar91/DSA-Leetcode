class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        while(n!=1){
            if(s.count(n)) return 0;
            s.insert(n);
            int sum = 0;
            while(n!=0){
                int r = n%10;
                n/=10;
                sum+=(r*r);
            }
            n = sum;
        }
        return 1;
    }
};