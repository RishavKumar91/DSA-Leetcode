
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int lft = 0, right = n - 1;
        int top = 0, bottom = n - 1;
        while (lft < right) {
            for (int i = 0; i < right - lft; i++) {
                int temp = matrix[top][lft + i];
                matrix[top][lft + i] = matrix[bottom - i][lft];
                matrix[bottom - i][lft] = matrix[bottom][right - i];
                matrix[bottom][right - i] = matrix[top + i][right];
                matrix[top + i][right] = temp;
            }
            lft++;right--; top++;bottom--;
        }
    }
};
