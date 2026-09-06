class Solution {
    public int[] productExceptSelf(int[] nums) {
        int postfix=1;
        int prefix=1;
        int [] result =new int[nums.length];

        for(int i=0;i<nums.length;i++){
            result[i]=prefix;
            prefix*=nums[i];

        }

        for(int i=nums.length-1;i>=0;i--){
            result[i]*=postfix;
            postfix*=nums[i];
        }

        return result;
        
    }
}