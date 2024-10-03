/*Given a string s consisting of stars “*” and bars “|” ,an array of starting indices starIndex,and an array of ending indices endIndex,determine the number of stars between any two bars within the substrings between the two indices inclusive . NOTE that in this problem indexing starts at 1.

A Star is represented as an asterisk [*=ascii decimal 42]
A Bar is represented as a Pipe [“|”=ascii decimal 124]
Example :
s=’|**|*|’
startIndex=[1,1]
endIndex=[5,6]

For the first pair of indices (1,5) the substrings is “|**|*” . There are 2 stars between a pair of bars
For the second pair of indices (1,6) the substring is “|**|*|” and there are 2+1=3 stars in between the bars.
Both of the answers are returned to the array [2,3].

Constraints :
int [n];each element[i] answers the query of startIndex[i] to endindex[i]

Constraints
1<=n<=105
1<=StartInde[i]<=endIndex[i]
Each Character of s is either “*” or “|”

>Input Format for Custom testing
First line contains a string S the next line contains an integer n , the no.of elements in startIndex. Each line i of the n subsequent lines contains an integer of startIndex.the next line contains an integer n , the no.of elements in endIndex. Each line i of the n subsequent lines contains an integer of endindex
>Sample Case 0

Sample Input for Custom Testing
*|*| → s=”*|*|”
1 → startindex[] size=1
1 → startindex= 1
1 → endindex[] size=1
3 → endindex=3
Sample output  :
0
Explanation :
The substring from index =1 to index=3 is “*|*” . there is no consecutive pair of bars in this string.*/



#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> countStarsBetweenBars(const string& s, const vector<int>& startIndex, const vector<int>& endIndex) {
    int n = s.length();
    vector<int> leftBarCount(n + 1, 0);   // Count of bars up to each index
    vector<int> starCountBetweenBars(n + 1, 0);  // Cumulative stars between last bar
    int currentStarCount = 0;
    int barCount = 0;

    // Build the auxiliary arrays
    for (int i = 0; i < n; ++i) {
        if (s[i] == '|') {
            barCount += 1;
            leftBarCount[i + 1] = barCount;  // Store bar count up to this index
            starCountBetweenBars[i + 1] = starCountBetweenBars[i] + currentStarCount;
            currentStarCount = 0;  // Reset star count after a bar
        } else if (s[i] == '*') {
            currentStarCount += 1;
            starCountBetweenBars[i + 1] = starCountBetweenBars[i];  // Carry forward the last count
        }
    }

    // Prepare result array
    vector<int> result;

    // Answer each query
    for (int i = 0; i < startIndex.size(); ++i) {
        int start = startIndex[i] - 1;  // Convert to 0-based index
        int end = endIndex[i] - 1;      // Convert to 0-based index

        // Find the number of bars in the range
        int firstBar = leftBarCount[start];
        int lastBar = leftBarCount[end + 1];

        if (firstBar < lastBar) {  // There are at least two bars in the range
            int starsBetween = starCountBetweenBars[end + 1] - starCountBetweenBars[start];
            result.push_back(starsBetween);
        } else {
            result.push_back(0);  // No bars in the range
        }
    }

    return result;
}

int main() {
    string s;
    cout << "Enter the string (containing '*' and '|'): ";
    cin >> s;

    int n;
    cout << "Enter the number of queries: ";
    cin >> n;

    vector<int> startIndex(n);
    vector<int> endIndex(n);

    cout << "Enter the start indices: ";
    for (int i = 0; i < n; ++i) {
        cin >> startIndex[i];
    }

    cout << "Enter the end indices: ";
    for (int i = 0; i < n; ++i) {
        cin >> endIndex[i];
    }

    // Get the result for each query
    vector<int> result = countStarsBetweenBars(s, startIndex, endIndex);

    // Print the results
    cout << "Results: ";
    for (int count : result) {
        cout << count << " ";
    }
    cout << endl;

    return 0;
}
