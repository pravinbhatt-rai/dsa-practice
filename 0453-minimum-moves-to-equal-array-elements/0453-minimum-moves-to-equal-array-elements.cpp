class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);

        int min=*min_element(nums.begin(),nums.end());

        return sum-(int)nums.size()*min;


        
    }
};