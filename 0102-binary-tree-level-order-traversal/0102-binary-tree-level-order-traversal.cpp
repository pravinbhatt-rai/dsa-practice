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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;

        if(root==nullptr){
            return result;
        }

        queue<TreeNode*> q; // bfs like level wise search perform gareko

        q.push(root);

        while(!q.empty()){
            int size=q.size();

            vector<int> levels;

            for(int i=0;i<size;i++){
                TreeNode* Node =q.front();
                q.pop(); // first iteration node wmptry bnayo 

                levels.push_back(Node->val);

                if(Node->left!=nullptr){
                    q.push(Node->left);  // left value q ma haleko

                }

                if(Node->right!=nullptr){
                    q.push(Node->right);
                }
            }

            result.push_back(levels);
        }
        return result;
        
    }
};