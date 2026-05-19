#include<bits/stdc++.h>
using namespace std;
int main()
{
    int largest=0;
    int second_largest;
    int i;
    int n;
    cout << "enter number of transactions" << endl;
    cin >> n;
    int arr[n];
    cout << "enter the value of each transaction" << endl;
    for(i=1; i<=n; i++)
    {
        cin >> arr[i];
    }
    cout << "the amount of transactions are" << endl;
    for(i=1; i<=n; i++)
    {
        cout << arr[i] << endl;
    }
    for(i=1; i<=n; i++)
    {
        if(arr[i] > largest)
        {
            second_largest = largest;
            largest= arr[i];
        }
        else if(arr[i] > second_largest && arr[i]!=largest)
        {
            second_largest = arr[i];
        }
    }
    cout << "the second largest amount is :" << second_largest << endl;
    cout << "the largest amount is :" << largest << endl;   
}