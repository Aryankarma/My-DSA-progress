/*  Problem statement -  First Unique Character In A String

    You are given a string A consisting of lower case English letters. You have to find the first non-repeating character
    from each stream of characters.

    For Example: If the given string is 'bbaca', then the operations are done as:

    The first stream is “b” and the first non-repeating character is ‘b’ itself, so print ‘b’.
    The next stream is “bb” and there are no non-repeating characters, so print nothing.
    The next stream is “bba” and the first non-repeating character is ‘a’, so print ‘a’.
    The next stream is “bbac” and the first non-repeating character is ‘a’, so print ‘a’.
    The next stream is “bbaca” and the first non-repeating character is ‘c’, so print ‘c’.

    Link to codingNinijas [https://www.naukri.com/code360/problems/first-unique-character-in-a-string_893404?topList=love-babbar-dsa-sheet-problems&utm_source=website&utm_medium=affiliate&utm_campaign=450dsatracker&leftPanelTabValue=PROBLEM]

*/

#include <bits/stdc++.h>
vector<char> firstNonRepeating(string stream)
{
    map<char, int> mapping;
    vector<char> ans;
    queue<char> q;
    for (int i = 0; i < stream.length(); i++)
    {
        cout << stream << endl;
        char ch = stream[i];
        q.push(ch);
        mapping[ch]++;
        while (!q.empty())
        {
            if (mapping[q.front()] > 1)
                q.pop();
            else
            {
                ans.push_back(q.front());
                break;
            }
        }
    }
    return ans;
}
