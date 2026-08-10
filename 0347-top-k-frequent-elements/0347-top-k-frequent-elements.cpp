class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      unordered_map<int,int> freq;

      for(int i:nums){
        freq[i]++;
        
      }  

      
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > minheap;

        for(auto & i:freq){
            minheap.push({i.second,i.first});
            if(minheap.size()>k){
                minheap.pop();
            }
        }

        vector<int> ans;
        while(!minheap.empty()){
            ans.push_back(minheap.top().second);
            minheap.pop();
        }

    return ans;
    }
};