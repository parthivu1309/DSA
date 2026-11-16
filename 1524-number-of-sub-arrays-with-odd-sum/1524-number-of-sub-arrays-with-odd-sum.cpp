class Solution {
public:
    long long MOD = 1e9 + 7;
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        vector<long long>prefixSum(n);

        prefixSum[0] = arr[0];
        for(int i = 1; i < n; i++){
            prefixSum[i] = prefixSum[i - 1] + arr[i];
        }

        int evenCount = 1;//as 0 is the even number
        int oddCount = 0;

        int ans = 0;
        for(int i = 0; i < n; i++){
            if(prefixSum[i] % 2 == 1){
                //odd
                oddCount++;
                ans = (ans + evenCount) % MOD;
            }
            else{
                //even
                evenCount++;
                ans = (ans + oddCount) % MOD;
            }
        }
        return ans % MOD;
    }
};