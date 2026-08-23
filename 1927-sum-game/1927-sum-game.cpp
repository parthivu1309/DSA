class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        double sumDiff = 0; // Left sum minus right sum
        double qDiff = 0;   // Left '?' count minus right '?' count
        
        for (int i = 0; i < n; i++) {
            if (i < n / 2) {
                if (num[i] == '?') qDiff++;
                else sumDiff += (num[i] - '0');
            } else {
                if (num[i] == '?') qDiff--;
                else sumDiff -= (num[i] - '0');
            }
        }
        
        // If this equals 0, Bob balanced the scales and wins (return false).
        // Otherwise, Alice wins (return true).
        return (sumDiff + 9.0 * qDiff / 2.0) != 0.0;
    }
};