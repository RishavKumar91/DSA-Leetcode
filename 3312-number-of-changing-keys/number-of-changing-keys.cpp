class Solution {
public:
    int countKeyChanges(string s) {
        int n = s.size(),count=0;
        int a = 'a' -'A';
        for(int i=0;i<n-1;i++){
            int n = s[i] - s[i+1];
            if(n!=a && n!=-a && n!=0) count++;
        }
        return count;
    }
};