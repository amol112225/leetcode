class Solution {
public:
    int evalRPN(vector<string>& s) {
        int n = s.size();
        stack<string>st;
        for(int i=0; i<n; i++){
            if(s[i]=="+"){
                int n1 = stoi(st.top());
                st.pop();
                int n2 = stoi(st.top());
                st.pop();
                st.push(to_string(n1+n2));
            }
            
            else if(s[i]=="-"){
                int n1 = stoi(st.top());
                st.pop();
                int n2 = stoi(st.top());
                st.pop();
                st.push(to_string(n2-n1));
            }

            else if(s[i]=="*"){
                int n1 = stoi(st.top());
                st.pop();
                int n2 = stoi(st.top());
                st.pop();
                st.push(to_string(n1*n2));
            }
            else if(s[i]=="/"){
                int n1 = stoi(st.top());
                st.pop();
                int n2 = stoi(st.top());
                st.pop();
                st.push(to_string(n2/n1));
            }
            else st.push(s[i]);
        }
        return stoi(st.top());
    }
};