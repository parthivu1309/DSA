//intution is in photo

//code
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int low = 0;
        int high = height.size() - 1;
        int maxArea = 0;

        while(low < high){
            int w = high - low;
            int l = min(height[low],height[high]);

            int area = w*l;

            maxArea = max(maxArea,area);

            (height[low] < height[high]) ? low++ : high--;
        }

        return maxArea;
    }
};