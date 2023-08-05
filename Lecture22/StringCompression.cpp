#include<bits/stdc++.h>
using namespace std;

/*  443. String Compression
    Given an array of characters chars, compress it using the following algorithm:

    Begin with an empty string s. For each group of consecutive repeating characters 
    in chars:
    If the group's length is 1, append the character to s.
    Otherwise, append the character followed by the group's length.
    The compressed string s should not be returned separately, but instead, be stored 
    in the input character array chars. Note that group lengths that are 10 or longer 
    will be split into multiple characters in chars.
    After you are done modifying the input array, return the new length of the array.
    You must write an algorithm that uses only constant extra space.

    Example 1:
    Input: chars = ["a","a","b","b","c","c","c"]
    Output: Return 6, and the first 6 characters of the input array should be: 
    ["a","2","b","2","c","3"]
    Explanation: The groups are "aa", "bb", and "ccc". This compresses to "a2b2c3".
    
    Example 2:
    Input: chars = ["a"]
    Output: Return 1, and the first character of the input array should be: ["a"]
    Explanation: The only group is "a", which remains uncompressed since it's a single 
    character.
    
    Example 3:
    Input: chars = ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
    Output: Return 4, and the first 4 characters of the input array should be: 
    ["a","b","1","2"].
    Explanation: The groups are "a" and "bbbbbbbbbbbb". This compresses to "ab12".
*/

// Link to Leetcode [https://leetcode.com/problems/string-compression/]


// LeetCode solution
class Solution {
public:
    int compress(vector<char>& chars) {
        int i=0; 
        int index=0;

        while(i<chars.size()){
            int j=i+1;
            while(j<chars.size() && chars[i] == chars[j]){
                j++;
            }

            chars[index++] = chars[i];
            int count=j-i;
            if(count > 1){
                string cnt = to_string(count);
                for(char ch : cnt){
                    chars[index++] = ch;
                }
            }
            i=j;
        }
        return index;
    }
};






// VS code solution (working)- runtime error on leetcode
int main(){
    char chars[] = {'a','b','b','b','b','b','b','b','b','b','b','b','b'};
    string s;
    int size = sizeof(chars)/sizeof(chars[0]);
    int i=0, j=0;

    while(i<size){
        // is the size of array is 1
        if(size==1){
            s.push_back(chars[0]);
            break;
        }
        // when i=0 and it is single character;
        if(i == 0){
            if(chars[0] != chars[1]){
                s.push_back(chars[0]);
                i++;
                j++;
            }else{
                i++;
            }
        }

        // if i is at the end of the array i.e. i == size;
        if(i == size){
            if(chars[i] == chars[i-1]){
                int count = i-j+1;
                string cnt = to_string(count);
                s.push_back(chars[i]);
                for(int i=0; i<cnt.length(); i++){
                    char c = cnt[i];
                    s.push_back(c);
                }
                break;
            }else{
                s.push_back(chars[i]);
                break;
            }
        }
        
        // i is at the end of a consecutive group
        if(chars[i] == chars[i-1] && chars[i] != chars[i+1]){
            int count = i-j+1;
            string cnt = to_string(count);
            s.push_back(chars[i]);
            for(int i=0; i<cnt.length(); i++){
                char c = cnt[i];
                s.push_back(c);
            }
            j=i+1;
            i++;
        }
        // when i is present at the one character alone
        else if(chars[i] != chars[i-1] && chars[i] != chars[i+1]){
            s.push_back(chars[i]);
        }
        // if i is in the middle of a consecutive group
        else if(chars[i] == chars[i+1] && chars[i] == chars[i-1]){
            i++;
        }
        // if i is at the start 
        else if(chars[i] != chars[i-1] && chars[i] == chars[i+1]){
            i++;
        }
    }

    int sizeS = s.size();
    for(int i=0; i<sizeS; i++){
        chars[i] = s[i];
    }
    for(int i=sizeS; i<size; i++){
        chars[i] = '\0';
    }

    cout << "string is : " << s << endl;

    size = sizeof(chars)/sizeof(chars[0]);

    for(int i=0; i<size; i++){
        cout << chars[i] << " ";
    }cout << endl;
}
