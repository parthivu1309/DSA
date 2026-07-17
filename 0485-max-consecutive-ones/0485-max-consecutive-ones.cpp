class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxLen =0;
        int count =0;
        if(nums.size()==1){
            if(nums[0]==1) return 1;
            else return 0;
        }
        else {
            int j=0;
            for(j=0;j<nums.size();j++){
                if(nums[j]!=0) break;
            }
            if(j==nums.size()) return 0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==1&&nums[i-1]==nums[i]){
                count++;
                maxLen = max(maxLen,count);
            }
            else{
                count =0;
            }
        }
        }
        return maxLen+1;  
    }
};