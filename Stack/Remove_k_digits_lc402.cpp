//Remove the element from the stack only when we find a number smaller than that..
//We can do this entorely witht the string without using the stack

 string removeKdigits(string num, int k) {
        stack<char>st;
        string ans;
        if(num.size()==k)return "0";
        for(int i=0;i<num.size();i++){
            while(!st.empty() && st.top()>num[i] && k){
                st.pop();
                k--;
                }
                st.push(num[i]);
        }
        while(k){
            st.pop();
            k--;
        }
        while(!st.empty() ){
            ans.push_back(st.top());
            st.pop();
        }
        while(!ans.empty() && ans.back()=='0'){
            ans.pop_back();
        }
        if(ans.empty())return "0";
        reverse(ans.begin(),ans.end());
        return ans;

    }
