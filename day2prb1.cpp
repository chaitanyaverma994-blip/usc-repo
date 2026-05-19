#include<bits/stdc++.h>
using namespace std;
int main()
{
    int count=0;
    int q;
    int sum=0;
    int i;
    int n;
    cout << "enter the number of players" << endl;
    cin >> n;
    int arr[n];
    cout << "enter the scores of each player" << endl;
    for(i=1; i<=n; i++)
    {
        cin >> arr[i];
    }
    cout << "the scores are" << endl;
    for(i=1; i<=n; i++)
    {
        cout << arr[i] << endl;
    }
    for(i=1; i<=n; i++)
    {
        sum = sum + arr[i];
    }
    q=sum/n;
    cout << "the average is :" << q << endl;
    for(i=1; i<=n; i++)
    {
        if(arr[i] > q)
        {
            count ++;
            cout << "score greater than average is  :" << arr[i] << endl;
        }
        else
        {
            continue;
        }
    }
    cout << "the number of players having greater tha average is :" << count << endl;
}