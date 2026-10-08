class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
         int n=nums.size();
        int low =0;
        int high=n-1;
        while(low<high){
            int mid=low+(high-low)/2;

            if(mid%2==1){
                mid--;
            }

            if(nums[low]==nums[low+1]){
                low=low+2;
            }else{
                high=mid;
            }
        }
        return nums[low];
    }
};