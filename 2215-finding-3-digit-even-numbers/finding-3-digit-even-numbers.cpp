class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();
        vector<int> v;
        unordered_map<int,int> mp;
        for(int i =0;i<n;i++){
            mp[digits[i]]++;
        }
        for(int i =100;i<1000;i+=2){
            int a = i%10;
            if(mp[a]>0) {
                mp[a]--;
                int b = i/10; b = b%10;
                if(mp[b]>0) {
                    mp[b] -- ;
                    int c = i/100;
                    if(mp[c]>0)
                        v.push_back(a+b*10+c*100);
                mp[b]++;
                }
            mp[a]++;
            }
        }
    return v;
    }
};