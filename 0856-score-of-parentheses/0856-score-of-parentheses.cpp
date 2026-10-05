class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.size();

        stack<char> st;
        stack<int> scores;   // score corresponding to each *

        st.push(s[0]);

        for (int i = 1; i < n; i++) {

            if (s[i] == ')') {

                int inside = 0;

                while (!st.empty() && st.top() == '*') {
                    inside += scores.top();
                    scores.pop();
                    st.pop();
                }

                if (!st.empty() && st.top() == '(') {
                    st.pop();
                }

                int currentScore=0;
                if (inside == 0) {
                    currentScore = 1;
                }
                else {
                    currentScore = inside * 2;
                }

                st.push('*');
                scores.push(currentScore);
            }
            else {
                st.push(s[i]);
            }
        }

        int score = 0;

        while (!scores.empty()) {
            score += scores.top();
            scores.pop();
        }

        return score;
    }
};