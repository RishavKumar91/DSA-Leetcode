class Solution {
public:
    int maxConsecutiveAnswers(string q, int k) {
        int n = q.size();
        int T = 0 ,F = 0 , i = 0 , j = 0 , ans = 0 ;
        while(j<n){
            if(q[j] == 'T') T++;
            else F++;
            while(min(T,F) > k){
                if(q[i] == 'T') T--;
                else F--;
                i++;
            }
        ans = max(ans , j-i+1);
        j++; 
        }
    return ans;
    }
};