class Solution {
public:
    bool valid(string s) {
    int count = 0;

    for(char c : s) {
        if(c == '(') count++;

        else if(c == ')') count--;

        if(count < 0) return false;
    }

    return count == 0;
}
    vector<string> removeInvalidParentheses(string s) {
        int n = s.size();
        queue<string>q;
        q.push(s);
        set<string>visited;
        visited.insert(s);
        vector<string>ans;
        while(!q.empty()){
            bool found = false;
            int siz = q.size();
            while(siz--){
                string temp = q.front();
                q.pop();
                if(valid(temp)){
                    ans.push_back(temp);
                    found = true;
                }
                if(found) continue;

                for(int i=0; i<temp.size(); i++){
                    if(temp[i]!='(' && temp[i]!=')') continue;
                    string next = temp;
                    next.erase(i,1);
                    if(visited.find(next)==visited.end()){
                        visited.insert(next);
                        q.push(next);
                    }
                }

            }
            if(found) break;

        }
        return ans;
    }
};