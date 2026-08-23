class Solution {
    
    List<List<Integer>> result = new ArrayList<>();
    public List<List<Integer>> subsets(int[] nums) {
         List<Integer> current = new ArrayList<>();

         backtrack(0,nums,current);

         return result;
        
        
    }
    public void backtrack(int index,int []nums,List<Integer> currentIntegers){
        result.add(new ArrayList<>(currentIntegers));

        for(int i=index;i<nums.length;i++){
            currentIntegers.add(nums[i]);

            backtrack(i+1,nums,currentIntegers);

            currentIntegers.remove(currentIntegers.size()-1);


        }
    }
}