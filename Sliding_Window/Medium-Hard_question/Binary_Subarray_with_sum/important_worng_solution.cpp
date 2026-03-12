#include <bits/stdc++.h>
using namespace std;

//this solution is wrong because it is not counting the subarrays which are having 0's in between the 1's
//you can dry run the code with the input [1,0,1,0,1] and goal = 2 to understand the problem with this code
//you will missed up so many solutions with this code

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int count = 0;
        int one = 0;
        int l =0;
        int r =0;

        while(r<nums.size()){
            if(nums[r]==1) one++;
            while(one>goal){
                if(nums[l]==1) one--;

                l++;
            }
            if(one == goal) count++;
            r++;
        }
        while(nums[l]==0){
            count++;
            l++;
        }
        
        return count;
    }
};