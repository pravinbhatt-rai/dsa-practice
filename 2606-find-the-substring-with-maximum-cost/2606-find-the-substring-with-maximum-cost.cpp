class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        vector<int> cost(26);
        int sum=0;
        int curr=0;

        for(int i=0;i<26;i++){
            cost[i]=i+1;

        }

        for(int i=0;i<chars.size();i++){
            cost[chars[i]-'a']=vals[i];
        }

        for(char c:s){
            curr=max(0,curr+cost[c-'a']);
            sum=max(curr,sum);
        }

        return sum;

        
    }
};