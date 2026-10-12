class Solution {
public:
    string convert(string s, int numRows) {
        int n=(int)s.size();
        if(numRows==1||numRows>=n){
            return s;
    }

        vector<string>rows(min(n,numRows));
        int currRow=0;

        int direction=-1;

        for(char c:s){
            rows[currRow]+=c;
            if(currRow==0||currRow==numRows-1){
                direction*=-1;
            }
            currRow+=direction;
        }

        string ans;
        for(string row:rows){
            ans+=row;
        }

        return ans;


        
    }
};