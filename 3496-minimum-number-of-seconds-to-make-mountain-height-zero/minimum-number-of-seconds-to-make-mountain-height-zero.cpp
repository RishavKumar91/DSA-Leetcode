class Solution {
public:
    // bool chck(long long mi ,long long MH, vector<int> &WT){
    //     // long long count = 0;
    //     for(int i = 0;i<WT.size();i++){
    //         long long now = 0;
    //         for(long long j = 1;j<=mi;j++){
    //             if(now+WT[i]*j >mi) break; 
    //             now+=WT[i]*j;
    //             MH--;
    //         }
    //     }
    // return MH <= 0 ? 1 : 0;
    // }
    bool chck(long long t, int MH, vector<int>& WT){
        long long ht = 0;
        for(int w : WT){
            long long k = (sqrt(1 + (8.0 * t) / w) - 1) / 2;
            ht += k;
            if(ht >= MH)
                return true;
        }

        return false;
    }
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        int maxt = 0;
       for(int x : workerTimes)
            maxt = max(maxt, x);
        long long start = 0;
        long long last = 1LL * mountainHeight * maxt * (mountainHeight + 1) / 2;
        long long ans ;
        while(start<=last){
            long long mi = start + (last-start)/2;
            if(chck(mi,mountainHeight,workerTimes)){
                ans = mi;
                last = mi-1;
            }
            else {
                start = mi+1;
            }
        }
    return ans;

    }
};