/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

TreeNode* build(vector<int>&preorder, vector<int>&inorder, int &preindex, int instart,int inend){
    if(instart>inend){
        return nullptr;
    }

    int rootvalue= preorder[preindex]; // root value lai uthako
    preindex++;

    TreeNode * root=new TreeNode(rootvalue);

    int inindex=instart;

    while(inindex<=inend&&inorder[inindex]!=rootvalue){
        inindex++;
    }

    root->left=build(preorder,inorder,preindex,instart,inindex-1);

    root->right=build(preorder,inorder,preindex,inindex+1,inend);

    return root;
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        int preindex=0;

        return build(preorder,inorder,preindex, 0,inorder.size()-1);
    }
};