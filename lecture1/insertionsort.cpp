//
// Created by Boss on 16.08.2023.
//
//Сортировка вставками по возрастанию
#include <iostream>
using namespace std;

void insertion_sort(int * array, int n){
    int j, tmp;
    for (int i = 1; i < n; i++){
        tmp = array[i];
        j = i;
        while (j > 0 && array[j-1] > tmp){ //поиск элемента меньше выбранного
            array[j] = array[j-1]; //сдвиг элементов вправо
            j--;
        }
        array[j] = tmp; //замена элемента на выбранное значение
    }
}

void to_least(int* arr, int n){
    int j, tmp;
    for (int i = 1; i < n; i++){
        tmp = arr[i];
        j = i;
        while (j > 0 && arr[j - 1] < tmp){
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = tmp;
    }
}

int main(){
    int arr[]= {4, 2, 5, 1, 3};
    //insertion_sort(arr, 5);
    to_least(arr, 5);
    for (auto el : arr){
        cout<<el<<' ';
    }
    return 0;
}

