class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();

        vector<int>dp=triangle[n-1];
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<=i;j++){
                int same=triangle[i][j]+dp[j];
                int next=triangle[i][j]+dp[j+1];

                dp[j]=min(same,next);
            }
        }
        return dp[0];
        
    }
};