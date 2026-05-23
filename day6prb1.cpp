#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i;
    int hasupper=0;
    int haslower=0;
    int hasdigit=0;
    string password;
    cout << "enter the password" << endl;
    getline(cin, password);
    int n=password.length();
    for(i=0; i<n; i++)
    {
       if(isupper(password[i]))
       {
        hasupper=1;
       }
       else if(islower(password[i]))
       {
        haslower=1;
       }
       else if(isdigit(password[i]))
       {
        hasdigit=1;
       }
    }
    if( hasupper && haslower && hasdigit)
    {
        cout << "STRONG";
    }
    else
    {
        cout << "WEAK";
    }
}