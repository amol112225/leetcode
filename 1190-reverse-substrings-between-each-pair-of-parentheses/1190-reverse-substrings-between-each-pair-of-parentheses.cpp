class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        string ans="";
        stack<char>st;
        
        for(int i=0; i<n; i++){
            if(s[i]!='(' && s[i]!=')') st.push(s[i]);
            else if(s[i]=='(') st.push(s[i]);
            else if(s[i]==')'){
                string word = "";
                while(st.top()!='('){
                    word+=st.top();
                    st.pop();
                }
                st.pop();
                for(auto it : word) st.push(it);
                
            }
           
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
};