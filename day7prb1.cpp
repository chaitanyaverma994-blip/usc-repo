#include <bits/stdc++.h>
using namespace std;

int main() 
{
    string s1, s2;
    cout << "enter first string" << endl;
    cin >> s1;
    cout << "enter second string" << endl;
    cin >> s2;

    if (s1.length() != s2.length()) {
        cout << "NO";
        return 0;
    }

    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    if (s1 == s2)
       {
        cout << "YES";
       } 
    else
      {
        cout << "NO";
      } 
}