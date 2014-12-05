//
// knapsack.cpp
//
// Created by Daniil Shevlyuk on December 4, 2014
//
//

#include "knapsack.h"
#include <stdio.h>


//============== dynamic knapsack =================

#pragma mark - dynamic knapsack

void print_matrix(int **matrix, int n, int k) {
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < k; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << '\n';
    }
    
}

int knapsack::dynamic_knapsack(item* items, int n, int capacity) {
    this->items = items;
    this->n = n;
    
    int** matrix = make_matrix_for_dynamic(n, capacity);
    
    int res = dynamic_recursive_call(n, capacity, matrix);
    
    print_matrix(matrix, n + 1, capacity + 1);
    
    delete [] matrix;
    
    return res;
}


int knapsack::dynamic_recursive_call(int items_to_pack, int capacity, int** matrix) {

    if (matrix[items_to_pack][capacity] == -1) {
        if (items[items_to_pack - 1].weight <= capacity) {
            
            int a = dynamic_recursive_call(items_to_pack - 1, capacity, matrix);
            int b = dynamic_recursive_call(items_to_pack - 1,
                                           (capacity - items[items_to_pack - 1].weight), matrix) + items[items_to_pack - 1].cost;
            
            matrix[items_to_pack][capacity] = std::max(a, b);
        } else {
            matrix[items_to_pack][capacity] = dynamic_recursive_call(items_to_pack - 1, capacity, matrix);
        }
    }
    
    return matrix[items_to_pack][capacity];
}

int** knapsack::make_matrix_for_dynamic(int n, int capacity) {
    int** matrix = new int*[n + 1];
    for(int i = 0; i < n + 1; i++) {
        matrix[i] = new int[capacity + 1];
        
        for (int j = 0; j < capacity + 1; j ++) {
            if (i == 0) {
                matrix[i][j] = 0;
            } else {
                if (j == 0) {
                    matrix[i][j] = 0;
                } else {
                    matrix[i][j] = -1;
                }
            }

        }
    }
    
    return matrix;
}


//============== end of dynamic knapsack =================



//============== backtracking knapsack =================

#pragma mark - backtracking knapsack

//virtual int backtrack_knapsack(item* items, int n, int capacity) {
//    
//}
//
//virtual int backtracking_recursive_call(int current_item, int current_weight, int current_cost, int capacity) {
//    
//}

//============== end of backtracking knapsack =================

//================== greedy knapsack ======================

#pragma mark - greedy knapsack
int knapsack::greedy_knapsack(item* items, int n, int capacity) {
    
    sort_items_by_priority(items, n, capacity);
    
    
    int res = 0;
    int maxCost = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (res + items[i].weight <= capacity) {
            res += items[i].weight;
            maxCost += items[i].cost;
        }
    }
    
    return maxCost;
}

void knapsack::sort_items_by_priority(item* items, int n, int capacity) {
    
    int increment;
    item temp;
    int j;
    
    for (increment = n / 2; increment > 0; increment /= 2) {
        for (int i = increment; i < n; i++) {
            temp = items[i];
            for (j = i; j >= increment; j -= increment) {
                if (temp.cost / temp.weight < items[j - increment].cost / items[j - increment].weight) {
                    items[j] = items[j - increment];
                } else {
                    break;
                }
            }
            items[j] = temp;
        }
    }
}
//===================end of greedy knapsack ================