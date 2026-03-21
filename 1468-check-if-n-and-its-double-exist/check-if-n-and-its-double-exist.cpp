class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> s;
        for(int i =0 ;i<arr.size();i++){
            if(arr[i]%2==1 && s.count(2*arr[i])) return 1;
            if(arr[i]%2==0 && (s.count(2* arr[i]) || s.count(arr[i]/2))) return 1;
            s.insert(arr[i]);
        }
    return 0;
    }
};