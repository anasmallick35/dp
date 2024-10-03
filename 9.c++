/*You are required to input the size of the matrix then the elements of matrix, then you have to divide the main matrix in two sub matrices (even and odd) in such a way that element at 0 index will be considered as even and element at 1st index will be considered as odd and so on. then you have sort the even and odd matrices in ascending order then print the sum of second largest number from both the matrices

Example

enter the size of array : 5
enter element at 0 index : 3
enter element at 1 index : 4
enter element at 2 index : 1
enter element at 3 index : 7
enter element at 4 index : 9
Sorted even array : 1 3 9
Sorted odd array : 4 7

7*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    
    // Input elements of the array
    for (int i = 0; i < n; i++) {
        cout << "Enter element at index " << i << ": ";
        cin >> arr[i];
    }

    vector<int> even, odd;

    // Divide into even and odd indexed submatrices
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            even.push_back(arr[i]);
        } else {
            odd.push_back(arr[i]);
        }
    }

    // Sort both submatrices
    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());

    // Output sorted arrays
    cout << "Sorted even array: ";
    for (int e : even) {
        cout << e << " ";
    }
    cout << endl;

    cout << "Sorted odd array: ";
    for (int o : odd) {
        cout << o << " ";
    }
    cout << endl;

    // Find the second largest elements
    int secondLargestEven = (even.size() >= 2) ? even[even.size() - 2] : 0; // 0 if not enough elements
    int secondLargestOdd = (odd.size() >= 2) ? odd[odd.size() - 2] : 0; // 0 if not enough elements

    // Calculate the sum of the second largest numbers
    int result = secondLargestEven + secondLargestOdd;

    cout << result << endl;

    return 0;
}
