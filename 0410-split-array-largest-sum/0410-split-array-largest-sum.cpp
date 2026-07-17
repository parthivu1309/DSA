class Solution {
public:
    int split(vector<int>& nums,int mid){
        long sum =0;
        int count =1;
        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]<=mid){
                sum+=nums[i];
            }
            else{
                count++;
                sum = nums[i];
            }
        }

        return count;
    }
    int splitArray(vector<int>& nums, int k) {
       int low = *max_element(nums.begin(),nums.end());
       int high = accumulate(nums.begin(),nums.end(),0);

       while(low<=high){
        int mid = low +(high -low)/2;
        if(split(nums,mid)<=k){
           high = mid - 1;
        }
        else{
            low = mid + 1;
        }
        }

       return low;
    }
};