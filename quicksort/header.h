//
// Created by ansgar on 24/07/2022.
//

#ifndef QUICKSORT_C_HEADER_H
#define QUICKSORT_C_HEADER_H

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NELEMS(x)  (int)(sizeof(x) / sizeof((x)[0]))
#define SIZE 8




void print_out(int arr[SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        printf("%i ", arr[i]);
    }printf("\n");
}



void swap(int arr[], int idx1, int idx2)
{
    int tmp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = tmp;
}



int partition(int arr[], int low_idx, int high_idx)
{
    int
            pivot = arr[high_idx],
            left_ptr = low_idx,
            right_ptr = high_idx;

    while (left_ptr < right_ptr)
    {
        while (arr[left_ptr] <= pivot && left_ptr < right_ptr)
            left_ptr++;
        while (arr[right_ptr] >= pivot && left_ptr < right_ptr)
            right_ptr--;
        swap(arr, left_ptr, right_ptr);
    }
    swap(arr, left_ptr, high_idx);
    return left_ptr;
}




void quicksort(int arr[], int low_idx, int high_idx)
{
    if (low_idx >= high_idx) return;

    int
            left_ptr = partition(arr, low_idx, high_idx);

    quicksort(arr, low_idx, left_ptr - 1);
    quicksort(arr, left_ptr + 1, high_idx);
}







#endif //QUICKSORT_C_HEADER_H
