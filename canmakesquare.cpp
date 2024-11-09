class Solution {
public:
    bool canMakeSquare(vector<vector<char>>& grid) {
        int wcnt = 0;
        int bcnt = 0;
        int ok=0;
        if (grid[0][0] == 'W')
            wcnt++;
        else
            bcnt++;
        if (grid[0][1] == 'W')
            wcnt++;
        else
            bcnt++;
        if (grid[1][0] == 'W')
            wcnt++;
        else
            bcnt++;
        if (grid[1][1] == 'W')
            wcnt++;
        else
            bcnt++;
        if (bcnt == 2 && wcnt == 2)
            ok++;

        bcnt = 0;
        wcnt = 0;
        if (grid[0][1] == 'W')
            wcnt++;
        else
            bcnt++;
        if (grid[0][2] == 'W')
            wcnt++;
        else
            bcnt++;
        if (grid[1][1] == 'W')
            wcnt++;
        else
            bcnt++;
        if (grid[1][2] == 'W')
            wcnt++;
        else
            bcnt++;
        if (bcnt == 2 && wcnt == 2)
           ok++;

        bcnt = 0;
        wcnt = 0;
        if (grid[1][0] == 'W')
            wcnt++;
        else
            bcnt++;
        if (grid[1][1] == 'W')
            wcnt++;
        else
            bcnt++;
        if (grid[2][0] == 'W')
            wcnt++;
        else
            bcnt++;
        if (grid[2][1] == 'W')
            wcnt++;
        else
            bcnt++;
        if (bcnt == 2 && wcnt == 2)
           ok++;

        bcnt = 0;
        wcnt = 0;
        if (grid[1][1] == 'W')
            wcnt++;
        else
            bcnt++;
        if (grid[1][2] == 'W')
            wcnt++;
        else
            bcnt++;
        if (grid[2][1] == 'W')
            wcnt++;
        else
            bcnt++;
        if (grid[2][2] == 'W')
            wcnt++;
        else
            bcnt++;
        if (bcnt == 2 && wcnt == 2)
           ok++;

    if(ok==4)return false;
        return true;
    }
};