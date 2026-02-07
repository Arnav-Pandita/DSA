# Here we use a node variable so that we do not go in the depth of the nodes already visited
# When any node is not NULL, we push it in the stack and move to left, ELSE we will push the node into the stack and move to the right. 

   vector<int> inOrder(Node* root) {
 
        vector<int>inorder;
        stack<Node*>st;
        Node*node=root;
        while(!st.empty() || node){ //If my stack is empty at the root but I have not discovered the right subtree (my node is NOT NULL)
            if(node){
                st.push(node);
                node=node->left;
            }
            else{
                Node*n=st.top();
                st.pop();
                inorder.push_back(n->data);
                node=n->right;
            }
            
        } return inorder;
    }
