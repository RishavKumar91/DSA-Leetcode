class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        // unordered_set<int> s1;
        // unordered_set<int> s2;
        // for(int i= 0 ; i < n ; i++){
        //     for(int j = i ; j < n ; j++){
        //         s1.insert(nums[i] ^ nums[j]);
        //     }
        // }
        // for(auto & s : s1){
        //     for(int j = 0 ; j < n ; j++){
        //         s2.insert(s ^ nums[j]);
        //     }
        // }
        int maxx = *max_element(nums.begin(),nums.end());
        int m = 1;
        while(m<=maxx) m*=2;



        vector<bool> arr(m,0);
        for(int i= 0 ; i < n ; i++){
            for(int j = i ; j < n ; j++){
                arr[nums[i] ^ nums[j]] = 1;
            }
        }


        vector<bool>  arrr(m,0);
        for(int i = 0 ; i < m ; i++){
            if(arr[i] == 1){
                for(int j = 0 ; j < n ; j++){
                    arrr[i^nums[j]] = 1;
                }
            }
        }
        int ans = 0 ; 
        for(int i = 0 ; i< m; i ++) if(arrr[i] == 1) ans++;

    return ans;
    }
};

