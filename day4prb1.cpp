#include<bits/stdc++.h>
using namespace std;

int main()
{
    int count_vowels = 0;
    int count_words = 1;
    int count_consonants = 0;

    string sentence;

    cout << "Enter a sentence" << endl;
    getline(cin, sentence);

    int n = sentence.length();

    for(int i = 0; i < n; i++)
    {
        char ch = tolower(sentence[i]);

        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
        {
            count_vowels++;
        }
        else if(ch>='a' && ch<='z')
        {
            count_consonants++;
        }

        if(ch == ' ')
        {
            count_words++;
        }
    }

    cout << "Total vowels : " << count_vowels << endl;
    cout << "Total consonants : " << count_consonants << endl;
    cout << "Total words : " << count_words << endl;

    return 0;
}