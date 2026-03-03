class Solution {
public:
    char findKthBit(int n, int k) {
        if(n==1) return '0';
        int lngth = 1;
        for(int i = 1;i<n;i++){
            lngth = (lngth*2) + 1;
        }
        int mi = (lngth/2 )+1;
        if(k<mi){
            return findKthBit(n-1,k);
        }
        else if(k == mi) {
            return '1';
        }
        else{
            char ch =  findKthBit(n-1,lngth-k+1);
            return (ch == '1' )? '0' : '1';
        }
    }
};