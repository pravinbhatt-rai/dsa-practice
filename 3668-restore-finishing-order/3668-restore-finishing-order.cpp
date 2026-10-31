class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        vector<int> vect1;
        for(int i=0 ; i<order.size() ; i++){
            if(count(friends.begin() , friends.end() , order[i]) == 1){
                vect1.push_back(order[i]);
            }
        }
        return vect1;
    }
};