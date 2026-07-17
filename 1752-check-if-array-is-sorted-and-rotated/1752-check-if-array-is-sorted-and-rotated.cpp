class Solution {
public:
    bool check(vector<int>& nums) {
        int cont =0;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]>nums[i])
            cont++;
        }
        if(cont==0)
        return true;
        if(cont==1&&nums[nums.size()-1]<=nums[0])
        return true;

        return false;
    }
};