class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int mini = INT_MAX;
        int index = -1;
        int minIndex = INT_MAX;
        int diff = -1;
        for(int i=0;i<capacity.size();i++){
            if(capacity[i]>=itemSize){
                diff = capacity[i]-itemSize;
                mini = min(mini,diff);
            }
        }
        if(mini == INT_MAX) return -1;

        for(int i=0;i<capacity.size();i++){
            diff = capacity[i]-itemSize;
            if(diff == mini){
                index = i;
                break;
            }
        }

        return index;
        
    }
};