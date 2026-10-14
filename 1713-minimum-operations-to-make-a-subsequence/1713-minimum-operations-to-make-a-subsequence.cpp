class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        unordered_map<int,int> mp;
        vector<int>nums;
        vector<int> lis;

        for(int i=0;i<target.size();i++){
            mp[target[i]]=i;
        }
        for(int x:arr){
            if(mp.count(x)){
                nums.push_back(mp[x]);// map koh index chi push huncha 

            }
        }

        for(int x:nums){
            auto it=lower_bound(lis.begin(),lis.end(),x);

            if(it==lis.end()){
                lis.push_back(x); //agar it hamro lis mei chaina 
            }else{
                *it=x; // it matlab pointer ho ani jaba *it gachum typ pointer mah jun value hincha tyo x snga replace hnca
            }


        }

        return target.size()-lis.size();


        
        
    }
};