//
// Created by Boss on 19.08.2023.
//

//этого в лекции уже не было
#include <iostream>

#include <cstdlib> //тут есть встроенная qsort
using namespace std;
void qsortRecursive(int *mas, int size) {
    //Указатели в начало и в конец массива
    int i = 0;
    int j = size - 1;

    //Центральный элемент массива
    int mid = mas[size / 2];

    //Делим массив
    do {
        //Пробегаем элементы, ищем те, которые нужно перекинуть в другую часть
        //В левой части массива пропускаем(оставляем на месте) элементы, которые меньше центрального
        while(mas[i] < mid) {
            i++;
        }
        //В правой части пропускаем элементы, которые больше центрального
        while(mas[j] > mid) {
            j--;
        }

        //Меняем элементы местами
        if (i <= j) {
            int tmp = mas[i];
            mas[i] = mas[j];
            mas[j] = tmp;

            i++;
            j--;
        }
    } while (i <= j);


    //Рекурсивные вызовы, если осталось, что сортировать
    if(j > 0) {
        //"Левый кусок"
        qsortRecursive(mas, j + 1);
    }
    if (i < size) {
        //"Првый кусок"
        qsortRecursive(&mas[i], size - i);
    }
}
//компаратор для встроенной qsort
int comp(const void *a, const void *b){
    return (*(int *) a - *(int *) b); //по возрастанию, по убыванию будет б минус а
};

int main(){
    int arr[] = {3, 9, 4, 1, 15, 6};
    qsortRecursive(arr, 6);

    for (auto el : arr){
        cout<<el<<' ';
    }
//встроенная функция
    int arr1[] = {3, 9, 4, 1, 15, 6};
    qsort(arr1, 6, sizeof(int), comp);
    cout << endl;
    for (auto el : arr1){
        cout<<el<<' ';
    }
    return 0;
}
