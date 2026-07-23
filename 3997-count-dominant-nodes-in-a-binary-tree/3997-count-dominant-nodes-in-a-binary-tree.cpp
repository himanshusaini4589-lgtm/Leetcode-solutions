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
    int count = 0 ;
    int f(TreeNode* root){
        if(root==NULL) return INT_MIN;
        if(root->left==NULL && root->right== NULL){
            count++;
            return root->val;
        }
        int maxVal = max(f(root->left),f(root->right));
        if(root->val>=maxVal){
            count++;
            return root->val;
        } 
        
        return maxVal;
    }
    int countDominantNodes(TreeNode* root) {
        int r = f(root);
        return count;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna