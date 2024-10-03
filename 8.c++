/*Problem statement : The principal has a problem with repetitions. Everytime someone sends the same email twice he becomes angry and starts yelling. His personal assistant filters the mails so that all the unique mails are sent only once, and if there is someone sending the same mail again and again, he deletes them. Write a program which will see the list of roll numbers of the student and find how many emails are to be deleted.

Sample Input:
    6
    1
    3
    3
    4
    3
    3

Sample Output:
    3*/




#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin >> n;
    unordered_map<int,int> mpp;

    for(int i = 0;i<n;i++){
        int rollNumber;
        cin >> rollNumber;
        mpp[rollNumber]++;
    }
int todelete = 0;
    for(auto it: mpp){
        if(it.second > 1){
            todelete += (it.second -1);
        }
    }
    cout << todelete;
    return 0;
}


