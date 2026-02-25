class Solution {
public:
    static bool cmp(int a1,int a2){
        if(__builtin_popcount(a1) == __builtin_popcount(a2))
            return a1 <a2;
        return    __builtin_popcount(a1) <  __builtin_popcount(a2);
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),cmp);
        return arr;
    }
};