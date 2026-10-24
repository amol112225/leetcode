
class Solution {
public:
    int convert(string date, map<int,int>&mpp) {
        int month = stoi(date.substr(0,2));
        int day = stoi(date.substr(3, 2));

        for (int i = 1; i < month; i++) {
            day += mpp[i];
        }
        return day;
    };
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        map<int,int> mpp = {
            {1,31},
            {2,28},
            {3,31},
            {4,30},
            {5,31},
            {6,30},
            {7,31},
            {8,31},
            {9,30},
            {10,31},
            {11,30},
            {12,31}
        };

        int a1 = convert(arriveAlice,mpp);
        int a2 = convert(leaveAlice,mpp);
        int b1 = convert(arriveBob,mpp);
        int b2 = convert(leaveBob,mpp);

        int start = max(a1, b1);
        int end = min(a2, b2);

        if (start > end) return 0;

        return end - start + 1;
    }
};
