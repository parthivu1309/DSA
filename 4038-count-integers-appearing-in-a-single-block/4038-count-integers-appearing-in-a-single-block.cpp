class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int count = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            int x = nums[i];
            int start = i;
            while(i + 1 < n && nums[i + 1] == x) i++;
            int end = i;

            int j;
            for(j = 0; j < n; j++){
                if(nums[j] == x){
                    if(j <= end && j >= start) continue;
                    else break;
                }
            }
            if(j == n)count++;
        }
        return count;
    }
};