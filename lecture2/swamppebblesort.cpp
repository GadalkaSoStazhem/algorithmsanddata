//
// Created by Boss on 19.08.2023.
//

//эту сортировку я подсмотрела у одного гения с хабра
//она очень быстрая и использовалась для 1806 задачи с тимуса

#include <iostream>
using namespace std;

void SwampPebbleSort(int *arr, int size)
{
    for (int j = 0; j < size - 1; j++)
    {
        if (arr[j] > arr[j + 1])
        {
            int t = arr[j + 1];
            arr[j + 1] = arr[j];
            arr[j] = t;
            for (int v = j; v > 0; v--)
            {
                if (arr[v] < arr[v - 1])
                {
                    t = arr[v - 1];
                    arr[v - 1] = arr[v];
                    arr[v] = t;
                }
                else break;
            }
        }
    }
}

int main(){
    int arr[] = {3, 9, 4, 1, 15, 6};
    SwampPebbleSort(arr, 6);
    for (auto el : arr){
        cout << el << " ";
    }
    return 0;
}

