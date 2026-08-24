class Solution {
    List<List<Integer>> result=new ArrayList<>();

    void backtrack(int[]nums,List<Integer> current,boolean[]used){
        if(current.size()==nums.length){
            result.add(new ArrayList<>(current));
            return;
        }
        for(int i=0;i<nums.length;i++){
            if (used[i]) continue;
        current.add(nums[i]);
        used[i]=true;
        backtrack(nums,current,used);
        current.remove(current.size()-1);
        used[i]=false;
        }
    }

    public List<List<Integer>> permute(int[] nums) {
        List<Integer> current=new ArrayList<>();
        boolean [] used=new boolean[nums.length];

        backtrack(nums,current,used);
        return result;
    }
}