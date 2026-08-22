class Solution {
    public int leastInterval(char[] tasks, int n) {
        int[] freq=new int[26];

        for(char task:tasks){
            freq[task-'A']++;
        }


        PriorityQueue<Integer>maxheap=new PriorityQueue(Collections.reverseOrder());

        for(int num:freq){
            if(num>0){
                maxheap.offer(num);
            }
        }

        int time=0;


        while(!maxheap.isEmpty()){
        List<Integer> temp=new ArrayList();

            for(int i=0;i<=n;i++){
                if(!maxheap.isEmpty()){
                    int count=maxheap.poll();

                    count--;

                    if(count>0){    // ekbar task lai execute garo ani agar value lai temo mah store garo feri
                        temp.add(count);
                    }}

                time++;

                if(maxheap.isEmpty()&& temp.isEmpty()){
                    break;  // jaba kei task nei hunna bhan break gardeh
                }
            }

            for(int count:temp){
                maxheap.offer(count);  // feri tyo count lai heap mah haldeh futrter koh lagi
            }
        }

        return time;


        
    }
}