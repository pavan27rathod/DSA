#include<iostream>
#include<vector>
using namespace std;

//valid movement is possoble by folowing conditions
//1.new cell must be in bound
//2.new cell must not be visited before, i.e. it should be false
//3. new cell must be opened path i.e it should be 1

bool isSafe(int srcx, int srcy, int newx, int newy,int maze[][4],
int row, int col, vector<vector<bool>>&visited){
    if(
        (newx>=0 && newx<row) &&
        (newy>=0 && newy<col) &&
        maze[newx][newy]==1 &&
        visited[newx][newy]==false
    )
        return true;
    else
        return false;
}

void printAllPath(int maze[][4], int row, int col,int srcx,int srcy,
string &output, vector<vector<bool>>&visited){
    //Base case, we have been reached to the rat's place which is our destination
    //Destination coordinates are [row-1][col-1]
    if(srcx==row-1 && srcy==col-1){
        //Reached destination
        cout<<output<<" ";
        return;
    }

    //We can move in four direction from each point i.e. upwards, rightwards,
    //downwards & leftwards but no moving in cross or diagonal direction is allowed

    //Moving upwards, new upward coordinates will be - newx=srcx-1 & newy=srcy
    int newx=srcx-1;
    int newy=srcy;
    if(isSafe(srcx,srcy,newx,newy,maze,row,col,visited)){
        //When we visit the particular point then mark it as visited
        visited[newx][newy]=true;
        //After visiting the particular point do the same (apply recursion) for upcoming points where we can visit safely
        // & push 'U','R','D','L' respectively according to respective direction in output string
        output.push_back('U');
        printAllPath(maze,row,col,newx,newy,output,visited);

        //backtracking

        //after pusing the direction in output string we pop it for & make the visited as false to undo the task performed i.e. backtracking the performed task
        output.pop_back();
        visited[newx][newy]=false;
    }

     //Moving rightwards, new rightward coordinates will be - newx=srcx & newy=srcy+1
    newx=srcx;
    newy=srcy+1;
    if(isSafe(srcx,srcy,newx,newy,maze,row,col,visited)){
        //When we visit the particular point then mark it as visited
        visited[newx][newy]=true;
        //After visiting the particular point do the same (apply recursion) for upcoming points where we can visit safely
        // & push 'U','R','D','L' respectively according to respective direction in output string
        output.push_back('R');
        printAllPath(maze,row,col,newx,newy,output,visited);

        //backtracking

        //after pusing the direction in output string we pop it for & make the visited as false to undo the task performed i.e. backtracking the performed task
        output.pop_back();
        visited[newx][newy]=false;
    }

     //Moving downwards, new downward coordinates will be - newx=srcx+1 & newy=srcy
     // Moving downwards: newx = srcx + 1, newy = srcy
    newx = srcx + 1;
    newy = srcy; 
    if(isSafe(srcx,srcy,newx,newy,maze,row,col,visited)){
        //When we visit the particular point then mark it as visited
        visited[newx][newy]=true;
        //After visiting the particular point do the same (apply recursion) for upcoming points where we can visit safely
        // & push 'U','R','D','L' respectively according to respective direction in output string
        output.push_back('D');
        printAllPath(maze,row,col,newx,newy,output,visited);

        //backtracking

        //after pusing the direction in output string we pop it for & make the visited as false to undo the task performed i.e. backtracking the performed task
        output.pop_back();
        visited[newx][newy]=false;
    }

     //Moving upwards, new upward coordinates will be - newx=srcx & newy=srcy-1
    newx=srcx;
    newy=srcy-1;
    if(isSafe(srcx,srcy,newx,newy,maze,row,col,visited)){
        //When we visit the particular point then mark it as visited
        visited[newx][newy]=true;
        //After visiting the particular point do the same (apply recursion) for upcoming points where we can visit safely
        // & push 'U','R','D','L' respectively according to respective direction in output string
        output.push_back('L');
        printAllPath(maze,row,col,newx,newy,output,visited);

        //backtracking

        //after pusing the direction in output string we pop it for & make the visited as false to undo the task performed i.e. backtracking the performed task
        output.pop_back();
        visited[newx][newy]=false;
    }

}
int main(){
    int maze[4][4]={
        {1,0,0,0},
        {1,1,0,0},
        {1,1,1,0},
        {1,1,1,1}
    };
    int row=4;
    int col=4;

    int srcx=0;
    int srcy=0;

    string output="";

    //Create visited 2D array
    vector<vector<bool>> visited(row, vector<bool>(col,false));
    if(maze[0][0]==0){
        //If src position is closed that means rat ca not move
        cout<<"No path exists"<<endl;
    }
    else{
        visited[srcx][srcy]=true;
        printAllPath(maze,row,col,srcx,srcy,output,visited);
    }


}