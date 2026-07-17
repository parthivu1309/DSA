class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int arr[256];
        for(int i =0;i<255;i++){
            arr[i] = -1;
        }
        int maxlen = 0;
        //two pointers
        int left = 0;
        int right = 0;

        while(right < s.size()){
            if(arr[s[right]]!=-1){//char at right preasent in arr
                if(left<=arr[s[right]]){
                    left = arr[s[right]]+1;//shrinking the window
                }
            }
            int len = right - left + 1;
            maxlen = max(len,maxlen);
            arr[s[right]] = right;

            //moving right forward
            right++;
        }

        return maxlen;
    }
};