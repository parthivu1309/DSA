class Solution {
public:
    int countValidPrefixes(string s) {
        int count0 = 0;
        int count1 = 0;
        int ans = 0;

        for(auto i : s){
            if(i == '1')count1++;
            else count0++;

            if(abs(count1 - count0) <= 1){
                ans++;
            }
        }

        return ans;
    }
};