class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxwater=0;
        int lp=0;// lp left pointer
        int rp=height.size()-1;// rp=rightpointer

        while(lp<rp){
            int capacityheight=min(height[lp],height[rp]);

            int capacitywidth=rp-lp;

            int currwatercapacity=capacityheight*capacitywidth;

            maxwater=max(currwatercapacity,maxwater);

            if(height[lp]<height[rp]){
                lp++;
                
            }else{
                rp--;
            }
        }
        return maxwater;
        
    }
};