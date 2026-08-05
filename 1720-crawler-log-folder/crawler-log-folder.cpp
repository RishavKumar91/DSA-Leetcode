class Solution {
public:
    int minOperations(vector<string>& logs) {
        int curr =  0 ;
        for(string &s : logs){
            if(s == "../") curr = max(0,curr-1);
            else if(s == "./") continue;
            else  curr++;
        }
        return curr - 0;
    }
};