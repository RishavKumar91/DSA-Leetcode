class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int m = word1.size() , n = word2.size(),count = 0;
        vector<int> ans;
        vector<int> suff(m,-1);
        int i = m-1 , j = n-1 ;
        while(i>=0){
            if(j >=0 && word1[i] == word2[j]){
                count++; j--;
            }
            suff[i] = count;
        i--;
        }
        // if(suff[0] < n-1) return {};
        i = 0 , j = 0; 
        bool canchange = 1 ;
        while(i<m && j<n){
            if(word1[i] == word2[j]){
                ans.push_back(i);
                j++;
            }
            else if(canchange == 1 && i+1 < m && suff[i+1] >= n-(j+1) ){
                ans.push_back(i);
                j++;
                canchange = 0;
            }
        i++;
        }

    if (ans.size() != n) return {};
    return ans;
    }
};
