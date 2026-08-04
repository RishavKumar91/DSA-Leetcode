class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int N = nums.size() , SUM = accumulate(nums.begin() , nums.end() , 0 );
        int n = N/2;
        unordered_map<int,vector<int> > mp1 , mp2;
        for(int mask = 0 ; mask < (1<<n) ; mask++){
            int sum = 0 , count = 0 ;
            for(int i = 0 ; i < n ; i++){
                if(mask & (1<<i)){
                    count++ ; sum+=nums[i];
                }
            }
        mp1[count].push_back(sum);
        }
        for(int mask = 0 ; mask < (1<<n) ; mask++){
            int sum = 0 , count = 0 ;
            for(int i = 0 ; i < n ; i++){
                if(mask & (1<<i)){
                    count++ ; sum+=nums[n+i];
                }
            }
        mp2[count].push_back(sum);
        }

    int ans = INT_MAX ; 
        for(auto &x : mp2) sort(x.second.begin() , x.second.end() ) ; 

        for(auto &m1 : mp1){
            int currcount = m1.first ;
            int fincount = n - currcount ;
            for(auto &mm1 : m1.second){
                int currsubsum = mm1;
                auto &m2  =  mp2[fincount] ;
                    int f = (SUM - 2*currsubsum) / 2 ;
                    int l = lower_bound(m2.begin()  ,  m2.end()  , f) - m2.begin();

                    if(l >=0 && l< mp2[fincount].size()) ans = min(ans ,  abs(SUM - 2*(currsubsum + mp2[fincount][l]))) ; 

                    if(l-1 >=0 && l-1 < mp2[fincount].size()) ans = min(ans ,  abs(SUM - 2*(currsubsum + mp2[fincount][l-1]))) ;
                    if(ans == 0 ) return ans;
            }
        }
    return ans ; 
    }
};













// DO $$
// DECLARE
// AGE INT:=16;
// BEGIN
// 	IF AGE>=18 THEN
// 	RAISE NOTICE 'YOU ARE ELIGIBLE FOR A JOB BECAUSE YOUR AGE IS %',AGE;
// 	ELSE
// 	RAISE NOTICE 'YOU ARE NOT ELIGIBLE FOR A JOB BECAUSE YOUR AGE IS LESS THE 18';
// 	END IF;
		
// END $$;