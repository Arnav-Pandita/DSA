//for every node we consider its VAL+LEFT+RIGHT, and pass VAL+MAXBRANCH to the upper node..
//Make the leftsum or rightsum 0 if they are -ve, so that our answer does not reduce.


    int path(TreeNode* root, int& maxi){
        if(root==NULL)return 0;
        int lsum=max(0,path(root->left,maxi));
        int rsum=max(0,path(root->right,maxi));
        int sum=lsum+rsum+root->val;
        maxi=max(maxi,sum);
        int max_branch=max(lsum,rsum);
        return max_branch+root->val;
    }
    int maxPathSum(TreeNode* root) {
        int maxi=-2000;
        path(root,maxi);
        return maxi;
    }
