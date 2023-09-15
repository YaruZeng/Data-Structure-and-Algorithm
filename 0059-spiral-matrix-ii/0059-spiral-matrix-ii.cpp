class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>> result(n, vector<int>(n, 0));
        int startx = 0;
        int starty = 0;
        int offset = 1;
        int count = 1;
        int loop = n / 2;
        int i, j;
        
        while (loop--) {
            
            for (j = starty; j < n - offset; j++) { // the starting row
                result[startx][j] = count++;
            }
            
            for (i = startx; i < n - offset; i++) { // the ending column
                result[i][j] = count++;
            }
            
            for (; j > starty; j--) { // the ending row
                result[i][j] = count++;
            }
            
            for (; i > startx; i--) { // the starting column
                result[i][j] = count++;
            }
            
            offset++;
            startx++;
            starty++;
        }
        
        if (n%2) { // the center cell
            int mid = n / 2;
            result[mid][mid] = count;
        }
        
        return result;
    }
};