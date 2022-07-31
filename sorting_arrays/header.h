//
// Created by ansga on 28/07/2022.
//

#ifndef BUBBLE_SORT_C_HEADER_H
#define BUBBLE_SORT_C_HEADER_H

#endif //BUBBLE_SORT_C_HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int *arr, int i, int j){
    int tmp = arr[i];
    arr[i] = arr[j], arr[j] = tmp;
}

int lexicographic_sort(const char* a, const char* b) {
    return strcmp(a, b);
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    return strcmp(b, a);
}


void bubble_sort(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (arr[i] > arr[j] && i < j)
                swap(arr, i, j);
        }
    }
}

#define SIZE 75  //ascii printables
int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int arr_a[SIZE] = {0}, arr_b[SIZE] = {0};
    //Change char value to index and set 1 if present.
    for (int i = 0; i < (int)strlen(a); i++)
    {
        arr_a[a[i]-'0'] = 1;
    }
    for (int i = 0; i < (int)strlen(b); i++)
    {
        arr_b[b[i]-'0'] = 1;
    }

    int sum_a = 0, sum_b = 0;
    for(int i = 0; i< SIZE; i++) sum_a += arr_a[i];
    for(int i = 0; i< SIZE; i++) sum_b += arr_b[i];

    return sum_a > sum_b ? 1 : -1;
}


int sort_by_length(const char* a, const char* b) {
    return strlen(a) > strlen(b) ? 1 : -1;
}


void bubble_sortCHya(char **arr, int size,
                     int(*cmp_func)(const char *a, const char *b))
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++){
            if ( cmp_func(arr[i], arr[j]) == 1  && i < j){
                const char *tmp = arr[i];
                const char *w2 = arr[j];
                arr[i] = w2;
                arr[j] = tmp;
            }
        }
    }
}


void string_sort(char** arr,const int len,
                 int (*cmp_func)(const char* a, const char* b)){
    bubble_sortCHya(arr, len, cmp_func);
}


