class Solution {
public:
    int strStr(string haystack, string needle) {
        int big = haystack.size();
        int small = needle.size();
        for(int i =0;i<big-small+1;i++){
            if(needle[0]==haystack[i]){
                int count = 0;
                for(int j =0,k = i;j<small;j++,k++){
                    if(needle[j]==haystack[k]) count++;
                }
                if(count==small) return i;
            }

        }
    return -1;
    }
};