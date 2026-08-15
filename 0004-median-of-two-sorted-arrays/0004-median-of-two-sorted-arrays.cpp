class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
// agar n2 syano cha bhane jn syano cah tesbara chi thal
        if(n1>n2){
            return findMedianSortedArrays(nums2,nums1);
        }


        int low=0;
        int high=n1;

        

        int total=n1+n2;

        int leftpart=(total+1)/2;


        while(low<=high){
           int cut1=low+(high-low)/2;
            int cut2=leftpart-cut1;

            int l1,l2,r1,r2;

            if(cut1==0){
                l1=INT_MIN;

            }else{
                l1=nums1[cut1-1];
            }

            l2=(cut2==0)?INT_MIN:nums2[cut2-1];

            r1=(cut1==n1)?INT_MAX:nums1[cut1];

            r2=(cut2==n2)?INT_MAX:nums2[cut2];


            if(l1<=r2&& l2<=r1){
                if(total%2==1){
                return max(l1,l2);
            }else{
                return((max(l1,l2)+min(r1,r2))/2.0);
            }

            }else if(l1<r2){
                low=cut1+1;
            }else{
                high=cut1-1;
            }
        }

        return 0.0;
    }
};