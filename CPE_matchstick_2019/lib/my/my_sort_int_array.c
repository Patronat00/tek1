/*
** EPITECH PROJECT, 2019
** CPool_Day04_2019
** File description:
** my_sort_int_array
*/

void my_sort_int_array(int *array, int size)
{
    int tmp;

    for (int i = 0; i != (size - 1); i++) {
        if (array[i] > array[i + 1]) {
            tmp = array[i + 1];
            array[i + 1] = array[i];
            array[i] = tmp;
            i = -1;
        }
    }
}
