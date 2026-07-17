class Solution {
public:

    void merge(vector<pair<char,int>>&v,int low,int mid,int high){
        vector<pair<char,int>> temp;

        int left = low;
        int right = mid+1;

        while(left<=mid && right<=high){
            if(v[left].second >= v[right].second){
                temp.push_back(v[left++]);
            }
            else{
                temp.push_back(v[right++]);
            }
        }

        while(left<=mid){
            temp.push_back(v[left++]);
        }

        while(right<=high){
            temp.push_back(v[right++]);
        }

        for(int i=low;i<=high;i++){
            v[i] = temp[i-low];
        }
    }

    void merge_sort(vector<pair<char,int>>&v,int low,int high){
        if(low>=high) return;

        int mid = (low+high)/2;

        merge_sort(v,low,mid);
        merge_sort(v,mid+1,high);

        merge(v,low,mid,high);
    }

    string frequencySort(string s) {

        vector<pair<char,int>> v(128);

        for(int i=0;i<128;i++){
            v[i] = {char(i),0};
        }

        for(char c:s){
            v[c].second++;
        }

        merge_sort(v,0,127);

        string str="";

        for(int i=0;i<127;i++){
            for(int j=0;j<v[i].second;j++){
                str+=v[i].first;
            }
        }

        return str;
    }
};