class Solution {
public:
    int reverseBits(int n) {
        string nn = bitset<32>(n).to_string(); 
        reverse(nn.begin(),nn.end());
        long long ans = 0;
        long long j = 1;
        for(int i = 31;i>=0;i--){
            if(nn[i]=='1') ans +=j;
            j+=j;
        }
        return ans;
    }
};