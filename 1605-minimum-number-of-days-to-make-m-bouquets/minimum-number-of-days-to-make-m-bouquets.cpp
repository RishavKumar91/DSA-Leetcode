class Solution {
public:
    bool yup(vector<int>& bloomDay , int mi,int m , int k){
        int nowcount = 0;
        int bouqcount = 0;
        for(int i =0;i<bloomDay.size();i++){
            if(bloomDay[i]<=mi) nowcount++;
            else nowcount = 0;
            if(nowcount==k){
                bouqcount++;
                nowcount = 0;
            }
        }
    return bouqcount>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long)m*k>bloomDay.size()) return -1;
        int n = bloomDay.size();
        int first = 1;
        int last = INT_MIN;
        for(int i =0;i<n;i++){
            last = max(last,bloomDay[i]);
        }
        int ans = -1;
        while(first<=last){
            int mi = first + (last-first)/2;
            if(yup(bloomDay,mi,m,k)) {
                ans = mi;
                last = mi-1;
            }
            else first = mi+1;
        }
    return ans;
    }
};