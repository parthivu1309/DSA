class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {

        int left_sum = 0;
        int right_sum = 0;
        int maxSum = 0;

        int n = cardPoints.size();

        //first find the left_sum 
        for(int i = 0; i < k; i++)
            left_sum += cardPoints[i];

        maxSum = left_sum;
        //removing last card from left_sum and adding rightmost card to the right_sum;
        for(int i = 1; i <= k; i++){
            left_sum -= cardPoints[k - i];
            right_sum += cardPoints[n - i];
            maxSum = max(maxSum, left_sum + right_sum);
        }

        return maxSum;
    }
};