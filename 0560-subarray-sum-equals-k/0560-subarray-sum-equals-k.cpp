class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int pref_sum = 0;
        int count =0;
        unordered_map<int,int>mpp;
        mpp[pref_sum]++;
        for(int i=0;i<nums.size();i++){
            pref_sum+=nums[i];
            if(mpp.find(pref_sum-k)==mpp.end()){
                mpp[pref_sum]++;
            }
            else{
                count+= mpp[pref_sum-k];
                mpp[pref_sum]++;
            }
        }
        return count;
    }
};