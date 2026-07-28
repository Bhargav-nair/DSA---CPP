#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;


//hashing for number
int main() {
    int n, q;
    cout << "Enter the size of the array : "<<endl;
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the array elements :" << endl;
    int maximum = -1;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        maximum = max(maximum, arr[i]);
    }
    vector<int> freq(maximum + 1, 0);
    for (int i = 0; i < n; ++i) {
        freq[arr[i]]++;
    }
    cout << "Enter the number of iterations : "<<endl;
    cin >> q;
    cout << "Enter the numbers to be found :" << endl;
    while (q--) {
        int num;
        cin >> num;
        if (num >= 0 && num <= maximum) {
            cout << freq[num] << endl;
        } else {
            cout << 0 << endl;
        }
    }
    return 0;
}


// highest occurring element in an array - Done
int highest_occur(int arr[], int n){
    if (n<=0) return -1;
    int maximum=0;
    for(int i=1;i<n;i++){
        maximum=max(maximum,arr[i]);
    }
    vector<int> hash(maximum + 1, 0);
    for(int i=0;i<n;i++){
        hash[arr[i]]++;
    }
    int maxCount=0, ele=0;
    for(int i=0;i<maximum;i++){
        if(hash[i]>maxCount){
            maxCount=hash[i];
            ele=i;
        }
    }
    return ele;
}
int main() {
    int arr[] = {1, 2, 3, 3, 2, 5, 2, 3, 4, 8, 2, 3, 4, 4, 4, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = highest_occur(arr, n);
    cout << "Highest occurring element: " << result << endl;
    return 0;
}


// second highest occurring element
int second_largest(int arr[], int n) {
    if (n <= 0) return -1;
    int maximum = arr[0];
    for (int i = 1; i < n; ++i) {
        maximum = max(maximum, arr[i]);
    }
    vector<int> hash(maximum + 1, 0);
    for (int i = 0; i < n; ++i) {
        hash[arr[i]]++;
    }
    int firstValue = -1, secondValue = -1;
    int firstCount = 0, secondCount = 0;
    for (int i = 0; i <= maximum; ++i) {
        if (hash[i] > firstCount) {
            secondCount = firstCount;
            secondValue = firstValue;
            firstCount = hash[i];
            firstValue = i;
        } else if (hash[i] > secondCount) {
            secondCount = hash[i];
            secondValue = i;
        }
    }
    return secondValue;
}
int main() {
    int arr[] = {1,1,1,2,2,2,2,3,3,3,3,3};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = second_largest(arr, n);
    cout << "Second highest frequency count: " << result << endl;
    return 0;
}


//Sum of highest and lowest frequency
int sum_of_largest_and_lowest(int arr[], int n) {
    if (n <= 0) return -1;

    int maximum = arr[0];
    for (int i = 1; i < n; ++i) {
        maximum = max(maximum, arr[i]);
    }
    vector<int> hash(maximum + 1, 0);
    for (int i = 0; i < n; ++i) {
        hash[arr[i]]++;
    }

    int maxfre=0, minfre=n;
    for (int i = 0; i <= maximum; ++i) {
        if (hash[i] != 0) {
            maxfre=max(maxfre,hash[i]);
            minfre=min(minfre,hash[i]);
        }
    }
    return maxfre+minfre;
}
int main() {
    int arr[] = {1,2,2,2,3,3};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = sum_of_largest_and_lowest(arr, n);
    cout << "Sum of max and min frquency :" << result << endl;
    return 0;
}