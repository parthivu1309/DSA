#include <bits/stdc++.h>
using namespace std;

//brute force
class Solution {
public:
    int maxfreq(map<char,int>&mpp){
        int max =0;
        for(auto it : mpp){
            if(max<it.second){
                max = it.second;
            }
        }
        return max;
    }
    int characterReplacement(string s, int k) {
        
        map<char,int>mpp;
        int l =0;
        int r =0;
        int maxlen =0;
        
        while(r < s.size()){
            mpp[s[r]]++;

            while(((r-l+1)-maxfreq(mpp))>k){
                mpp[s[l]]--;
                l++;
            }

            if(((r-l+1)-maxfreq(mpp))<=k){
                maxlen = max(maxlen,r-l+1);
                r++;
            }  
   
        }
        return maxlen;

    }
};

//better approach
//intution in photo1
class Solution {
public:
    int characterReplacement(string s, int k) {

        vector<int> freq(26,0);

        int l = 0;
        int r = 0;
        int maxf = 0;
        int maxlen = 0;

        while(r < s.size()){

            freq[s[r] - 'A']++;

            maxf = max(maxf, freq[s[r] - 'A']);

            while((r - l + 1) - maxf > k){
                freq[s[l] - 'A']--;
                l++;
            }

            maxlen = max(maxlen, r - l + 1);

            r++;
        }

        return maxlen;
    }
};
//optimal approach
//intution in photo2
class Solution {
public:
    int characterReplacement(string s, int k) {

        vector<int> freq(26,0);

        int l = 0;
        int r = 0;
        int maxf = 0;
        int maxlen = 0;

        while(r < s.size()){

            freq[s[r] - 'A']++;

            maxf = max(maxf, freq[s[r] - 'A']);

            if((r - l + 1) - maxf > k){
                freq[s[l] - 'A']--;
                l++;
            }

            maxlen = max(maxlen, r - l + 1);

            r++;
        }

        return maxlen;
    }
};