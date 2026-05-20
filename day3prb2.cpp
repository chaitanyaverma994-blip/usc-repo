#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,j;
    int n;
    cout << "enter the value" << endl;
    cin >> n;
    for(i=0; i<n ; i++)
    {
        for(j=0; j<n; j++)
        {
            if(j==i || j+i==n-1)
            {
                cout << char('A'+i);
            }
            else
            {
                cout << "*";
            }
        }
        cout << endl;
    }
}