class Solution {
    List<List<Integer>> result=new ArrayList<>();
   

    void backtrack(int index,int[] candidates, int target,List<Integer> current){
        // base case
        if(target==0){
            result.add(new ArrayList<>(current));
        }

        for(int i=index;i<candidates.length;i++){
            if(candidates[i]>target){
                continue;
            }

            current.add(candidates[i]); // auta choose gar

            backtrack(i, candidates,target-candidates[i],current);// explore

            current.remove(current.size()-1); // undo
        }
    }
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
 List<Integer> current=new ArrayList<>();
 backtrack(0,candidates,target,current);
 return result;
        
    }
}