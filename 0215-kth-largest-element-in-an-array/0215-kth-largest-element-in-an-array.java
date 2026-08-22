class Solution {
    public int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer> maxheap=new PriorityQueue<>();

        for(int num:nums){
            maxheap.offer(num);

            if(maxheap.size()>k){
                maxheap.poll();
            }
        }

        return maxheap.peek();
        
    }
}