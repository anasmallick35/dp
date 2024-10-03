/*Problem

Imagine you're in a mission to count unique patterns is a range of numbers from a to b But here's the rule each number should have its digits in a way that no two adiacent digits are the same

For example and b-20, you would be counting numbers like 10, 12, 13, 14, 15, 16, 17, 18, 19 and 20

Find the total number of integers following the above rule between a to b (both a and b are included in the range).

Input

The only input line han two antegens a and b

Output

Provide the count of such unique pattem.mun fied range

Constraints
0ab10018

Sample Input 123 321

Sample Output

171*/


#include<iostream>
#include<string>
using namespace std;


bool hasUniqueAdjacentNumbers(int num){
    string str = to_string(num);
    for(int i = 1;i<str.size();i++){
        if(str[i] == str[i-1]){
            return false;
        }
    }
    return true;
}

int uniquePatternNumber(int a, int b){
    int count = 0;

    for(int i = a;i<=b;i++){
        if(hasUniqueAdjacentNumbers(i)){
            count++;
        }
    }
    return count;
}

int main(){
    int a;
    int b;

    cin >> a;
    cin >> b;

    int res = uniquePatternNumber(a,b);
    cout << res;
    return 0;
}