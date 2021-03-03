#include <iostream>   // cout
#include <algorithm>  // copy, fill

#include "tasks.hpp"

// ИСПОЛЬЗОВАНИЕ ЛЮБЫХ ДРУГИХ БИБЛИОТЕК НЕ СОВЕТУЕТСЯ И МОЖЕТ ПОВЛИЯТЬ НА ВАШИ БАЛЛЫ

using std::cout;
using std::fill;
using std::copy;

// Задание 1
void swap_args(int *lhs, int *rhs) {
    if ((lhs != nullptr) && (rhs != nullptr)) {
        int temp = *lhs;
        *lhs = *rhs;
        *rhs = temp;
    }
}

// Задание 2
int **allocate_2d_array(int num_rows, int num_cols, int init_value) {
    if ((num_rows >= 1) && (num_cols >= 1)) {
        int **array_2d = new int *[num_rows];
        for (int row_index = 0; row_index < num_rows; row_index++) {
            array_2d[row_index] = new int[num_cols]{};
        }
        for (int row_index = 0; row_index < num_rows; row_index++){
            for (int cols_index = 0; cols_index < num_cols; cols_index++ ){
                array_2d[row_index][cols_index] = init_value;
            }
        }
        return array_2d;
    } else {
        return nullptr;
    }
}

// Задание 3
bool copy_2d_array(int **arr_2d_source, int **arr_2d_target, int num_rows, int num_cols) {
    if ((arr_2d_source == nullptr) || (arr_2d_target == nullptr) || (num_rows <= 0) || (num_cols <= 0)) {
        return false;
    } else {
        for (int row_index = 0; row_index < num_rows; row_index++) {
            copy(arr_2d_source[row_index],arr_2d_source[row_index]+ num_cols, arr_2d_target[row_index]);
        }
    } return true;
}

// Задание 4
void reverse_1d_array(vector<int> &arr) {
    int ar_size = arr.size();
    for (int elem = 0; elem < ar_size; elem++) {
        if (elem >= ar_size - elem - 1) {
            break;
        }
        int temp = arr[elem];
        arr[elem] = arr[ar_size - elem - 1];
        arr[ar_size - elem - 1] = temp;
    }
}

// Задание 5
void reverse_1d_array(int *arr_begin, int *arr_end) {
    if ((arr_begin != nullptr) || (arr_end != nullptr)){
     for (int *index = arr_begin; index <= arr_end; index++ ) {
         int temp = *index;
         int elem = (index - arr_begin);
         if (index >= arr_end - elem) {
             break;
         }
         *index = *(arr_end - elem);
         *(arr_end - elem) = temp;
     }
    }
}

// Задание 6
int *find_max_element(int *arr, int size) {
    if ((arr == nullptr) || (size <= 0)) {
        return nullptr;
    }
    else {
        int *max_elem = arr;
        for (int *elem = arr; elem < arr + size ; elem++) {
            if (*elem > *max_elem) {
                max_elem = elem;
            }
        }
        return max_elem;

    }

}

// Задание 7
vector<int> find_odd_numbers(vector<int> &arr) {
    vector<int> odd_arr;
    for (int number:arr) {
        if ((number % 2) != 0) {
            odd_arr.push_back(number);
        }
    }
    return odd_arr;
}

// Задание 8
vector<int> find_common_elements(vector<int> &arr_a, vector<int> &arr_b) {
    vector<int> comm_arr;
    vector<int> arr_b_copy = arr_b;
    for (int elem : arr_a) {
        for (int index = 0;index < arr_b_copy.size(); index++) {
            if (elem == arr_b_copy[index]) {
                comm_arr.push_back(elem);
                arr_b_copy[index] = arr_b_copy.back();
                arr_b_copy.pop_back();
                break;
            }
        }

    }
    return comm_arr;
}
