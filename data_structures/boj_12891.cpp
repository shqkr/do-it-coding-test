#include <iostream>
using namespace std;

int stdArr[4] = {};
int curArr[4] = {};
void Add(char c);
void Remove(char c);
bool IsConditionMet();

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int S, P;
    cin >> S >> P;
    string DNA;
    cin >> DNA;
    int ans = 0;

    for (int i = 0; i < 4; i++)
    {
        cin >> stdArr[i];
    }

    // Processing initial P-length of string
    for (int i = 0; i < P; i++)
    {
        Add(DNA[i]);
    }
    if (IsConditionMet())
    {
        ans++;
    }
    
    // Using sliding window algorithm
    for (int end = P; end < S; end++)
    {
        int start = end - P;
        Add(DNA[end]);
        Remove(DNA[start]);
        if (IsConditionMet())
        {
            ans++;
        }
    }

    cout << ans << '\n';
}

// Add new char info in curArr
void Add(char c)
{
    switch (c)
    {
        case 'A': curArr[0]++; break;
        case 'C': curArr[1]++; break;
        case 'G': curArr[2]++; break;
        case 'T': curArr[3]++; break;
    }
}

// Remove char info in curArr
void Remove(char c)
{
    switch (c)
    {
        case 'A': curArr[0]--; break;
        case 'C': curArr[1]--; break;
        case 'G': curArr[2]--; break;
        case 'T': curArr[3]--; break;
    }
}

// Return if stdArr and curArr are same
bool IsConditionMet()
{
    for (int i = 0; i < 4; i++)
    {
        if (stdArr[i] > curArr[i])
            return false;
    }
    return true;
}