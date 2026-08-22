class Solution {
    public int[][] kClosest(int[][] points, int k) {

        PriorityQueue<int[]> maxheap=new PriorityQueue<>((a,b)->{
            int Adis=a[0]*a[0]+a[1]*a[1];
            int bdis=b[0]*b[0]+b[1]*b[1]; // esle chi hamro heap mah ti points heru lai rakhcha based on higher poits ya distance koh value

            return bdis-Adis;

        });

        for(int[] num:points){
            maxheap.offer(num);
        

        if(maxheap.size()>k){
            maxheap.poll(); // khai k ora points matai rath ani sapai arulai hataideh
        }}

        int [][]result=new int[k][2];

        for(int i=0;i<k;i++){
            result[i]=maxheap.poll(); // yoh ch result mah store gareko 
        }

        return result;


        
    }
}