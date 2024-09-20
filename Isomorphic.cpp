class Solution {
public:
    bool isIsomorphic(string s, string t) {

        int s_array[256] = {0};
        int t_array[256] = {0};

        int n = s.size();

        for (int i = 0; i < n; i++) {

            if (s_array[s[i]] != t_array[t[i]])
                return false;

            s_array[s[i]] = i + 1;
            t_array[t[i]] = i + 1;
        }

        return true;
    }
};