class Solution {
public:

 int solve(int i,int j,int n,vector<vector<int>>& triangle, vector<vector<int>>&dp,
 vector<vector<bool>>&visited
 ){

          

         if(i==n-1){
            return triangle[i][j];
        }

      

        if(visited[i][j]){
            return dp[i][j];
        }

        int down=solve(i+1,j,n,triangle,dp,visited);
        int diagonal=solve(i+1,j+1,n,triangle,dp,visited);
        visited[i][j]=true;

        return dp[i][j]=triangle[i][j]+min(down,diagonal);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
           int n=triangle.size();


        vector<vector<int>>dp(n,vector<int>(n,-1));
         vector<vector<bool>> visited(n,vector<bool>(n,false));

        return solve(0,0,n,triangle,dp,visited);
    }
};

