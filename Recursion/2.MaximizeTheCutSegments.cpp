//Q. https://www.geeksforgeeks.org/problems/cutted-segments1642/1

int maximizeTheCuts(int n, int x, int y, int z){
        if(n==0)
            return 0;
        if(n<0)
            return INT_MIN;
        //We have to cut by either x,y or z
        //When we cut by x, then we will be cutting as x + recusrive sol
        int opt1=maximizeTheCuts(n-x,x,y,z);
        
        //same with y
        int opt2=maximizeTheCuts(n-y,x,y,z);
        
        //same with z
        int opt3=maximizeTheCuts(n-z,x,y,z);
        
        int maximum=max(opt1,max(opt2,opt3));
         // If maximum is negative, it means no valid cuts were possible
        if (maximum == INT_MIN)
            return INT_MIN;
        else
            return maximum + 1;
}
