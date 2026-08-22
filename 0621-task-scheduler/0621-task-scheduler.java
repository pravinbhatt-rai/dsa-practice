class Solution {
    public int leastInterval(char[] tasks, int n) {
        int[] freq=new int[26];

        for(char task:tasks){
            freq[task-'A']++;
        }


       int maxfreq=0;

       for(int f:freq){
        maxfreq=Math.max(maxfreq,f);
       }


       int countfreq=0;

       for(int c:freq){
        if(maxfreq==c){
            countfreq++;
        }

       }

       int ans=(maxfreq-1)*(n+1)+countfreq;


       return Math.max(ans,tasks.length);
        
    }
}