class Solution {
public:
    string makeGood(string s) {
        deque<char> dq;
        dq.push_back(s[0]);

        for (int i = 1; i < s.size(); i++) 
        {
            if (!dq.empty() && (islower(dq.back()) && isupper(s[i]) || (isupper(dq.back()) && islower(s[i])))) 
            {
                char x = tolower(dq.back());
                char y = tolower(s[i]);

                if (x == y) 
                {
                    dq.pop_back();
                } 
                else 
                {
                    dq.push_back(s[i]);
                }
            } 
            else 
            {
                dq.push_back(s[i]);
            }
        }

        string res = "";
        while (!dq.empty()) 
        {
            res += dq.front();
            dq.pop_front();
        }

        return res;
    }
};