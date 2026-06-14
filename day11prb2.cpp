#include<bits/stdc++.h>
using namespace std;

int main() {

    int N;

    cout << "Enter number of participants: ";
    cin >> N;

    string name[100];
    int score[100];

    cout << "Enter participant name and score:" << endl;

    for (int i = 0; i < N; i++) {
        cin >> name[i] >> score[i];
    }
    for (int i = 0; i < N - 1; i++) {

        for (int j = 0; j < N - i - 1; j++) {

            if (score[j] > score[j + 1]) 
            {
                int tempScore = score[j];
                score[j] = score[j + 1];
                score[j + 1] = tempScore;

                string tempName = name[j];
                name[j] = name[j + 1];
                name[j + 1] = tempName;
            }
        }
    }

    cout << "Sorted Leaderboard:" << endl;

    for (int i = 0; i < N; i++) {
        cout << name[i] << " " << score[i] << endl;
    }

}