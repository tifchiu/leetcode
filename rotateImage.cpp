class Solution {
public:

    void transpose(vector<vector<int>> & matrix) {
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = i; j < matrix.size(); j++) {
                swap(matrix[j][i], matrix[i][j]);
            }
        }
    }
    void reverse(vector<vector<int>> & matrix) {
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix.size()/2; j++) {
                swap(matrix[i][j], matrix[i][matrix.size()-1-j]);
            }
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        reverse(matrix);
    }
};