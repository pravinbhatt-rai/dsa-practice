class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=*max_element(piles.begin(),piles.end());

        while(low<=high){
            int mid=low+(high-low)/2;
            long long hours=0;
            for(int hour:piles){
                hours+=(hour+mid-1)/mid;
            }

            (hours>h)?low=mid+1:high=mid-1;



        }
        return low;
    }
};