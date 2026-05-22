#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;

    cout << "Enter value of N and X: ";
    cin >> n >> x;

    int arr[100];

    cout << "Enter array elements: " << endl;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int sum = 0;
    int ans = -1;

    for(int i = 0; i < n; i++)
    {
        sum = sum + arr[i];

        if(sum > x)
        {
            ans = i;
            break;
        }
    }

    cout << "First batch index where hall becomes full: " << ans;

    return 0;
}