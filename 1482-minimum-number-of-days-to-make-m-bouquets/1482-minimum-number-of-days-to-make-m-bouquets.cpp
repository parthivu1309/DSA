class Solution {
public:
    bool isPairPossible(vector<int>& bloomDay, int day, int k, int m) {
    int count = 0;
    int bouquets = 0;

    for (int i = 0; i < bloomDay.size(); i++) {
        if (bloomDay[i] <= day) {
            count++;//count sideby side only 
            if (count == k) {
                bouquets++;
                count = 0;   // reset after using k flowers
            }
        } else {
            count = 0;//if sidebyside is not avaliable then 0
        }
    }
    return bouquets >= m;
}

    int minDays(vector<int>& bloomDay, int m, int k) {
        if(bloomDay.size()<(long long)m*k) return -1;// edge case

        int max = *max_element(bloomDay.begin(),bloomDay.end());
        int low = 1;
        int high = max;
        int ans = max;

        while(low<=high){
            int mid = low + (high - low)/2;
            if(isPairPossible(bloomDay,mid,k,m)){
                ans = mid;
                high = mid-1;//try smaller one
            }
            else{
                low = mid+1;//move to bigger
            }
        }

        return ans;
    }
};