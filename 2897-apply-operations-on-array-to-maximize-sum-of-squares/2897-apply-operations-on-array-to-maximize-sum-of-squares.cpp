class Solution {
public:
    int maxSum(vector<int>& nums, int k) {

        // har bit ki frequency count karna aur un bits ko combine karke k maximum numbers banana.
        long long mod=1e9+7;

        vector<int>cnt(31,0);
        // num=2,6,5,8,
        // bitwise:0010,0110,0101,1000,
        // count of each=1,2,2,1 ushiko store karo frequency mei

        for(int num:nums){
            for(int bit=0;bit<31;bit++){
                if(num &(1<<bit)){
                    cnt[bit]++;
                }
            }
        }

        long long ans=0;

        for(int i=0;i<k;i++){
            long long num=0;

            for(int bit=0;bit<31;bit++){
                if(cnt[bit]>0){
                    num=num|(1LL<<bit);
                    cnt[bit]--;
                }
            }
            ans= (ans+num*num)%mod;
        }

        return (int)ans;


        
    }
};