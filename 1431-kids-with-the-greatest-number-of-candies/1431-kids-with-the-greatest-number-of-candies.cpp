class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n=candies.size();
        int greatest=0;
        vector<bool> ans(n);
        for(int candy:candies){
            greatest=max(greatest,candy);
        }

        for(int i=0;i<n;i++){
            if(candies[i]+extraCandies>=greatest){
                ans[i]=true;
            }else{
                ans[i]=false;
            }
        }

        return ans;
        
    }
};