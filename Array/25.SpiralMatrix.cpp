//Q. Print the Spiral Matrix: https://leetcode.com/problems/spiral-matrix/

vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector <int> ans;
        int m=matrix.size();
        int n= matrix[0].size();
        int startingRow=0;
        int endingRow=m-1;
        int startingCol=0;
        int endingCol=n-1;
        int count=0;
        int totalElements=m*n;
        while(count<totalElements){
            //First push the col
            for(int i=startingCol;i<=endingCol && count<totalElements;i++){
                ans.push_back(matrix[startingRow][i]);
                count++;
            }
            startingRow++;
            //Push the col
            for(int i=startingRow;i<=endingRow && count<totalElements;i++){
                ans.push_back(matrix[i][endingCol]);
                count++;
            }
            endingCol--;
            // Push Row
            for(int i=endingCol;i>=startingCol && count<totalElements;i--){
                ans.push_back(matrix[endingRow][i]);
                count++;
            }
            endingRow--;
            // Push Col
            for(int i=endingRow;i>=startingRow && count<totalElements;i--){
                ans.push_back(matrix[i][startingCol]);
                count++;
            }
            startingCol++;

        }
        return ans;
    }