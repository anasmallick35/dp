/*You are given an integer, N. You have to turn it into the binary representation of it, and find out how many set bits are there in the binary representation.

Input Format:
The first line contains the integer.

Output Format:
One line containing an integer denoting the number of setbits.

Constraints:
1<=N<=10^9

Sample Input:
8
Output:
1

Output Description:
8 in binary is 1000.*/


#include<bits/stdc++.h>
using namespace std;

string intToBin(int n){
    string res = "";
    int cnt = 0;

    while(n>0){
        if(n%2 == 1){
            res += '1';
            cnt +=1;

        }else{
            res += '0';
        }
        n = n/2;
    }

    int a = res.size();
    int i = 0, j = a-1;
    while(i<j){
        char temp = res[i];
        res[i] = res[j];
        res[j] = temp;
        i++;
        j--;
    }
    cout << cnt << endl;
    return res;
 
}

int main(){
    int n;
    cin >> n;

    string result = intToBin(n);
    cout << result;
}