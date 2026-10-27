class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string>ans;

        string s;
        for(int i = 0; i < n; i++){
            s += ".";
        }
        ans.push_back(s);
        
        for(int i = 1; i < m; i++){
            string str(n, '#');
            str[n - 1] = '.';
            ans.push_back(str);
        }

        return ans;
    }
};