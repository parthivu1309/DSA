class Solution {
public:

long long int solve(vector<int>& arr) {
    // Get the size of the array
    int n = arr.size();
    
    // If there's only one house, return its value
    if (n == 1) return arr[0];

    // prev stores the maximum sum till the previous index
    long long int prev = arr[0];

    // prev2 stores the maximum sum till the index before previous
    long long int prev2 = 0;

    // Loop through houses starting from index 1
    for (int i = 1; i < n; i++) {
        // Option 1: Pick the current house and add the value from prev2
        long long int pick = arr[i];
        if (i > 1) pick += prev2;

        // Option 2: Skip the current house, take prev
        long long int nonPick = prev;

        // Choose the maximum of pick and nonPick
        long long int cur_i = max(pick, nonPick);

        // Update prev2 and prev for the next iteration
        prev2 = prev;
        prev = cur_i;
    }
    // prev will contain the maximum loot possible
    return prev;
}

    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 0) return 0;
        if(n == 1) return nums[0];

        vector<int> arr1, arr2;
        for (int i = 0; i < n; i++) {
            if (i != 0) arr1.push_back(nums[i]);
            if (i != n - 1) arr2.push_back(nums[i]);
        }
        long long int ans1 = solve(arr1);
        long long int ans2 = solve(arr2);

        return max(ans1, ans2);
    }
};