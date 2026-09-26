class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n = s.size();
        string ans="";
        map<string,string>mpp;
        for(auto &x : knowledge){
            mpp[x[0]] = x[1];
        }
        for(int i=0; i<n; i++){
            if(s[i]!='('){
                ans+=s[i];
                continue;
            }
            i++;
            string word = "";
            while(s[i]!=')'){
                word+=s[i];
                i++;
            }
            
            if(mpp.find(word)!=mpp.end()){
                ans+=mpp[word];
            }
            else ans+='?';
        }
        return ans;
        
    }
};