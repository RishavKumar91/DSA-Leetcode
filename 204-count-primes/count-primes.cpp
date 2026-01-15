class Solution {
public:
    int countPrimes(int n) {
        if(n<2) return 0;
        vector<int> v(n,0);int count=0;
        v[0]=v[1]=1;
        for(int i=2;i*i<=n;i++){
            if(v[i]==0){
                for(int j = i+i;j<n;j+=i)
                v[j] = 1;
            }
        }
        for(int i =2;i<n;i++){
            if(v[i]==0) count++;
        }
        return count;
    }
};