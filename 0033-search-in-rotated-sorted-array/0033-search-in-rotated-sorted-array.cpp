class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;

        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target) return mid;
            if(nums[low]<=nums[mid]){    // Left half is sorted
            if(nums[low]<=target&&target<nums[mid]){ // Target is inside left sorted half
                high=mid-1;

            }
            else{
                low=mid+1;
            }
            }else{
                if(nums[mid]<target&&target<=nums[high]){ // Target is inside right sorted half
                    low=mid+1;
                }else{
                    high=mid-1;
                }
            }
        }
        return -1;


        
    }
};