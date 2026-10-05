class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        
        for(char it : s) {
            if(it == '(') {
                // Use -1 to represent the '(' character
                st.push(-1);
            } 
            else {
                int add = 0;
                // Keep popping and adding until we hit our dummy '('
                while(st.top() != -1) {
                    add += st.top();
                    st.pop();
                }
                
                // Pop the '(' itself
                st.pop();
                
                // If add is 0, it was an empty "()", so push 1
                if(add == 0) {
                    st.push(1);
                } 
                // Otherwise, multiply the inner score by 2
                else {
                    st.push(2 * add);
                }
            }
        }
        
        // Sum up whatever is left on the stack
        int ans = 0;
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        
        return ans;
    }
};