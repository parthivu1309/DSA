class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans;
        map<int, int> mpp;
        
        // Step 1: Count frequencies
        for(int x : nums) {
            mpp[x]++;
        }

        // Step 2: Iterate through the map until all elements are used up
        while(!mpp.empty()) {
            auto it = mpp.begin();
            while(it != mpp.end()) {
                ans.push_back(it->first);
                it->second--;
                
                // If count reaches 0, remove it from the map so we don't process it anymore
                if(it->second == 0) {
                    it = mpp.erase(it); // erase returns the iterator to the next element
                } else {
                    ++it;
                }
            }
        }
        
        return ans;
    }
};