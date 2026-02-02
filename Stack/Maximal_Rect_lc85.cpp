//Here pass every row in the largestRectangleArea function after adding the upper 1's in it.

     int largestRectangleArea(vector<int>& heights) {
      stack<int>st;int pse,nse,val;int area=0;
      for(int i=0;i<heights.size();i++){
        while(!st.empty() && heights[i]<=heights[st.top()]){
            val=heights[st.top()];
            nse=i;
            st.pop();
            pse=st.empty()?-1:st.top();
            area=max(area,val*(nse-pse-1));
        }
        st.push(i);
      
      } while(!st.empty()){
        val=heights[st.top()];
        nse=int(heights.size());
        st.pop();
        pse=st.empty()?-1:st.top();
        area=max(area,val*(nse-pse-1));
      }
        return area;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> heights(m, 0);
        int area = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            heights[j] = (matrix[i][j]=='1')? heights[j]+1:0;
        }
        area = max(area,largestRectangleArea(heights));
    }
    return area;
    }
