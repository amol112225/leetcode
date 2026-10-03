class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        int cnt = 0;
        stack<int>st;
        st.push(-1);
        for(int i=0; i<n; i++){
            if(s[i]=='(') st.push(i);
            if(s[i]==')'){
                if(!st.empty()){
                    st.pop();
                    if(st.empty()) st.push(i);
                    else cnt = max(cnt,i-st.top());
                }
                
            }
        }
        return cnt;
    }
};