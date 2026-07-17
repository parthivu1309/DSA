class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        string ans;

        for (char it : s) {
            if (it == '(') {
                if (!st.empty()) ans += it;
                st.push(it);//first check then push
            }
            else { // ')'
                st.pop();
                if (!st.empty()) ans += it;//first pop then check
            }
        }
        return ans;
    }
};