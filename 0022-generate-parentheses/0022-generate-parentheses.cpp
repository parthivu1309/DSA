class Solution {
public:
    vector<string>result;
    bool isValid(string s){
        int count = 0;
        for(auto it : s){
            if(it == '(')count ++;
            else count--;

            if(count < 0)return false;
        }
        if(count == 0) return true;
        return false;
    }

    void solve(string& curr, int n){
        if(curr.size() == 2*n){
            if(isValid(curr))result.push_back(curr);
            return;
        }

        curr.push_back('(');
        solve(curr, n);

        curr.pop_back();

        curr.push_back(')');
        solve(curr, n);
        curr.pop_back();

        return;
    }
    vector<string> generateParenthesis(int n) {
        string curr = "";
        solve(curr, n);
        return result;    
    }
};