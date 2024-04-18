#include <iostream>
using namespace std;

bool isLetter(char ch ) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

void lengthOfLastWord(string s) {
    int j = 0;
    int right = s.size() - 1;
    while (!isLetter(s[right])) {
        right--;
    }
    j = right;
    right--;
    
    while (isLetter(s[right])) {
        right--;
    }
    cout << s[j] << " " << right << " " << s[right] << " ";
    cout <<  (j - right) << endl;
}

int main()
{
    string str1 = "Hello World";
    string str2 = "   fly me   to   the moon  ";
    string str3 = "a ";
    string str4 = "a";
    
    lengthOfLastWord(str1);
    lengthOfLastWord(str2);
    lengthOfLastWord(str3);
    lengthOfLastWord(str4);
    return 0;
}