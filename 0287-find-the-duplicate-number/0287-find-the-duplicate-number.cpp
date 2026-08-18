class Solution {
public:

// treat it liake a linked list
    int findDuplicate(vector<int>& nums) {
       int slow=nums[0];
       int fast= nums[0];

       do{
        slow=nums[slow];
        fast=nums[nums[fast]];

       }while(slow!=fast); // cycle detect gareko

       slow=nums[0]; // fast ma assign greko

       while(slow!=fast){
        fast=nums[fast];
        slow=nums[slow]; // intersection of slow and fast to bring kun chi repating eala cha
       }

       return slow;
        
    }
};