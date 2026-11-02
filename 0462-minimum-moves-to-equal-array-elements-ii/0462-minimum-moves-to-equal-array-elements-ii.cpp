class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();

        //sort the array
        sort(begin(nums), end(nums));

        //finding the middle element
        int mid = nums[n/2];

        int moves = 0;
        //on n/2 iterations we can calculate the total moves
        for(int i = 0; i < n/2; i++) {
            moves += abs(nums[i] - mid);
            moves += abs(nums[n-i-1] - mid);
        }

        return moves;
    }
};