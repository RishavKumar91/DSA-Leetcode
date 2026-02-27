class Solution {
public:
    bool fxnn(vector<int> &citations,int mi ){
        int ans = 0;
        for(int i = 0;i<citations.size();i++){
            if(citations[i]>=mi) ans++;
        }
        return ans>=mi;
    }
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int first = 0;
        int ans = 0;
        int last = 0;
        for(int i =0;i<n;i++){
            last = max(last,citations[i]);
        }
        while(first<=last){
            int mi = first + (last-first)/2;
            if(fxnn(citations,mi)){
                ans = mi;
                first = mi+1;
            }
            else{
                last = mi-1;
            }
        }
    return ans;
    }
};