class Solution {
    public :
    int minimumPushes(string word) {
        vector<int> arr(26);
        for(char &ch : word){
            arr[ch-'a']++;
        }
        sort(arr.begin(),arr.end() , greater<int>() ) ; 
        int ans = 0 ;
        int count = 0;
        for(int i = 0 ; i<26 ; i++ ){
            if(arr[i] ==0 ) break;
            if(i<8 ) ans += arr[i];
            else if(i<16) ans += 2*arr[i];
            else if(i<24) ans += 3 * arr[i];
            else ans += arr[i]*4;
        }
    return ans ;
    }
};