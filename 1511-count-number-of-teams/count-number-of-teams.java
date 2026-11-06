class Solution {
    public int numTeams(int[] rating) {
        int ans = 0 , n = rating.length ;
        for(int i = 1 ; i < n-1 ; i++){
            int currval = rating[i];
            int lftmin = 0 , lftmor = 0 , rgtmin = 0 , rgtmor = 0 ;
            for(int j = 0 ; j < i ; j++){
                if(rating[j] < currval) lftmin++;
                if(rating[j] > currval) lftmor++;
            }
            for(int j = i+1 ; j < n ; j++){
                if(rating[j] < currval) rgtmin++;
                if(rating[j] > currval) rgtmor++;
            }
            ans += rgtmor*lftmin ;
            ans += rgtmin*lftmor ;
        }
    return ans ;    
    }
}