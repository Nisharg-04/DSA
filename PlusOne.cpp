class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; i--) {
            int temp = digits[i];
            if (temp <= 8) {
                temp++;
                digits[i] = temp;
                break;
            } else {
                digits[i] = 0;
            }
        }
     int flag=0;
     for(int i=0;i<digits.size();i++){
        if(digits[i]!=0){
            flag=1;
        }
     }
            if ( flag==0) {
                digits.push_back(1);
                reverse(digits.begin(), digits.end());
            }
           
        
         return digits;
    }
};