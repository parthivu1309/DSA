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
            if(st.top() == '('){
                ans++;
            }
            ans++;
            st.pop();
        }
        return ans;
    }

    int minInsertions(string s) {
        int ans = 0;
        string str = "";
        int i;
        for(i = 0; i < s.size() - 1; i++){
            if(s[i] == ')' && s[i+1] == ')'){
                //replace )) -> )
                str.push_back(')');
                i++;
            }
            else if(s[i] == ')' && s[i+1] != ')'){
                //add ) then replace )) -> ), evanlutaly add 1 to ans 
                ans++;
                str.push_back(')');
            }
            else{
                str.push_back('(');
            }
        }
        if(i == s.size() - 1){
            if(s[i] == ')')ans++;
            str.push_back(s[i]);
        }

        return ans += minAddToMakeValid(str);
    }
};