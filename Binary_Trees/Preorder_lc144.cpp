//Iterative Preorder traversal using stack 
//Here first push right, and then left in the stack, so that left part can get seen first..

   vector<int> preorderTraversal(TreeNode* root) {
        if(root==NULL)return {};
        vector<int>preorder;
        stack<TreeNode*>st;
        st.push(root);
        while(!st.empty()){
            TreeNode*n=st.top();
            st.pop();
            preorder.push_back(n->val);
            if(n->right)st.push(n->right);
            if(n->left)st.push(n->left);
        }
        return preorder;
    }
