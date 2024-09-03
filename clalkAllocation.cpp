class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int i = 0;
        long total = 0;
        int n = chalk.size();
        for (int i = 0; i < n; i++) {
            total += chalk[i];
        }
        int rem = k % total;
        for (int i = 0; i < n; i++) {
            if (rem < chalk[i])
                return i;
            rem -= chalk[i];
        }
        return 0;
    }
};