class Solution {

    public int lastStoneWeight(int[] stones) {
        PriorityQueue<Integer> maxheap=new PriorityQueue<>(Collections.reverseOrder());

        for(int num:stones){
            maxheap.offer(num);
        }

        while(maxheap.size()>1){
            int first=maxheap.poll();
            int second=maxheap.poll();

            if(first!=second){
                maxheap.offer(first-second);
            }
        }

        if(maxheap.isEmpty()){
            return 0;
        }else{
            return maxheap.peek();
        }
        



        
    }
}