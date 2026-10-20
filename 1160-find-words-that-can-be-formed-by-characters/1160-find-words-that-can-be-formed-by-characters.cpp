
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int n1 = words.size();
        int n2 = chars.size();

        map<char,int> mpp;
        for(int i = 0; i < n2; i++) {
            mpp[chars[i]]++;
        }

        int cnt = 0;

        for(int i = 0; i < n1; i++) {
            map<char,int> temp(mpp.begin(), mpp.end());
            bool flag = true;

            for(int j = 0; j < words[i].size(); j++) {
                char ch = words[i][j];

                if(temp.find(ch) == temp.end() || temp[ch] <= 0) {
                    flag = false;
                    break;
                }

                temp[ch]--;
            }

            if(flag) cnt += words[i].size();
        }

        return cnt;
    }
};
