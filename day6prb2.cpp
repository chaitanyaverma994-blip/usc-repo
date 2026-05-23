#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,j;
    int sum1=0;
    int sum2=0;
    int n;
    cout << "enter the value of the square matrix" << endl;
    cin >> n;
    int a[100][100];
    cout << "enter the element of matrix" << endl;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            cin >> a[i][j];
        }
    }
    cout << "\nThe matrix is:" << endl;

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            if (i==j)
            {
                sum1=sum1+a[i][j];
            }
            if(i+j==n+1)
            {
                sum2=sum2+a[i][j];
            }
        }
    }
    if(sum1==sum2)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}