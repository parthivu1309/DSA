class Solution {
public:
    bool checkValidString(string s) {
        int min = 0;//mini of the range
        int max = 0;//max of the range

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                min++;
                max++;
            }
            else if(s[i] == ')'){
                min--;
                max--;
            }
            else{
                min--;
                max++;
            }

            if(min < 0) min = 0;
            if(max < 0) return false;
        } 

        if(min == 0) return true;
        else return false;
    }
};