class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st; 
        int maxArea = 0;
        int n = heights.size();

        for (int i = 0; i <= n; ++i) {
            int currHeight = (i < n) ? heights[i] : 0;

            while (!st.empty() && heights[st.top()] > currHeight) {
                int topIdx = st.top();
                st.pop();

                int height = heights[topIdx];
                int leftIdx = st.empty() ? -1 : st.top();
                int width = i - leftIdx - 1;

                maxArea = max(maxArea, height * width);
            }

            st.push(i);
        }

        return maxArea;
    }
};
