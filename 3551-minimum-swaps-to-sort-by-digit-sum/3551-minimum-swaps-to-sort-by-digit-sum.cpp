class Solution {
public:
    int getDigitSum(int n){
        int sum = 0;

        while(n > 0){
            sum += n % 10;
            n /= 10;
        }

        return sum;
    }
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int>afterSort(nums);

        auto lamda = [&](int num1, int num2){
            int digitSum1 = getDigitSum(num1);
            int digitSum2 = getDigitSum(num2);

            if(digitSum1 != digitSum2){
                return digitSum1 < digitSum2;
            }

            return num1 < num2;
        };
        sort(afterSort.begin(), afterSort.end(), lamda);

        unordered_map<int,int>valToInx;
        for(int i = 0; i < n; i++){
            valToInx[nums[i]] = i;
        }

        int swapCount = 0;

        for(int i = 0; i < n; i++){
            int expValue = afterSort[i];
            int currValue = nums[i];

            if(expValue == currValue)continue;
            
            int ind = valToInx[expValue];

            nums[i] = expValue;
            nums[ind] = currValue;

            valToInx[expValue] = i;
            valToInx[currValue] = ind;

            swapCount++;
        }

        return swapCount;
    }
};