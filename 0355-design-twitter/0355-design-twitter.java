class Twitter {

 class Tweet{
    int tweetId;
    int time;
    Tweet  next;

    Tweet(int tweetId,int time){
        this.tweetId=tweetId;
        this.time=time;
        this.next=null;
    }
 }

 Map<Integer,Tweet> tweets; // userid---> tweet user and there tweets map
 Map<Integer,Set<Integer>> following ;// user---> followers user and their followers tweet

 int time;

    public Twitter() {
        tweets=new HashMap<>();
        following=new HashMap<>();
        time=0; // global time counter
        
    }
    
    public void postTweet(int userId, int tweetId) {
        Tweet newtweet=new Tweet(tweetId,time); // naya tweet banako ya initialize gareko
        time++; // time lageko

        newtweet.next=tweets.get(userId); // agar tyo user koh tweet chan bhane teslai connect gareko hamerko next sanga 

        tweets.put(userId,newtweet); // teslai feri tweets wala map mah haleko
        
    }
    
    public List<Integer> getNewsFeed(int userId) {

        PriorityQueue<Tweet> maxheap=new PriorityQueue<>((a,b)->b.time-a.time);

        // user koh aafno latest tweet heap mah haldeh

        if(tweets.containsKey(userId)){
            maxheap.offer(tweets.get(userId)); // aafno tweet latest wala first dekhcha
        }

        Set<Integer> followees=following.getOrDefault(userId,new HashSet<>());
        /// find gardhca ki yoh user lah kn kun manche ali follow gareko cha ani tinerko feed dekhaucha ,  follow gareko hcaina bhane austa hasset dincha empty wla to chi esko default value huncha


        for(int followee:followees){
            if(tweets.containsKey(followee)){
                maxheap.offer(tweets.get(followee)); // tyo tweets yo chi followers oh cha tyo wala dekha bhaneko agar tweet wala map mah tyo userid wala heruleh aafo tweet hale bahen teslai dekha 
            }
        }

        List<Integer> result=new ArrayList<>();

        while(!maxheap.isEmpty()&&result.size()<10){
            Tweet current=maxheap.poll();

            result.add(current.tweetId);

            if(current.next!=null){
                maxheap.offer(current.next);
            }


        }

        return result;


        
    }
    
    public void follow(int followerId, int followeeId) {
        following.computeIfAbsent(followerId,k->new HashSet<>()).add(followeeId);
        
    }
    
    public void unfollow(int followerId, int followeeId) {

        if(following.containsKey(followerId)){
            following.get(followerId).remove(followeeId);
        }
        
    }
}

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * List<Integer> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */