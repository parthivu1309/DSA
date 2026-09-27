class Solution {
public:
    string& reverse(string& s, int start, int end){
        while(start <= end){
            swap(s[start++], s[end--]);
        }
        return s;
    }
    string reverseParentheses(string s) {
        stack<int>st;
        string ans = "";

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(') {
                st.push(ans.size());
            }
            else if(s[i] == ')'){
                int start = st.top();
                st.pop();
                reverse(ans, start, ans.size() - 1);
            }
            else{
                ans += s[i];
            }
        }
        return ans;
    }
};