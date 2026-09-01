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

    TreeNode* f(vector<int> &in,int inlo,int inhi ,vector<int> &post,int postlo,int posthi){
        if(postlo>posthi) return NULL;
        TreeNode* root = new TreeNode(post[posthi]);
        int i = inlo;
        while(i<=inhi){
            if(in[i]==post[posthi]) break;
            i++;
        }
        int leftcount = i-inlo;
        int rightcount = inhi-i;
        root->left = f(in,inlo,i-1,post,postlo,postlo+leftcount-1);
        root->right = f(in, i+1,inhi,post, postlo+leftcount,posthi-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        TreeNode* root = f(inorder,0,n-1,postorder,0,n-1);
        return root;

    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna