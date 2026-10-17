class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        int swaps=0;
        vector<pair<int,int>>cont(n);

        for(int i=0;i<n;i++){
            int curr=nums[i];
            int add=0;
            while(curr!=0){
                add+=curr%10;
                curr/=10;


            }
            cont[i]={add,nums[i]};





        }


        sort(cont.begin(),cont.end());

        vector<int> target(n);

        for(int i=0;i<n;i++){
            target[i]=cont[i].second;
        }

        unordered_map<int,int> pos;

          for(int i=0;i<n;i++){
            pos[nums[i]]=i;
          }

          for(int i=0;i<n;i++){
            if(nums[i]==target[i]) continue;

            int j=pos[target[i]];

            pos[nums[i]]=j;
            pos[nums[j]]=i;

            swap(nums[i],nums[j]);
            swaps++;
          }
        return swaps;


        
    }
};