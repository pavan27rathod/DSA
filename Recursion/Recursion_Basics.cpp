#include<iostream>
using namespace std;

int factorial(int num){
    if(num==0)
        return 1;
    return num * factorial(num-1);
}

void print(int n){
    if(n==0)
        return;
    cout<<n<<"\t";
    print(n-1);
}

int pow(int n){
    if(n==0)
        return 1;
    int ans= 2* pow(n-1);
    return ans;
}

void fibonacciWithoutRecursion(int terms){
     int num1 = 0;
    int num2 = 1;

    int n = 3;
    cout << num1 << "  " << num2 << "  "; // Add an extra space for clarity
    while (n <= 8) {
        int num3 = num1 + num2;
        cout << num3 << "  ";
        num1 = num2;
        num2 = num3;
        n++;
    }
}

int fibonacciWithRecursion(int n){
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    int ans=fibonacciWithRecursion(n-1)+fibonacciWithRecursion(n-2);
    return ans;    
}

int sum(int num){
    if(num==0)
        return 0;
    int ans= num + sum(num-1);
    return ans;
}

void printNumbersReversely(int n){
    if(n==0){
        cout<<0;
        return;
    }
    cout<<n<<"\t";
    printNumbersReversely(n-1);
        
}

void printNumbers(int n){
    if(n==0){
        cout<<0<<"\t";
        return;
    }
    printNumbers(n-1);
    cout<<n<<"\t";

}

void printArrayReverse(int arr[], int size, int index){
    if(index == size){
        return;
    }
    printArrayReverse(arr,size,index+1);
    cout<<arr[index]<<"\t";   
}

// void printNumberReversely(int num){
//     if(num==0)
//         return;
//     int digit=num%10;
//     num=num/10;
//     printNumberReversely(num);    
//     cout<<digit<<"  ";
// }

void printDigits(int num){
    if(num == 0) {
        return;
    }
    int digit = num % 10;
    num = num / 10;
    
    cout << digit << endl;
    printDigits(num);    
}


int main(){
    printDigits(54321);
}