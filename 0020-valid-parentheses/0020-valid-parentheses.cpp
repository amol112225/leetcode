class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        int n = s.size();
        st.push(s[0]);
        for(int i=1; i<n; i++){
            
            if(s[i]==')'){
                if(!st.empty()){
                    if(st.top()!='(') return false;
                    st.pop();
                }
                else return false;
            }
            else if(s[i]=='}'){
                if(!st.empty()){
                    if(st.top()!='{') return false;
                    st.pop();

                }
                else return false;
            }
            else if(s[i]==']'){
                if(!st.empty()){
                    if(st.top()!='[') return false;
                    st.pop();
                }
                else return false;
            }
            else st.push(s[i]);
        }
        if(!st.empty()) return false;
        return true;
    }
};