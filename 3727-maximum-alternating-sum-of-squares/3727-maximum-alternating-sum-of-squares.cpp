class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long score=0;
        int n=nums.size();

        vector<long long> squares;

        for(int x:nums){
            squares.push_back(1LL*x*x);
        }

        sort(squares.begin(),squares.end());

        for(int i=0;i<n;i++){
            if(i<n/2){
                score-=squares[i];
            }else{
                score+=squares[i];
            }
        }

        return score;
        
    }
};