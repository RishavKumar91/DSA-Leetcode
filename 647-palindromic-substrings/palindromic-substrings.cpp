class Solution {
public:
int count;
void solv(string &s,int i , int j){
    if(i<0 || j>=s.size()) return ;
    if(i>j) return ;
    if(s[i]==s[j]) {count++; solv(s,i-1,j+1);}
}
    int countSubstrings(string s) {
        count = 0;
        int n = s.size();
        for(int i = 0;i<n;i++){
            solv(s,i,i+1);
            solv(s,i,i);
        }
    return count;
    }
};