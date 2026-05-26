#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N;

    cout << "Enter size of array: ";
    cin >> N;

    int arr[N];

    cout << "Enter array elements: ";

    for(int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    for(int i = 0; i < N; i++)
    {
        arr[i] = arr[i] * arr[i];
    }

    // Sorting squared values
    for(int i = 0; i < N-1; i++)
    {
        for(int j = i+1; j < N; j++)
        {
            if(arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    cout << "Sorted squared array: ";

    for(int i = 0; i < N; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}