class Solution {
public:
    int secondHighest(string s) {
        
        int largest=-1;
        int secondLargest=-1;
        int digit=0;

        for(char c:s){
            if(isdigit(c)){
                 digit=c-'0';
            
            if(digit>largest){
                secondLargest=largest;
                largest=digit;
            }
            else if(digit<largest&&secondLargest<digit){
                secondLargest=digit;
            }
            }
        }
        return secondLargest;
    }
};