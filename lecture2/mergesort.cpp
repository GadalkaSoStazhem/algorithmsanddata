//
// Created by Boss on 19.08.2023.
//

#include <iostream>
using namespace std;

//Этого тоже нет в лекции, моя личная инициатива


// Соединяет два подмассива
// Первый подмассив - arr[начало..середина]
// Второй подмассив - arr[середина+1..конец]
void merge(int array[], int const left,
           int const mid, int const right)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;

    // Создание временных подмассивов
    auto *leftArray = new int[subArrayOne],
            *rightArray = new int[subArrayTwo];

    // копирование данных в подмассивы
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    // объявление индексов подмассивов
    auto indexOfSubArrayOne = 0,
            indexOfSubArrayTwo = 0;

    // объявление индекса объединенного массива
    int indexOfMergedArray = left;

    // слияние подмассивов в массив
    // array[left..right]
    while (indexOfSubArrayOne < subArrayOne &&
           indexOfSubArrayTwo < subArrayTwo)
    {
        if (leftArray[indexOfSubArrayOne] <=
            rightArray[indexOfSubArrayTwo])
        {
            array[indexOfMergedArray] =
                    leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else
        {
            array[indexOfMergedArray] =
                    rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    // копирование оставшихся элементов из левого подмассива, если они есть
    while (indexOfSubArrayOne < subArrayOne)
    {
        array[indexOfMergedArray] =
                leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    // копирование оставшихся элементов из правого подмассива, если они есть
    while (indexOfSubArrayTwo < subArrayTwo)
    {
        array[indexOfMergedArray] =
                rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}

// begin - начальный индекс исходного массива, с которого он будет сортироваться
// end - конечный индекс начального массива

void mergeSort(int array[],
               int const begin,
               int const end)
{
    // рекурсия
    if (begin >= end)
        return;

    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

int main(){
    int arr[] = {3, 9, 4, 1, 15, 6};
    mergeSort(arr, 0, 5);

    for (auto el : arr){
        cout<<el<<' ';
    }
    return 0;
}
