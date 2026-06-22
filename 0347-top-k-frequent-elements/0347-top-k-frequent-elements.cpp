class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int,int> freq;

        for(int num:nums){
            freq[num]++;
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minheap;

        for(auto it:freq){
            int element=it.first;
            int count=it.second;

            minheap.push({count,element});

            if(minheap.size()>k){
                minheap.pop();
            }
        }

        vector<int>ans;

        while(!minheap.empty()){
            ans.push_back(minheap.top().second);
            minheap.pop();
        }

        return ans;

    }
};