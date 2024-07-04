//Find the row with maximum 1's
// 1,0,0,0
// 0,1,1,0
// 0,1,1,0
// 1,1,1,0
// 0,0,1,0
//You should return the array of 2 elements, first element will be the row in which maximum 1's are found while second element will be the count of maximim 1's
// O/P: {3,3}

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int n=mat.size();
        int oneCount=INT_MIN;
        int row=-1;
        vector <int> ans;
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j]==1)
                    count++;
            }
            if(count>oneCount){
                oneCount=count;
                row=i;
            }
        }
        ans.push_back(row);
        ans.push_back(oneCount);
        return ans;
}

int main(){
    vector<vector<int>> mat={
        {1,0,0,0},
        {0,1,1,0},
        {0,1,1,0},
        {1,1,1,0},
        {0,0,1,0}
    };
    vector<int> ans=rowAndMaximumOnes(mat);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}