#include <iostream>
using namespace std;

void search(string s1, string s2)
{
    int n = s1.length();
    int m = s2.length();
    bool isFound = false;
    int lps[m];
    lps[0] = 0;
    int l = 0, k = 1;

    while (k < m)
    {
        if (s2[k] == s2[l])
        {
            l++;
            lps[k] = l;
            k++;
        }
        else
        {
            if (l != 0)
                l = lps[l - 1];
            else
            {
                lps[k] = 0;
                k++;
            }
        }
    }

    int i = 0, j = 0;

    while (i < n)
    {
        if (s2[j] == s1[i])
        {
            i++;
            j++;
        }
        if (j == m)
        {
            isFound = true;
            cout << "Found pattern at index " << i - m << endl;
            j = lps[j - 1];
        }
        else if (i < n && s2[j] != s1[i])
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }

    }
    if (!isFound)
        cout << "Pattern Not found" << endl;
}

int main()
{
    string str1 = "AABAACAADAABAAABAA", str2 = "AABA";
    search(str1, str2);
    return 0;
}
