//
// Created by Boss on 19.08.2023.
//

#include <cmath>
#include <array>
#include <iostream>
using namespace std;
int binsearch_left(int* array, int n, int a){
    int left = -1;
    int right = n;
    int middle;
    while (left < right - 1){
        middle = (left + right)/2;
        if (array[middle] < a){
            left = middle;
        }
        else{
            right = middle;
        }
    }
    return right;
}

int binsearch_right(int* array, int n, int a){
    int left = -1;
    int right = n;
    int middle;
    while (left < right - 1){
        middle = (left + right)/2;
        if (array[middle] <= a){
            left = middle;
        }
        else{
            right = middle;
        }
    }
    return left;
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = end(arr) - begin(arr);
    int a = 6;
    int el_left = binsearch_left(arr, n, a);
    int el_right = binsearch_right(arr, n, a);
    cout << el_left << " " << el_right;

    return 0;
}
