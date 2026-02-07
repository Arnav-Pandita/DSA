# Similar to inorder, we just have to keep a rn for right node as first I have to go to the right.
#just remeber to mark the right node visited so that we do not go inside again.

    vector<int> postOrder(Node* root) {
        // code here
        vector<int>post;
        stack<Node*>st;
        Node* node=root;
        Node* lastnode=NULL;
        while(!st.empty() || node){
            if(node){
                st.push(node);
                node=node->left;
            }
            else{
                Node*rn=st.top()->right;
                if(!rn){
                    Node*n=st.top();
                    st.pop();
                    post.push_back(n->data);
                    lastnode=n;
                }
                else {
                    if(lastnode==rn){
                        post.push_back(st.top()->data);  //we are pushing the top as we know that we already have gone to the right
                        lastnode=st.top();   //mark it the lastnode for its parent
                        st.pop();
                    }
                    else node=rn;  //Push the right only when we know that it has not been processed
                }
            }
        } return post;
    }
