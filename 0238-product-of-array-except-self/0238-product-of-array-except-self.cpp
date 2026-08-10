class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prefix=1;
        int postfix=1;
        vector<int> result(nums.size(),1);

        for(int i=0;i<nums.size();i++){
            result[i]=prefix;
            prefix=prefix * nums[i];
        }

        for(int i=nums.size()-1;i>=0;i--){
            result[i]=postfix*result[i];
            postfix=postfix*nums[i];
        }

        return result;

        
    }
};