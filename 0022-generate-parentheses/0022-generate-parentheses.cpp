class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        stack<char> st;

        function<void(int,int)>solve =[&](int open, int close){
            if(open==n&& close==n){ //matlab auta valid wala parenthesis milo , first tyo stack lai hailai string ma convert harnuparchs,
            string s;
            stack<char> temp=st;

            while(!temp.empty()){
                s+=temp.top();
                temp.pop();
            }

            reverse(s.begin(),s.end());// lifo follow garcha tei bhayera hamile reverse gareko


            ans.push_back(s);
            return;

            }


            if(open<n){
                    st.push('(');

                    solve(open+1,close);
                    st.pop();
            }
            if(close<open){
                st.push(')');
                    solve(open,close+1);
                st.pop();
            }
        };

        solve(0,0);

        return ans;


    }
};