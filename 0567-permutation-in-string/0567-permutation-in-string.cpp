class Solution {
public:
    bool checkInclusion(string s1, string s2) {
      if(s1.length()>s2.length()){
        return false;
      }

        int left=0;
        vector<int>count1(26,0);
       vector<int>count2(26,0);


       for(char c:s1){
        count1[c-'a']++;
       }

       int windowsize=s1.length();
          for (int i = 0; i < windowsize; i++) { // first window calculate gareko 
            count2[s2[i] - 'a']++;
        }

        if(count1==count2){
            return true;    // s2 koh first window matai check gareko
        }

       for(int r=windowsize;r<s2.length();r++){  // s2 koh secod window dekhi start areko
        count2[s2[r]-'a']++; // adding haracter

       int l=r-windowsize;
        count2[s2[l]-'a']--; // removing the characters

        if(count1==count2){
            return true;  
        }


       }

    return false;

        
    



        
    }
};