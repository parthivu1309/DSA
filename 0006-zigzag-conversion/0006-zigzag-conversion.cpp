class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;

        int n = s.size();
        string ans = "";

        for(int i = 0; i < numRows; i++){
            int j = i;

            int down = 2 * (numRows - 1 - i);
            int up = 2 * i;

            bool toggle = true;

            while(j < n){
                ans += s[j];

                if(i == 0) {
                    j += down;
                }
                else if(i == numRows - 1) {
                    j += up;
                }
                else {
                    if(toggle) j += down;
                    else j += up;
                    toggle = !toggle;
                }
            }
        }

        return ans;
    }
};