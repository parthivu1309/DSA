class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();

        stack<int>st;
        vector<int>door(n);//door[i] = j means we goes from i to j

        for(int i = 0 ; i < n; i++){
            if(s[i] == '('){
                st.push(i);
            }
            else if(s[i] == ')'){
                int j = st.top();
                st.pop();

                door[i] = j;
                door[j] = i;
            }
        }

        string ans = "";
        int flag = 1;//+1 for LTR, -1 for RLT

        for(int i = 0; i < n; i += flag){
            if(s[i] == '(' || s[i] == ')'){
                i = door[i];
                flag = -flag;
            }
            else{
                ans.push_back(s[i]);
            }
        }

        return ans;
    }
};