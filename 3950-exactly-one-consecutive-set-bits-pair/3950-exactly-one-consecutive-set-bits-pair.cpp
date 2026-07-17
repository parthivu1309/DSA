class Solution {
public:
    vector<int> binary(int n){
        vector<int> ans;
        while(n != 0){
            int x = n%2;
            ans.push_back(x);
            n/=2;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    bool consecutiveSetBits(int n) {
        vector<int> s = binary(n);

        int count = 0;//count consitutive sets;
        for(int i = 1; i < s.size(); i++){
            if(s[i-1] == 1 && s[i] == 1) count++;
        }

        if(count == 1) return true;
        else return false;
    }
};