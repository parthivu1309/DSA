class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        long long ans;
        if(n == 1)return s;

        long long k = n/2;//this prevent overflow 
        ans = s + (k)*m - ((k) - 1);
        return ans;
    }
};