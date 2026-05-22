#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "enter value of n" << endl;
    cin >> n;

    int a[100][100];
    char ans[100][100];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(a[i][j] == 1)
            {
                ans[i][j] = 'O';
            }
            else
            {
                if((i > 0 && a[i-1][j] == 1) ||      
                   (i < n-1 && a[i+1][j] == 1) ||    
                   (j > 0 && a[i][j-1] == 1) ||      
                   (j < n-1 && a[i][j+1] == 1))     
                {
                    ans[i][j] = 'X';
                }
                else
                {
                    ans[i][j] = 'S';
                }
            }
        }
    }


    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}