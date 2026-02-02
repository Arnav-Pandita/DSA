//Do it in a single pass, no need to compute nse and pse arrays before..
//For any ele, the one which removes it from the stack is it's nse and it's pse is the ele in the stack below it

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
