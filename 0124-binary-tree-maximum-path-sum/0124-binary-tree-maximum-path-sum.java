/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
     int maxSum = Integer.MIN_VALUE;
    public int maxPathSum(TreeNode root) {
        maxgain(root);
        return maxSum;
        
    }
    private int maxgain(TreeNode node){

    if(node==null){
        return 0;
    }
    int left=Math.max(0,maxgain(node.left));
    int right=Math.max(0,maxgain(node.right));

    int currentPath=node.val+left+right;

     maxSum=Math.max(currentPath,maxSum);

    return node.val+ Math.max(left,right);
    }
}