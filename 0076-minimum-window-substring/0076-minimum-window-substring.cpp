class Solution {
public:
    string minWindow(string s, string t) {
        vector<int>freq(126,0);
        int start=0;
        int left=0;
        int right=0;

        for(char c: t){
            freq[c]++;// {1,1,1}
        }

        int need=t.length();

        int minlength=INT_MAX;

        while(right<s.length()){

            // right koh character lai herinhhca ani compare garinche

            char c=s[right];

            if(freq[c]>0){
                need--; // need kamti gardei gayeu
            }

            freq[c]--; //frequency pani kamti gardei gayeum

            while(need==0){ // 0 bhayo matlab hailai window milo
            int windowsize = right-left+1;

            if(windowsize<minlength){
                minlength=windowsize;
                start=left;
            }

            // aba yoh bhanda min length chaiyeko cha tei bhayera hami aru pan herchum

            char leftchar=s[left];

            freq[leftchar]++;// agi freq 0 banako theo aba 1 banako

            if(freq[leftchar]>0){
                need++;
            }

            left++;


            }
            right++;

        }

        if(minlength==INT_MAX){
            return "";
        }

        return s.substr(start,minlength);


    }
};