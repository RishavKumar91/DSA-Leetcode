class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int minn = INT_MAX;
        int n = arr.size();
        for(int i =0;i<n-1;i++){
            minn = min(minn,arr[i+1]-arr[i]);
        }
        vector<vector<int>> ans;
        vector<int> v(2,-1);
        for(int i =0;i<n-1;i++){
            if(arr[i+1]-arr[i]==minn) {v[0] = arr[i] ; v[1] = arr[i+1] ; ans.push_back(v);}
        }
    return ans;
    }
};