//We broke this problem from  Generating the subarrays to Finding the Contribution of each element when it becomes Min for a subarray.
//We found contributions by using NSE and PSEE
//PSEE has more guarantee than NSEE one
//Here the stack and the ans array store *indices* 
  vector<int> NSE(vector<int>&arr){
        vector<int>ans(arr.size(),0);stack<int>st;
        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i])st.pop();
            ans[i]=st.empty()?arr.size():st.top();
            st.push(i);
        }return ans;
    }
    vector<int>PSEE(vector<int>&arr){  //Keeping Equal Handles the case of duplicates
        vector<int>ans(arr.size(),0);stack<int>st;
        for(int i=0;i<arr.size();i++){
            while(!st.empty() && arr[st.top()]>arr[i])st.pop();
            ans[i]=st.empty()?-1:st.top();
            st.push(i);
        }return ans;
    }
    int sumSubarrayMins(vector<int>& arr) {
        vector<int>nge,psee;
        int left,right;int sum=0;const int Mod=1e9+7;
        nge=NSE(arr);
          psee=PSEE(arr);
        for(int i=0;i<arr.size();i++){
        left=i-psee[i];
        right=nge[i]-i;
        long long temp=(1LL*left*right)%Mod;
        temp=(temp*arr[i])%Mod;
        sum=(sum+temp)%Mod;
        }
        return sum;
    }
