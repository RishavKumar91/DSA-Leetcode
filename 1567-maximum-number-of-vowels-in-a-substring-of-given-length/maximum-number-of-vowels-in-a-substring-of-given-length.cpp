class Solution {
public:
bool isvwl(char ch){
    if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' ) return 1;
    return 0;
}
    int maxVowels(string s, int k) {
        int n = s.size(); int count = 0;
        for(int i =0;i<k;i++){
            if(isvwl(s[i]) ) count++; 
        }
        int maxx = count;
        int i = 0;
        int j = k;
        while(j<n){
            if(isvwl(s[j])) count++;
            if(isvwl(s[i])) count--;
            maxx = max(count,maxx);
            i++;
            j++;
        }
    return maxx;
    }
};