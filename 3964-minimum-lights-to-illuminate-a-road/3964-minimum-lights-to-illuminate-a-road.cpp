class Solution {
public:
    int minLights(vector<int>& lights) {
        int n = lights.size();
        
        // Step 1: Difference array to mark intervals in O(1) time
        vector<int> diff(n + 1, 0);
        
        for (int i = 0; i < n; i++) {
            if (lights[i] > 0) {
                int left = max(0, i - lights[i]);
                int right = min(n - 1, i + lights[i]);
                
                diff[left] += 1;
                diff[right + 1] -= 1;
            }
        }
        
        // Step 2: Calculate prefix sums to see which positions are lit
        vector<int> arr(n, 0);
        int current_illumination = 0;
        
        for (int i = 0; i < n; i++) {
            current_illumination += diff[i];
            arr[i] = (current_illumination > 0) ? 1 : 0;
        }
        
        // Step 3: Greedy placement of new bulbs
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) {
                count++;
                
                // We place the bulb at i + 1, which covers i, i + 1, and i + 2.
                // We advance i by 2 here. The loop's i++ will advance it one more time,
                // effectively meaning the next position checked will be i + 3.
                i += 2;
            }
        }
        
        return count;
    }
};