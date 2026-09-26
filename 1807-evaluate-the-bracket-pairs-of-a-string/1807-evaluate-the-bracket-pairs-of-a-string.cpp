#include <vector>
#include <string>

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n = s.size();
        //unordered_map for searching in O(1);
        unordered_map<string, string>mpp;
        for(auto it : knowledge){
            mpp[it[0]] = it[1];
        }
        string  ans= "";
        int i = 0;
        while(i < n){
            if(s[i] == '('){
                int j = i + 1;
                string key = "";

                while(j < n && s[j] != ')'){
                    key += s[j];
                    j++;
                }
                if(mpp.find(key) != mpp.end()){
                    ans += mpp[key];
                }
                else{
                    ans += "?";
                }
                i = j + 1;
            }
            else{
                ans += s[i];
                i++;
            }
        }
        return ans;
    }
};