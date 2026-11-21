class Solution {
public:
    int countConsistent(vector<int>& nums) {
        int count = 0;
        int n = nums.size();


        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                //set all the bit
                int ans = -1;
                for(int k = i; k <= j; k++){
                    ans = ans & nums[k];
                }
                int min = *min_element(nums.begin() + i,nums.begin() + j + 1);
                if(ans == min)count++;
            }
        }
        return count;
    }
};