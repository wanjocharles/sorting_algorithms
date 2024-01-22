/*
 * File: 106-bitonic_sort.c
 * Auth: Brennan D Baraban
 */

#include "sort.h"

void swap_integers(int *first, int *second);
void bitonic_merge(int *array, size_t size, size_t start, size_t seq_size, char direction);
void bitonic_sequence(int *array, size_t size, size_t start, size_t seq_size, char direction);
void bitonic_sort(int *array, size_t size);

void swap_integers(int *first, int *second)
{
    int temp = *first;
    *first = *second;
    *second = temp;
}

void bitonic_merge(int *array, size_t size, size_t start, size_t seq_size, char direction)
{
    size_t i, jump = seq_size / 2;

    if (seq_size > 1)
    {
        for (i = start; i < start + jump; i++)
        {
            if ((direction == 'U' && array[i] > array[i + jump]) ||
                (direction == 'D' && array[i] < array[i + jump]))
                swap_integers(array + i, array + i + jump);
        }
        bitonic_merge(array, size, start, jump, direction);
        bitonic_merge(array, size, start + jump, jump, direction);
    }
}

void bitonic_sequence(int *array, size_t size, size_t start, size_t seq_size, char direction)
{
    size_t cut = seq_size / 2;
    char *sort_direction = (direction == 'U') ? "UP" : "DOWN";

    if (seq_size > 1)
    {
        printf("Merging [%lu/%lu] (%s):\n", seq_size, size, sort_direction);
        print_array(array + start, seq_size);

        bitonic_sequence(array, size, start, cut, 'U');
        bitonic_sequence(array, size, start + cut, cut, 'D');
        bitonic_merge(array, size, start, seq_size, direction);

        printf("Result [%lu/%lu] (%s):\n", seq_size, size, sort_direction);
        print_array(array + start, seq_size);
    }
}

void bitonic_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    bitonic_sequence(array, size, 0, size, 'U');
}

