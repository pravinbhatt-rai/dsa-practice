class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int leftsum=0;
        int total=0;

        for(int x:nums){
            total+=x;
        }

        for(int i=0;i<nums.size();i++){
            int rightsum=total-leftsum-nums[i];
            if(leftsum==rightsum){
                return i;
            }
            leftsum+=nums[i];
        }
     

        return -1;
        
    }
};