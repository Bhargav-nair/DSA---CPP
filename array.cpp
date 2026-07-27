#include <iostream>
using namespace std;

// Sum of array elements
int sumarray(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}
int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << sumarray(arr, size);
    return 0;
}


//odd number in the array
int findodd(int arr[],int n){
    int count=0;
    for(int i=0;i<n;i++){
        if(arr[i]%2!=0){
            count += 1;
        }
    }
    return count;
}
int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << findodd(arr, n);
    return 0;
}


//reverse array - brutforce
void revarray(int arr[],int n){
    int temp[n];
    for(int i=0;i<n;i++){
        temp[n-i-1]=arr[i];
    }
    for(int i=0;i<n;i++){
        arr[i]=temp[i];
    }
}
int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    revarray(arr, n);
        for(int i=0;i<n;i++){
        cout<<arr[i]<<' ';
    }
    return 0;
}


//reverse array - optimal
void revarray(int arr[],int n){
    int left=0, right=n-1;
    while(left<right){
        swap(arr[left],arr[right]);
        left=left+1;
        right--;
    }
}
int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    revarray(arr, n);
        for(int i=0;i<n;i++){
        cout<<arr[i]<<' ';
    }
    return 0;
}


//check if array is sorted - not optimal
void checkarray(int arr[],int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[i]) cout<<"false ";
        }
    }
    cout<<"ture ";
}
int main() {
    int arr[] = {1, 2, 3, 4, 9, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    checkarray(arr, n);
        for(int i=0;i<n;i++){
        cout<<arr[i]<<' ';
    }
    return 0;
}


//check if array is sorted - optimal
bool checkarray(int arr[],int n){
    for(int i=0;i<n;i++){
        if(arr[i]<arr[i-1]){
            return false;
        }
    }
    return true;
}
int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    checkarray(arr, n);
    return 0;
}
