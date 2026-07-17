class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int sum = 0;
        int count1 = 0;//keeps the track of 5 
        int count2 = 0;//keeps the track of 10
        for(int i = 0 ; i < bills.size() ; i++){
            if(bills[i] == 5) count1++;
            else if(bills[i] == 10){
                if(count1){
                    count1--;
                    count2++;
                }
                else return false;
            }
            else{
                if(count1 && count2){
                    count1--;
                    count2--;
                }
                else if(count1 >= 3){
                    count1 -= 3;
                }
                else return false;
            }
        }
        return true;
    }
};