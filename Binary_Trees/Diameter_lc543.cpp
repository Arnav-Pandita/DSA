//For every node, consider its left and right and compare with left+right 

    int d(TreeNode*root,int& maxi){ //pass maxi by reference
        if(!root)return 0;
        int lh=d(root->left,maxi);
        int rh=d(root->right,maxi);
        maxi=max(lh+rh,maxi);
        return 1+max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi=-1;
        d(root,maxi);
        return maxi;
    }
