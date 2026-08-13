class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string st;

        function<void(int,int)>solve =[&](int open, int close){
            if(open==n&& close==n){ //matlab auta valid wala parenthesis milo , first tyo stack lai hailai string ma convert harnuparchs,
            

           

           


            ans.push_back(st);
            return;

            }


            if(open<n){
                    st.push_back('(');

                    solve(open+1,close);
                    st.pop_back();
            }
            if(close<open){
                st.push_back(')');
                    solve(open,close+1);
                st.pop_back();
            }
        };

        solve(0,0);

        return ans;


    }
};