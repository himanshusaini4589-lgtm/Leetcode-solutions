class Solution {
public:
    TreeNode* Tree(vector<int>&pre,int prelo , int prehi, vector<int>&in , int inlo , int inhi){
        if(prelo>prehi ) return NULL;
        TreeNode* root = new TreeNode(pre[prelo]);
        if(prelo == prehi ) return root;
        int i = inlo;
        while(i<=inhi){
            if(in[i]==pre[prelo]) break;
            i++;
        }
        int leftcount = i-inlo;
        int rightcount = inhi-i;
        root->left = Tree(pre,prelo+1,prelo+leftcount,in,inlo,i-1);
        root->right = Tree(pre,prelo+leftcount+1,prehi,in,i+1,inhi);
        return root;
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int n = pre.size();
        TreeNode* r = Tree(pre,0,n-1,in,0,n-1);
        return r;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna