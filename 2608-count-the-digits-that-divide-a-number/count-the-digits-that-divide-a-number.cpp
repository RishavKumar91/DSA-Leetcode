class Solution {
public:
    int countDigits(int num) {
        int n =num;
        int count = 0;
        while(n!=0){
            int r = n%10;
            if(num%r==0 ) count++;
            n=n/10;
        }
        return count;
    }
};