class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        unordered_map <int,int> mpp;
        vector<int>v;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]%2 == 0){
                mpp[nums[i]]++;
            }
        }
        for(auto it : mpp){
            if(it.second == 1){
                v.push_back(it.first);
            }
        }
        if(v.size() == 0) return -1;

        for(int i =0;i<nums.size();i++){
            int flag =0;
            for(int j =0;j<v.size();j++){
                if(v[j] == nums[i]){
                    flag =1;
                }
            }
            if(flag == 1){
                return nums[i];
            }
        }

        return -1;//for safety
    }
};