// n*n 2D matrix is provided as an image, rotate image by 90 degrees clockwise;
// 1 2 3
// 4 5 6
// 7 8 9
// O/P : 7 4 1
//       8 5 2
//       9 6 3

// Leetcode : https://leetcode.com/problems/rotate-image/description/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void rotate(vector<vector<int>> &matrix) {
    int n = matrix.size();

    // Get the transpose of matrix first
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    // Reverse each row
    for (int i = 0; i < n; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

void print(vector<vector<int>> &matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = i; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    rotate(matrix);
    print(matrix);
    return 0;
}