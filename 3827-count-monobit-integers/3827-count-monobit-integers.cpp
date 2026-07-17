class Solution {
public:
    int isValid(int n){
        vector<int>v;
        //push in vector
        while(n!=0){
            int x = n%2;
            v.push_back(x);
            n/=2;
        }
        
        int size = v.size();
        for(int i=1;i<size;i++){
            if(v[i-1]^v[i]==1)  return 0;//if two consicutive bit are not same
        }

        //else return 1
        return 1;
    }
    int countMonobit(int n) {
        int count =0;
        for(int i=0;i<=n;i++){
            count+=isValid(i);
        }

        return count;
    }
};