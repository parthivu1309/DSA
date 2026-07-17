class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int mx = INT_MIN;
        long long sum = 0;
        vector <int> prefixGcd;

        for(int i =0;i<nums.size();i++){
            mx = max(nums[i],mx);
            int x = gcd(nums[i],mx);
            prefixGcd.push_back(x);
        }
        sort(prefixGcd.begin(),prefixGcd.end());
        int l = 0;
        int r = prefixGcd.size() - 1;

        while(r > l){
            sum += gcd(prefixGcd[l],prefixGcd[r]);
            r--;
            l++;
        }

        return sum;
    }
};