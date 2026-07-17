class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = strs[0];
        int i=1;//start from second string
        while(i<strs.size()){
            if(strs[i].find(ans)!=0){//not find at first index
                if(ans.empty())return ans;//it take care of undifined bihaviour
                ans.pop_back();
            }
            else{
                i++;
            }
        }
        return ans;
    }
};