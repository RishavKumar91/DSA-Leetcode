class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int minc = 0,minr = 0,maxr = matrix.size()-1 , maxc = matrix[0].size()-1;
        vector<int> v;
        while(minr<=maxr && minc<=maxc){
            for(int i =minc;i<=maxc;i++){
                v.push_back(matrix[minr][i]);
            }
            minr++;
            if(minr>maxr) break;
            for(int i =minr;i<=maxr;i++){
                v.push_back(matrix[i][maxc]);
            }
            maxc--;
            if(minc>maxc) break;
            for(int i =maxc;i>=minc;i--){
                v.push_back(matrix[maxr][i]);
            }
            maxr--;
            if(minr>maxr) break;
            for(int i =maxr;i>=minr;i--){
                v.push_back(matrix[i][minc]);
            }
            minc++;
            if(minc>maxc) break;
        }
        return v;
    }
};