class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxar=0;

        for(int i=0;i<=heights.size();i++){

            int curr=(i==heights.size())?0:heights[i];
            while(!st.empty()&&curr<heights[st.top()]){
                int height=heights[st.top()];
                st.pop();

                int width;

                if(st.empty()){
                    width=i;
                }else{
                    width=i-st.top()-1;
                }
                int maxarea=(height*width);

                maxar=max(maxarea,maxar);
            }
            st.push(i);
        }

        return maxar;
        
    }
};