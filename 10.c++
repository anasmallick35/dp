/*Question:- Krishna loves candies a lot, so whenever he gets them, he stores them so that he can eat them later whenever he wants to.

He has recently received N boxes of candies each containing Ci candies where Ci represents the total number of candies in the ith box. Krishna wants to store them in a single box. The only constraint is that he can choose any two boxes and store their joint contents in an empty box only. Assume that there are an infinite number of empty boxes available.

At a time he can pick up any two boxes for transferring and if both the boxes contain X and Y number of candies respectively, then it takes him exactly X+Y seconds of time. As he is too eager to collect all of them he has approached you to tell him the minimum time in which all the candies can be collected.

Input Format:

The first line of input is the number of test case T
Each test case is comprised of two inputs
The first input of a test case is the number of boxes N
The second input is N integers delimited by whitespace denoting the number of candies in each box
Output Format: Print minimum time required, in seconds, for each of the test cases. Print each output on a new line.*/


#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int minTimeTaken(vector<int>&candies){
    priority_queue<int,vector<int>,greater<int>> minHeap(candies.begin(),candies.end());

    int totalTime = 0;
    while(minHeap.size() > 1){
        int first = minHeap.top();
        minHeap.pop();

        int second = minHeap.top();
        minHeap.pop();

        int combined = first + second;
        totalTime += combined;


        minHeap.push(combined);
    }

    return totalTime;
}

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        vector<int> candies(n);

        for(int i = 0;i<n;i++){
            cin >> candies[i];
        }

        cout << minTimeTaken(candies) << endl;
    }
    return 0;

}