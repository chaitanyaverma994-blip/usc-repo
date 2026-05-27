#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;

    cout << "Enter number of elements: ";
    cin >> N;

    int arr[1000];

    cout << "Enter array elements: " << endl;

    for(int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    int K;

    cout << "Enter target sum K: ";
    cin >> K;

    bool found = false;

    for(int i = 0; i < N - 2; i++)
    {
        for(int j = i + 1; j < N - 1; j++)
        {
            for(int k = j + 1; k < N; k++)
            {
                if(arr[i] + arr[j] + arr[k] == K)
                {
                    found = true;
                    break;
                }
            }

            if(found)
            {
                break;
            }
        }

        if(found)
        {
            break;
        }
    }

    if(found)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}