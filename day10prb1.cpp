#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    
    cout << "Enter number of restaurants: ";
    cin >> N;

    string restaurants[1000];

    cout << "Enter restaurant names:" << endl;
    
    for(int i = 0; i < N; i++)
    {
        cin >> restaurants[i];
    }

    string prefix;

    cout << "Enter search prefix: ";
    cin >> prefix;

    string result[1000];
    int count = 0;

    for(int i = 0; i < N; i++)
    {
        if(restaurants[i].find(prefix) == 0)
        {
            result[count] = restaurants[i];
            count++;
        }
    }

    sort(result, result + count);

    cout << "\nRestaurant names matching the prefix in lexicographical order:" << endl;

    for(int i = 0; i < count; i++)
    {
        cout << result[i] << endl;
    }

    return 0;
}