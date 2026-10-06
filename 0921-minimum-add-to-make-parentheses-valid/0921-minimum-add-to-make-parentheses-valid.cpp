class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>st;
        for(auto it : s){
            if(it == '(')st.push(it);
            else{
                if(st.empty())st.push(it);
                else if(st.top() != '(')st.push(it);
                else st.pop();
            }
        }
        int ans = 0;
        while(st.empty() == 0){
            ans++;
            st.pop();
        }
        return ans;
    }
};