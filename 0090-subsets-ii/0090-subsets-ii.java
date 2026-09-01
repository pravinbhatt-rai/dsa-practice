class Solution {
    List<List<Integer>> result;
    List<Integer>current;
    public List<List<Integer>> subsetsWithDup(int[] nums) {

        result=new ArrayList<>();
        Arrays.sort(nums);
        backtrack(nums,0,new ArrayList<>(),result);
        return result;
    }

    void backtrack(int []nums,int start, List<Integer> current,List<List<Integer>>result){
        // basecse 
        result.add(new ArrayList<>(current));

        for(int i=start;i<nums.length;i++){
            if(i>start&&nums[i]==nums[i-1]) continue;

            current.add(nums[i]);

            backtrack(nums,i+1,current,result);

            current.remove(current.size()-1);

        }
    }
}