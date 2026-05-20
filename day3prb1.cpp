#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i;
    int n;
    cout << "enter the size of code" << endl;
    cin >> n;
    int arr[n];
    cout << "enter all the numbers of code" << endl;
    for(i=1; i<=n; i++)
    {
        cin >> arr[i];
    }
    cout << "the numbers in code are" << endl;
    for(i=1; i<=n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    for(i=1; i<n; i++)
    {
        if(arr[i]!=arr[i+1])
        {
            cout << "VALID" << endl;
            continue;
        }
        else if(arr[i]==arr[i+1])
        {
            cout << "INVALID " << "at index " << i+1 << " the code " << arr[i] << " is repeated " << endl;
            break;
        }
    }
}