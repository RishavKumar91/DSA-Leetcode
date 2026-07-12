class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        set<int> st;
        for(int i = 0 ; i < n ; i++){
            st.insert(arr[i]);
        }
        int i = 1 ; 
        unordered_map<int,int> mp;
        for(auto &x : st){
            mp[x] = i++;
        }
        for(int i = 0 ; i < n ; i++){
            arr[i] = mp[arr[i]];
        }
    return arr;
    }
};