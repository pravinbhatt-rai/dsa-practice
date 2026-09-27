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
     int maxSum=Integer.MIN_VALUE;
    public int maxPathSum(TreeNode root) {
        getPath(root);
        return maxSum;
       


        
    }

    private int getPath(TreeNode node){
        if(node==null){
            return 0;
        }

        int left=Math.max(0,getPath(node.left));
        int right =Math.max(0,getPath(node.right));

        int currentPath=node.val+left+right;

        maxSum=Math.max(maxSum,currentPath);

        return node.val+Math.max(left,right);

    }
}