class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        if(n==1){
            return 1;
        }

        int left=0;

        int ans=0;

        vector<int> lastseen(128,-1);

for(int right=0;right<n;right++){
    char c=s[right];
    if(lastseen[c]>=left){
        left=lastseen[c]+1; // notunderstanding the behaviour need to see again
    }

    lastseen[c]=right;
    ans=max(ans,right-left+1);
}
return ans;

        
    }
};