class Solution {
public:
    bool rotateString(string s, string goal) {
        //If goal is rotation of s,
        //then goal must be substring of s+s
        if (s.size() != goal.size()) return false;
        return (s + s).find(goal) != string::npos;
    }
};