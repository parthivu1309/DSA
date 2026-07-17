class Solution {
public:
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
        int bulbs = (brightness + 2)/3;

        sort(intervals.begin(),intervals.end());

        long long total_time = 0;
        int current_start = intervals[0][0];
        int current_end = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= current_end) {
                // Overlapping intervals: extend the current block's end if necessary
                current_end = max(current_end, intervals[i][1]);
            } else {
                // Non-overlapping: add the length of the completed block to total
                total_time += (current_end - current_start + 1);
                // Start a new block
                current_start = intervals[i][0];
                current_end = intervals[i][1];
            }
        }
        
        total_time += (current_end - current_start + 1);

        return bulbs * total_time;
    }
};