class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int sum=0;
        for(int num=0;num<nums.size();num++){
            sum+=nums[num];
            nums[num]=sum;

        }
        return nums;
        
    }
};