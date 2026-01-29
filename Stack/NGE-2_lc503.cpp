 vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>st;
       int n=nums.size();
        vector<int>nge(n);
        st.push(INT_MIN);
        for(int i=(2*n)-1;i>=0;i--){
            int x=nums[i%n];
            while(!st.empty() && st.top()<=x)st.pop();
            nge[i%n]=st.empty()?-1:st.top(); //Or simply do only when i<n
            st.push(x);
        }
        return nge;
    }
