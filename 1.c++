/*Imagine you have a list of N exciting projects lined un, each with its own starting day, ending day, and a rewardirig payment. It's like a calendar full of opportunities!

Think of it as a thrilling adventure planner. Each project is like an adventure with its start and end dates, and the rewards are like treasures waiting to be claimed. Your challenge is to cleverty pick the projects that ensure you earn the maximum treasure by the end of this adventure-filled schedule. Here's the deal. You can only participate in one project per day. Your goal is to figure out the maximum amount of money you can earn.

Input The first input line contains an integer n: the number of projects

After this, there are N lines. Each such line has three integers Aj, Bj, and Ri: the starting day, the ending day, and the reward.

Output

Print one integer the maximum amount of money you can earn.*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Project{
    int start;
    int end;
    int reward;
};

bool compare(Project &a,Project &b){
    return a.end < b.end;
}

int binary(vector<Project> &projects,int i){
        int low = 0;
        int high = i-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(projects[mid].end < projects[i].start){
                if(projects[mid+1].end < projects[i].start){
                    low = mid+1;
                }
                else
                    return mid;
            }
            else
                high = mid-1;
        }
        return -1;
}

int maxReward(vector<Project>& projects){
    sort(projects.begin(),projects.end(),compare);
    int n = projects.size();

    vector<int>dp(n);
    dp[0] = projects[0].reward;

    for(int i = 1;i<n;++i){

        int includeReward = projects[i].reward;

        int idx = binary(projects,i);
        if(idx != -1){
            includeReward += dp[idx];
        }
        dp[i] = max(includeReward,dp[i-1]);
    }
    return dp[n-1];
}

int main(){
    int n;
    cin >> n;
    vector<Project> projects(n);

    for(int i = 0;i<n;++i){
        cin >> projects[i].start >> projects[i].end >> projects[i].reward;
    }

    cout << maxReward(projects)<<endl;

    return 0;
}


