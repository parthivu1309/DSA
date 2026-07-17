class Solution {
public:
    string reverseWords(string s) {
        //this is the 2 pointer approch of this question
        //first reverse the whole string and then reverse the part and used a basic white space logic
        reverse(s.begin(),s.end());
        int i =0;
        //this two are most important
        int l=0,r=0;
        int n = s.size();
        while(i<n){
            while(i<n && s[i]!=' '){
                s[r]=s[i];
                r++;
                i++;
                //s[r++]=s[i++] we can rite directly
            }
            if(l<r){
                reverse(s.begin()+l,s.begin()+r);
                s[r] = ' ';
                r++;
                l=r;
            }
            i++;
            
        }
        s= s.substr(0,r-1);
            return s;
    }
};