class Solution {
public:
    int alternatingSum(vector<int>& nums) {
        int sum =0;
        int i=0;
        while(i!=nums.size()){
            if(i%2==0){
                sum+=nums[i];
            }
            else{
                sum-=nums[i];
            }

            i++;
        }

        return sum;
    }
};