#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N;

    cout << "Enter number of series names: ";
    cin >> N;

    string arr[N];

    cout << "Enter series names:" << endl;

    for(int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    string prefix = arr[0];

    for(int i = 1; i < N; i++)
    {
        while(arr[i].find(prefix) != 0)
        {
            prefix = prefix.substr(0, prefix.length() - 1);

            if(prefix == "")
            {
                break;
            }
        }
    }

    cout << "Longest Common Prefix: " << prefix << endl;
}