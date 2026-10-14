class Solution {
public:
    int longestCommonSubsequence(string t1, string t2) {
        if(t1.size()<t2.size()){
            swap(t1,t2);
        }

        int n=t1.size();
        int m=t2.size();

        vector<int>dp(m+1,0);

        for(int i=1;i<=n;i++){
            int dg=0;
            for(int j=1;j<=m;j++){
                int t=dp[j];

                if(t1[i-1]==t2[j-1]){
                    dp[j]=dg+1;
                }else{
                    dp[j]=max(dp[j],dp[j-1]);
                }
            dg=t;
            }

        }

        return dp[m];
        
    }
};