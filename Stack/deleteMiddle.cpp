#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve(stack<int> s, int size, int count)
{
    if (count == size / 2)
    {
        cout << "Middle element deleted successfully " << s.top() << endl;
        s.pop();
        return;
    }
    int num = s.top();
    s.pop();
    solve(s, size, count + 1);
    s.push(num);
    cout << num << " ";
}
stack<int> deleteMiddle(stack<int> s)
{
    //  MY APPROACH
    int n = s.size();
    int i = 0;
    stack<int> spare;

    while (i < (n + 1) / 2 - 1)
    {
        spare.push(s.top());
        s.pop();
        i++;
    }
    s.pop();
    while(!spare.empty())
    {
        s.push(spare.top());
        spare.pop();
    }
    return s;
}

int main()
{
    stack<int> s;
    int n;
    cout << "Enter no of elements ";
    cin >> n;
    cout << "Enter array elements " << endl;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = n - 1; i >= 0; i--)
        s.push(arr[i]);
    s = deleteMiddle(s);
    while(!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}