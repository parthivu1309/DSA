class Solution {
public:
    bool checkString(string s) {
        bool b = false;
        for(auto it : s){
            if(it == 'b')b = true;
            if(b && it == 'a')return false;
        }
        return true;
    }
};