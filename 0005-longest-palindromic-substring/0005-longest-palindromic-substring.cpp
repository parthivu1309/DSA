class Solution {
public:

    bool solve(string &s,int low,int high){
        if(low >= high) return true;

        if(s[low] == s[high]){
            return solve(s,low+1,high-1);
        }

        return false;
    }

    string longestPalindrome(string s) {

        int maxlen = INT_MIN;
        int sp = 0;

        for(int i = 0; i < s.size(); i++){
            for(int j = i; j < s.size(); j++){

                if(solve(s,i,j)){
                    if(j-i+1 > maxlen){
                        maxlen = j-i+1;
                        sp = i;
                    }
                }

            }
        }

        return s.substr(sp,maxlen);
    }
};