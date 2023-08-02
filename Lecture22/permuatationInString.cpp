#include<bits/stdc++.h>
using namespace std;

bool arrayIsEqual(int arr1[26], int arr2[26]){
    for(int i=0; i<26; i++){
        if(arr1[i] != arr2[i]){
            return false;
        }
    }
    return true;
}

int main(){
    string s1="ab";
    string s2="eidbsabooo";
    int arr1[26] = {0};

    for(int i=0; i<s1.length(); i++){
        int index = s1[i] - 'a';
        // cout << index << endl;
        arr1[index]++;
    }

    int arr2[26] = {0};
    int windowSize = s1.length();
    string s3;
    
    for(int i=0; i<s2.length(); i++){
        s3 = s2.substr(i, windowSize);

        for(int i=0; i<windowSize; i++){
            int index = s3[i] -'a';
            // cout << s3[i] << " This is arr2 : " << index << endl;
            arr2[index]++;
            // cout << s3[i] << " This is arr2 : " << arr2[index] << endl;
        }

        // cout << "This is s3 : " << s3 << endl;
        // cout << " arr2 : " << arr2[i] << endl;

        // for(int i=0; i<26; i++){
        //     cout << "arr1 : " << arr1[i] << " arr2 : " << arr2[i] << endl;
        // }

        if(arrayIsEqual(arr1, arr2)){
            cout << "It is present" << endl;
            return true;
        }else{
            // arr2[26] = 0;
            for(int i=0; i<26; i++) {
                arr2[i]=0;
            }
            s3="";
            // cout << "It is not present right now" << endl;
        }
    }
    return 0;
}