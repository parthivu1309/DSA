typedef long long int ll;
class Solution {
public:
    long long maxDifference(vector<int>& nums) {
        ll n = nums.size();

        //dp1a[i] = score of alice when alice plays first from ith index
        vector<ll>dp1a(n + 1, 0);
        //dp1b[i] = score of bob when alice plays first from ith index
        vector<ll>dp1b(n + 1, 0);
        //dp2a[i] = score of alice when bob plays first from ith index
        vector<ll>dp2a(n + 1, 0);
        //dp2b[i] = score of bob when bob plays first from ith index
        vector<ll>dp2b(n + 1, 0);

        //tabulation 

        dp2b[n - 1] = nums[n - 1];
        dp2a[n - 1] = 0;
        dp1a[n - 1] = nums[n - 1];
        dp1b[n - 1] = 0;

        ll sum = nums[n - 1];
        for(ll i = n - 2; i >= 0; i--){
            sum = sum + nums[i];

            //think of alice
            ll answer1 = 0;
            ll answer2 = 0;

            ll op1 = nums[i];
            ll op2 = nums[i] + nums[i + 1];

            if(op1 % 3 == 0){
                answer1 = op1 + dp2a[i + 1];
            }
            else{
                answer1 = op1 + dp1a[i + 1];
            }
            
            if(op2 % 3 == 0){
                answer2 = op2 + dp2a[i + 2];
            }
            else{
                answer2 = op2 + dp1a[i + 2];
            }

            if(answer1>answer2){
                dp1a[i] = answer1;
                dp1b[i] = sum-answer1;
            }
            else{
                dp1a[i] = answer2; 
                dp1b[i] = sum-answer2;
            }


            //think of bob
            answer1 = 0;
            answer2 = 0;

            op1 = nums[i];
            op2 = nums[i] + nums[i + 1];

            if(op1 % 3 == 0){
                answer1 = op1 + dp1b[i + 1];
            }
            else{
                answer1 = op1 + dp2b[i + 1];
            }
            
            if(op2 % 3 == 0){
                answer2 = op2 + dp1b[i + 2];
            }
            else{
                answer2 = op2 + dp2b[i + 2];
            }

            if(answer1>answer2){
                dp2b[i] = answer1;
                dp2a[i] = sum-answer1;
            }else{
                dp2b[i] = answer2; 
                dp2a[i] = sum-answer2;
            }

        }

        return dp1a[0] - dp1b[0];
    }
};