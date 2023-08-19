//
// Created by Boss on 19.08.2023.
//

#include <iostream>
using namespace std;

//по возрастанию
void selectionsort(int* arr, int n){
    for (int i = 0; i < n - 1; i++){
        for (int j = i + 1; j < n; j++){
            if (arr[i] > arr[j]){ //по убыванию будет <
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

void selection_optimized(int* arr, int n){
    for (int i = 0; i < n - 1; i++){
        int min = i;
        for (int j = i + 1; j < n; j++){
            if (arr[min] > arr[j]){
                min = j;
            }
        }
        int tmp = arr[i];
        arr[i] = arr[min];
        arr[min] = tmp;
    }

}

int main(){
    int arr[] = {4, 3, 9, 5, 1,10};
    selectionsort(arr, 6);
    for (auto el : arr){
        cout<<el<<' ';
    }
    int arr1[] = {10, 5, 11, 2, 8, 6};
    selection_optimized(arr1, 6);
    cout << endl;
    for (auto el : arr1){
        cout<<el<<' ';
    }
    return 0;
}
