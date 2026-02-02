//Here use a deque and store indices in the decreasing order of their values.

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>swm;
        for(int i=0;i<nums.size();i++){
            if(!dq.empty() && dq.front()<=i-k)dq.pop_front();   //Checks the window size before any operation
            while(!dq.empty() && nums[dq.back()]<=nums[i])dq.pop_back();
            dq.push_back(i);
            if(i>=k-1)swm.push_back(nums[dq.front()]);
        }
        return swm;
    }
