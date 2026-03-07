class Solution {
public:
    int hammingDistance(int x, int y) {
        string binaryX = bitset<32>(x).to_string();
        string binaryY = bitset<32>(y).to_string();
        int count =0;
        for(int i =0;i<32;i++){
            if(binaryX[i] != binaryY[i]) count++;
        }
    return count;
    }
};