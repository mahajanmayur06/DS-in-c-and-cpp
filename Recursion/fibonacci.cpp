#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int fibonacci(int n)
{
    if (n == 0 || n == 1)
        return n;
    return fibonacci(n-1) + fibonacci(n-2);
}

void printFibonacci(int i,int n)
{
    if (i == n)
        return;
    cout << fibonacci(i) << " ";
    printFibonacci(i+1, n);
}
int main()
{
    int n;
    cin >> n;
    // printFibonacci(0, n);
    return 0;
}