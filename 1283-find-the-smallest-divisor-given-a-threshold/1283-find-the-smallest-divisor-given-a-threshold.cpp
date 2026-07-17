class Solution {
public:
    bool isPossible(vector<int>& nums,int num,int threshold){
        long long sum =0;
        int temp;
        for(int i=0;i<nums.size();i++){
            temp = (nums[i] + num -1)/num;
            sum+=temp;
        }
        if(sum<=threshold) return true;
        else return false;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int max = *max_element(nums.begin(),nums.end());
        int low =1;
        int high = max;
        int ans = max;
        while(low<=high){
            int mid =low + (high-low)/2;
            if(isPossible(nums,mid,threshold)){
                ans = mid;
                high =mid -1;
            }
            else{
                low = mid+1;
            }
        }

        return ans;
    }
};