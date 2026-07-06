class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        if (occupiedIntervals.empty()) return {};

        // 1. Sort intervals by their start times
        sort(occupiedIntervals.begin(), occupiedIntervals.end());

        vector<vector<int>> merged;
        int start = occupiedIntervals[0][0];
        int end = occupiedIntervals[0][1];

        // 2. Merge overlapping and touching intervals
        for (int i = 1; i < occupiedIntervals.size(); i++) {
            // If the current interval touches or overlaps with the running interval
            if (occupiedIntervals[i][0] <= end + 1) {
                // Extend the end time to the maximum of the two
                end = max(end, occupiedIntervals[i][1]);
            } else {
                // Push the finalized interval and reset start/end
                merged.push_back({start, end});
                start = occupiedIntervals[i][0];
                end = occupiedIntervals[i][1];
            }
        }
        // Don't forget to push the final running interval!
        merged.push_back({start, end});

        // 3. Remove the free interval
        vector<vector<int>> result;
        for (const auto& interval : merged) {
            int s = interval[0];
            int e = interval[1];

            // Case A: The interval is completely outside the free time (no overlap)
            if (e < freeStart || s > freeEnd) {
                result.push_back(interval);
            }
            // Case B: The interval overlaps with the free time
            else {
                // If there's a surviving piece on the left side
                if (s < freeStart) {
                    result.push_back({s, freeStart - 1});
                }
                // If there's a surviving piece on the right side
                if (e > freeEnd) {
                    result.push_back({freeEnd + 1, e});
                }
            }
        }

        return result;
    }
};