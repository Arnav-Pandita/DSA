// We create a function which finds the diff bw leftht and rightht . If not balanced, it returns -1, else it returns the ht to it's parent

    int ht(TreeNode* root){
    if(root==NULL)return 0;
    
    int lh=ht(root->left);
    if(lh==-1)return -1;

    int rh=ht(root->right);
    if(rh==-1)return -1;

    if(abs(lh-rh)>1)return -1;
    return 1+max(lh,rh);
    }
    bool isBalanced(TreeNode* root) {
       if(ht(root)==-1)return false;
       return true;
    }
