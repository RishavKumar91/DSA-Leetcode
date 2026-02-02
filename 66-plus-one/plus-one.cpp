class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        digits[n-1] +=1;
        int i = n-1;
      //  if(digits[n-1]>=10) digits.push_back(0);
        while(i>=1 && digits[i]>=10){
            digits[i]= digits[i]%10;
            digits[i-1]+=1;
            i--;
        }
        if(digits[0] >= 10) {
            digits[0] = 0;
            digits.insert(digits.begin(), 1);
        }
    return digits;
    }
};