class Solution {
public:
    int maxConsecutiveAnswers(string q, int k) {
        int n = q.size();
        int changeval = 0 , i = 0 , j = 0 , ans = 0 ;
        while(j<n){
            if(q[j] == 'T'){
                changeval++;
            }
            while(changeval > k){
                if(q[i] == 'T') changeval--;
                i++;
            }
        ans = max(ans , j-i+1);
        j++; 
        }
        i = 0 , j  = 0 , changeval = 0 ;
        while(j<n){
            if(q[j] == 'F'){
                changeval++;
            }
            while(changeval > k){
                if(q[i] == 'F') changeval--;
                i++;
            }
        ans = max(ans , j-i+1);
        j++; 
        }
    return ans;
    }
};