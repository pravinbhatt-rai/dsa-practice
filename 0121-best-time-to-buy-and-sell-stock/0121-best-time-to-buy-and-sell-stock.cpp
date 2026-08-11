class Solution {
public:
    int maxProfit(vector<int>& price) {
        int bb=price[0];
        int profit=0;

        for(int i=1;i<price.size();i++){
            if(price[i]>bb){
                profit=max(profit,price[i]-bb);
            }

            bb=min(bb,price[i]);
        }

        return profit;
        
    }
};