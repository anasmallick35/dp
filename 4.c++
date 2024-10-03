/*You are given an array, You have to choose a contiguous subarray of length ‘k’, and find the minimum of that segment, return the maximum of those minimums.
Sample input :
1 → Length of segment x =1
5 → size of space n = 5
1 → space = [ 1,2,3,1,2]
2
3
1
2

Sample output :
3
Explanation :
The subarrays of size x = 1 are [1],[2],[3],[1], and [2],Because each subarray only contains 1 element, each value is minimal with respect to the subarray it is in. The maximum of these values is 3. Therefore, the answer is 3*/



#include<iostream>
#include<vector>
#include<climits>
using namespace std;


int maxOfMinimum(vector<int>& arr, int k){
    int maxMin = INT_MIN;
    int n = arr.size();

    for(int i = 0;i<= n-k;i++){
        int currMin = INT_MAX;
        for(int j = i;j<i+k;j++){
            currMin = min(currMin, arr[j]);
        }

        maxMin = max(maxMin,currMin);
    }
    return maxMin;

}

int main(){
    int segment;
    cin >> segment;

    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i =0;i<n;i++){
       cin >> arr[i];
    }

int res = maxOfMinimum(arr,segment);
cout << res;
return 0;
}
