class Solution {
public:
    int numberOfSubstrings(string s) {
        int l = 0;
        int r = 0;
        int a_count = 0;
        int b_count = 0;
        int c_count = 0;
        int count = 0;

        while(r < s.size()){
            if(s[r] == 'a') a_count++;
            if(s[r] == 'b') b_count++;
            if(s[r] == 'c') c_count++;

            while((a_count >= 1) && (b_count >= 1) && (c_count >= 1)){
                count += s.size() - r ;//no need of +1 because r is index which is start from 0 not from 1;

                if(s[l] == 'a') a_count--;
                if(s[l] == 'b') b_count--;
                if(s[l] == 'c') c_count--;

                l++;
            }

            r++;
        }
        return count;
    }
};