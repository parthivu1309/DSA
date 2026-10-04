class Solution {
public:
    int minRotations(string s) {
        int ans = 0;
        int from = 0;
        int to;
        for(int i = 0; i < s.size(); i++){
            to = s[i] - '0';
            ans += min(abs(from - to), abs(10 - abs(from - to)));
            from = to;
        }
        return ans;
    }
};