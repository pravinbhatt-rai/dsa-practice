class Solution {
public:
    bool checkInclusion(string s1, string s2) {
      if(s1.length()>s2.length()){
        return false;
      }

        int left=0;
        vector<int>count1(26,0);
       vector<int>count2(26,0);


       

       
          for (int i = 0; i < s1.length(); i++) { // first window calculate gareko 
            count2[s2[i] - 'a']++;
            count1[s1[i]-'a']++;
        }

        if(count1==count2){
            return true;    // s2 koh first window matai check gareko
        }

       for(int r=s1.length();r<s2.length();r++){  // s2 koh secod window dekhi start areko
        count2[s2[r]-'a']++; // adding haracter

       int l=r-s1.length();
        count2[s2[l]-'a']--; // removing the characters

        if(count1==count2){
            return true;  
        }


       }

    return false;

        
    



        
    }
};