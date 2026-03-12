#include <bits/stdc++.h>
using namespace std;
//intution
//we have a wrong solution for this problem so that we can understand the problem and then we will solve it with the right solution
//intution is in photo

class Solution {
public:

    int atMost(vector<int>& nums, int goal){//function to finding no. of subarrays whoes sum is less than equal to goal
        if(goal < 0) return 0;

        int l = 0;
        int sum = 0;
        int count = 0;

        for(int r = 0; r < nums.size(); r++){
            sum += nums[r];

            while(sum > goal){
                sum -= nums[l];
                l++;
            }

            count += (r - l + 1);
        }

        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }
};