class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mpp;
        vector<int> v;

        for(int i = 0; i < nums.size(); i++){
            int num = nums[i];
            int more = target - num;

            if(mpp.find(more) != mpp.end()){
                v.push_back(mpp[more]);
                v.push_back(i);
                return v;
            }

            mpp[num] = i; 
        }
        return v;
    }
};