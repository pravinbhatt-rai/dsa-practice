class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // transponse nikal 

        int n=matrix.size();

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        for(int r=0;r<n;r++){
            reverse(matrix[r].begin(),matrix[r].end());
        }
        
    }
};