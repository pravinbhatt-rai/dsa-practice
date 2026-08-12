class Solution {
public:
bool matches(vector<int>m1,vector<int> m2){
    for(int i=0;i<26;i++){
        if(m1[i]!=m2[i]){
            return false;
        }
       
    }
    return true;
}
    bool checkInclusion(string s1, string s2) {
        
        if (s1.length() > s2.length()) {
            return false;
        }

        vector<int> s1Map(26, 0);
        vector<int> s2Map(26, 0);

        for (int i = 0; i < s1.length(); i++) {

            s1Map[s1[i] - 'a']++;

            s2Map[s2[i] - 'a']++;
        }
        

        for(int i=s1.length();i<s2.length();i++){
           if( matches(s1Map,s2Map)){
           return true;
           }

            int l=i-s1.length();

            s2Map[s2[i] - 'a']++;

            s2Map[s2[l] - 'a']--;
        }

        return matches(s1Map,s2Map); // takes mre time
    }
};