class Solution {
public:
    int countCommas(int n) {
        int count = 0;
        int comas = 0;
        int temp = n;
        
        while(temp != 0){
            temp = temp/10;
            count++;
        }
        if(count <= 3) return 0;
        else{
            comas += (n - 1000 +1);
        }

        return comas;
    }
};