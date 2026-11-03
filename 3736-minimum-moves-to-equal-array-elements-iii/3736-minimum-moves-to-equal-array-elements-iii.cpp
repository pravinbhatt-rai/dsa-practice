class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum=0;
        int maxnum=0;
        for( int n:nums){
          maxnum=  max(n,maxnum);
            sum+=n;
        }

        return maxnum*nums.size()-sum;
        
    }
};