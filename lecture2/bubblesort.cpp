//
// Created by Boss on 19.08.2023.
//

#include <iostream>

using namespace std;

//po vozrastaniyu
void bubblesort(int* arr, int n){
    bool swap = true;
    while(swap){
        swap = false;
        n--;
        for (int i = 0; i < n; i++){
            if (arr[i] > arr[i + 1]){
                int tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
                swap = true;
            }
        }
    }
}

int main(){
    int arr[] = {2, 6, 8, 9, 5, 3, 4};
    bubblesort(arr, 7);
    for (auto el : arr){
        cout << el << " ";
    }
    return 0;
}
