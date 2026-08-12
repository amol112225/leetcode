class Solution {
public:
    long long sumAndMultiply(int n) {
        
        stack<long long>st;
        while(n>0){
            int d=n%10;
            if(d!=0) st.push(d);
            n=n/10;
        }
        if(st.empty()) return 0;
        long long sum=st.top();
        long long x=st.top();
        st.pop();
        while(!st.empty()){
            sum+=st.top();
            x=x*10+st.top();
            st.pop();
        }
        return sum*x;
    }
};