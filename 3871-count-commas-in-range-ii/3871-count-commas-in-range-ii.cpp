class Solution {
public:
    long long countCommas(long long n) {
        long long temp = n;
        int count = 0;
        long long commas = 0;
        while(temp != 0){
            temp = temp/10;
            count++;
        }
        if(count <=3 ) return 0;
        else if(count <= 6) commas += (n - 1000 +1);
        else if(count <= 9) commas += (1000000 - 1000) + (n -1000000 +1)*2;
        else if(count <= 12) commas += (1000000 - 1000) + (1000000000 - 1000000)*2 + (n - 1000000000 + 1)*3;
        else if (count <= 15) commas += (1000000 - 1000) + (1000000000 - 1000000)*2 + (1000000000000 - 1000000000)*3 + (n - 1000000000000 + 1)*4;
        else{
            commas += (1000000 - 1000) + (1000000000 - 1000000)*2 + (1000000000000 - 1000000000)*3 + (1000000000000000 - 1000000000000)*4 + (n - 1000000000000000 +1)*5;
        }
            
        

        return commas;

        
    }
};