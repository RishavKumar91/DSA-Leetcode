class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int count_ = 0,now=0,n=moves.size();
        for(int i = 0 ;i<n;i++){
            if(moves[i]=='_') count_++;
            else if(moves[i]=='L') now++;
            else now--;
        }
        return abs(now)+count_;
    }
};