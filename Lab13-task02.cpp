// Lab13-task02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int nonrepeating(vector<int> a)
{
    vector<int> freq(2001, 0);
   for (int j = 0; j < a.size(); j++)
   {
       int n = a[j];
       freq[n+1000]++;
   }
   for (int j = 0; j < a.size(); j++)
   {
       int a1 = a[j];
       if (freq[a1 + 1000] == 1)
       {
           return a1;
       }
   }
   return -1;
}
void printSortedByFrequency(string s)
{
    vector<pair<int, int>> freq(26);
    for (int i = 0; i < 26; i++)
    {
        freq[i] = { i,0 };
    }
    for(char c : s)
    {
        freq[c - 'A'].second++;
    }
    sort(freq.begin(), freq.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
        }
    );
    for (int i = 0; i < 26; i++)
    {
        int lettercode = freq[i].first;
        int count = freq[i].second;
        char ch = char(lettercode + 'A');
        while (count != 0)
        {
            cout << ch;
            count--;
        }
    }
}
int main()
{
    vector<int> vec = { 4, 5, 6, 7, 4, 6, 5, 6, 4, 5, 5, 6 };
    cout << nonrepeating(vec) << endl;
    string s = "ZXZXYYZZYYXYYZZZWWQQQQQVVVVVVVVVWXX";
    printSortedByFrequency(s);
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
