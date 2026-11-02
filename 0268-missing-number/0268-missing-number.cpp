class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        int n=nums.size();
        int sum=0;


        for(int num:nums){
            sum+=num;

        }
        int total=n*(n+1)/2;

        return total-sum;
        
    }
};