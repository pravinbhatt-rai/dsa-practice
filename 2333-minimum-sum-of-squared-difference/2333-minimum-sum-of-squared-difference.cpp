class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n=nums1.size();

        vector<int>diff(n);
        long long k=(long long)k1+k2;
        long long sum=0;
        int mx=0;


        // abs difference nikala;

        for(int i=0;i<n;i++){
            diff[i]=abs(nums1[i]-nums2[i]);
            mx=max(mx,diff[i]);
            sum+=diff[i];
        }

        

       

        if(sum<=k) return 0;

        int low=0;
        int high=mx;

        while(low<high){
            int mid=low+(high-low)/2;
            long long need =0;

            for(int d:diff){
                if(d>mid){
                    need+=d-mid;
                }
            }

            if(need<=k){
                high=mid;
            }else{
                low=mid+1;
            }

        }

        long long need=0;
        long long ans=0;

        for(int d:diff){
            if(d>low){
                need+=d-low;
            }

            long long x = min(d, low);
            ans += x * x;
        }

        long long remaining = k - need;

        ans -= remaining * (2LL * low - 1);




        
        

     


        return ans;


      
        
    }
};