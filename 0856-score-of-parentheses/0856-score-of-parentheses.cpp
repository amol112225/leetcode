class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.size();
        stack<int>st;
        int score = 0;

        for(int i=0; i<n; i++){
            if(s[i]=='(') st.push(-1);
            else{
                int inside=0;
                while(!st.empty() && st.top()!=-1){
                    inside+=st.top();
                    st.pop();
                }
                st.pop();
                int curr = 0;
                if(inside==0) curr = 1;
                else{
                    curr=inside*2;
                }
                st.push(curr);
            }
        }
        while(!st.empty()){
            score+=st.top();
            st.pop();
        }
        return score;
    }
};