//Make separate functions for left, leaf and right 
//the left and right functions can be iterative also, in which we can use a pointer to move.

    bool isLeaf(Node*root){
        return (!root->left && !root->right);
    }
    void left(Node*root,vector<int>&ans){
        if(root==NULL || isLeaf(root)) return ;
        ans.push_back(root->data);
        if(root->left)left(root->left,ans);
        else left(root->right,ans);
    }
    void leaf(Node*root,vector<int>&ans){
        if(root==NULL)return;
        if(isLeaf(root))ans.push_back(root->data);
        leaf(root->left,ans);
        leaf(root->right,ans);
    }
    void right(Node*root,vector<int>&ans){
        if(root==NULL || isLeaf(root)) return;
        if(root->right)right(root->right,ans);
        else right(root->left,ans);
        ans.push_back(root->data);
    }
    
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int>ans;
        if(!root)return ans;
        ans.push_back(root->data);
        if(isLeaf(root)) return ans;
        if(root->left)left(root->left,ans);
        leaf(root,ans);
        if(root->right)right(root->right,ans);
        return ans;
        
    }
