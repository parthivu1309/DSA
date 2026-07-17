class Solution {
public:
    bool isPossible(vector<int>& piles, int num, int h) {
        long long hour = 0;
        for (int i = 0; i < piles.size(); i++) {
            hour += (piles[i] + (long long)num - 1) / num; // ceil division
        }
        return hour <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = high;//initialize ans with high 

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (isPossible(piles, mid, h)) {
                ans = mid;
                high = mid - 1; // try smaller speed
            } else {
                low = mid + 1;  // need faster speed
            }
        }
        return ans;
    }
};
