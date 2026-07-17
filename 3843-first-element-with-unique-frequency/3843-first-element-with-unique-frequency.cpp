class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int,int> freq;

        // step 1: number frequency
        for(int x : nums){
            freq[x]++;
        }

        // step 2: frequency count
        unordered_map<int,int> freqCount;
        for(auto &p : freq){
            freqCount[p.second]++;
        }

        // step 3: scan original order
        for(int x : nums){
            if(freqCount[freq[x]] == 1){
                return x;
            }
        }

        return -1;
    }
};