#include<bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int>& heights){
    stack<int> st;
    int result =0;
    heights.push_back(0);
    for(int i=0;i<heights.size();i++){

        while (!st.empty() && heights[st.top()]>heights[i])
        {
            int top = heights[st.top()];
            st.pop();
            int range = st.empty()?-1:st.top();
            result = max(result,(i-range-1)*top);
        }
        st.push(i);
    }
    return result;
}

int main(){

    vector<int> height = {2,1,5,6,2,3};
    cout<<largestRectangleArea(height);
    return 0;
}