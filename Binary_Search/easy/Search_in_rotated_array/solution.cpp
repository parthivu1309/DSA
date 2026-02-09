#include <bits/stdc++.h>
using namespace std;
//this header file is only for local testing and debugging, 
//it should be removed when submitting the code to leetcode

/*intution 
In a rotated sorted array, the entire array is no longer fully sorted ,
but an important property still holds: in every part of the array you look at,
one side will always be sorted. This means either the 
left portion or the right portion of the array will be in increasing order. 
That’s the key idea we use to find the target efficiently.
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low =0;
        int high = nums.size()-1;
        while(low<=high){
            int mid =(low+high)/2;
            if(nums[mid]==target) return mid;
            //left part is sorted
            if(nums[mid]>=nums[low]){
                if(target>=nums[low]&&target<nums[mid]){
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }
            //right part is sorted
            else{
                if(target>nums[mid]&&target<=nums[high]){
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
            }
        }
        return -1;
    }
};