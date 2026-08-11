class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        if(n==1){
            return 1;
        }

        int left=0;
        int right=0;
        int ans=0;

        unordered_set<char> st;

while(right<n){
    while(st.count(s[right])){
        st.erase(s[left]);
        left++;
    }

    st.insert(s[right]);
    ans=max(ans,right-left+1);




    right++;
}
return ans;

        
    }
};