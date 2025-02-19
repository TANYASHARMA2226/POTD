/*

1415. The k-th Lexicographical String of All Happy Strings of Length n

A happy string is a string that:

consists only of letters of the set ['a', 'b', 'c'].
s[i] != s[i + 1] for all values of i from 1 to s.length - 1 (string is 1-indexed).
For example, strings "abc", "ac", "b" and "abcbabcbcb" are all happy strings and strings "aa", "baa" and "ababbc" are not happy strings.

Given two integers n and k, consider a list of all happy strings of length n sorted in lexicographical order.

Return the kth string of this list or return an empty string if there are less than k happy strings of length n.

 

Example 1:

Input: n = 1, k = 3
Output: "c"
Explanation: The list ["a", "b", "c"] contains all happy strings of length 1. The third string is "c".
Example 2:

Input: n = 1, k = 4
Output: ""
Explanation: There are only 3 happy strings of length 1.
Example 3:

Input: n = 3, k = 9
Output: "cab"
Explanation: There are 12 different happy string of length 3 ["aba", "abc", "aca", "acb", "bab", "bac", "bca", "bcb", "cab", "cac", "cba", "cbc"]. You will find the 9th string = "cab"
 

Constraints:

1 <= n <= 10
1 <= k <= 100

*********************************************  Link to the problem  **********************************************

https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n?envType=daily-question&envId=2025-02-19
*/

#include<iostream>
#include<string>
using namespace std;

void generateHappyStrings(int n, int k, string &currentString, int &indexInSortedList, string &result){
    if(currentString.size() == n){
        indexInSortedList++;
        if(indexInSortedList == k) result = currentString;
        return;
    }

    for(char currentChar = 'a';currentChar <= 'c';currentChar++){
        if(currentString.size() > 0 && currentString.back() == currentChar) continue;
        currentString += currentChar;

        generateHappyStrings(n,k,currentString,indexInSortedList,result);

        if(result != "") return;
        currentString.pop_back();
    }
}

string getAllHappyStrings(int n, int k){
    string currentString = "";
    string result = "";
    int indexInSortedList = 0;

    generateHappyStrings(n,k,currentString,indexInSortedList,result);

    return result;
}

int main(){
    int n,k;
    cout << "Enter n and k";
    cin >> n >> k;

    string result;

    result = getAllHappyStrings(n,k);

    cout << "k-th Happy string is " << result;

    return 0;
}