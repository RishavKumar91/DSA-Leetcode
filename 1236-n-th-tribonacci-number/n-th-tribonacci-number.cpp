class Solution {
public:
    int tribonacci(int n) {
        vector<int> t(n+1);
        t[0] = 0;
        if(n==0) return t[0];
        t[1] = 1;
        if(n==1) return t[1];
        t[2] = 1;
        if(n==2) return t[2];
        for(int i =3;i<n+1;i++)
        t[i] = t[i-1]+t[i-2]+t[i-3];
    return t[n];
    }
    
};