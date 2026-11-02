class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        
        if(n%groupSize!=0){
            return false;
        }

        sort(hand.begin(),hand.end());




       unordered_map<int,int> mp;

        for(int x:hand){
            mp[x]++;
        }

        for(int x:hand){
            if(mp[x]==0) 
             continue;

            for(int i=0;i<groupSize;i++){
                if(mp[i+x]==0){
                    return false;
                }

                mp[i+x]--;

        }



               

        }
        return true;
        
    }
};