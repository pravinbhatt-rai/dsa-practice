class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<int>dp=matrix[0];

        for(int i=1;i<n;i++){
            vector<int> curr(n);
            for(int j=0;j<n;j++){
                int up=dp[j];

                int left=(j>0)?dp[j-1]:INT_MAX;
                int right=(j<n-1)?dp[j+1]:INT_MAX;

                curr[j]=matrix[i][j]+min(up,min(right,left));

            }
            dp=curr;
        }

        return *min_element(dp.begin(),dp.end());
        
    }
};