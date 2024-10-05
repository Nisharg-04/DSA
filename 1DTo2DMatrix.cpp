class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> ans;
        if (m * n != original.size())
            return ans;
        int temp = m;
        int temp1 = n;
        int i = 0;
        while (temp--) {
            if (i >= original.size())
                break;
            vector<int> a;
            while (temp1--) {
                if (i >= original.size())
                    break;
                a.push_back(original[i]);
                i++;
            }
            temp1=n;
            ans.push_back(a);
        }
        return ans;
    }
};