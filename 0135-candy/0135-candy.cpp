class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int sum = 1;

        int i = 1;
        while(i < n){
            if(ratings[i] == ratings[i-1]){
                sum += 1;
                i++;
                continue;
            }

            int up = 0;
            while(i < n && ratings[i] > ratings[i-1]){
                up++;
                sum += up + 1;
                i++;
            }

            int down = 0;
            while(i < n && ratings[i] < ratings[i-1]){
                down++;
                sum += down + 1;
                i++;
            }

            // subtract overlap
            sum -= min(up, down);
        }

        return sum;
    }
};