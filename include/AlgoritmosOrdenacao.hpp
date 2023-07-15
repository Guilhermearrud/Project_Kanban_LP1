#ifndef ALGORITMOSORDENACAO_H
#define ALGORITMOSORDENACAO_H

#include <iostream>
#include "Estruturas.hpp"

template<typename T>
class AlgoritmosOrdenacao {
public:

      static void bubbleSort(ListaDuplamenteEncadeada<T>& list, int size) {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                T& task1 = list.get(j);
                T& task2 = list.get(j + 1);
                if (task1.pegarPrioridade() > task2.pegarPrioridade()) {
                    TrocarTarefas(task1, task2);
                }
            }
        }
    }

    static void selectionSort(ListaDuplamenteEncadeada<T>& list, int size) {
        for (int i = 0; i < size - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < size; j++) {
                T& task1 = list.get(j);
                T& task2 = list.get(minIndex);
                if (task1.pegarPrioridade() > task2.pegarPrioridade()){
                    minIndex = j;
                }
            }
            if (minIndex != i) {
                T& task1 = list.get(i);
                T& task2 = list.get(minIndex);
                TrocarTarefas(task1, task2);
            }
        }
    }

private:
    static void TrocarTarefas(T& tarefa1, T& tarefa2) {
        T temp = tarefa1;
        tarefa1 = tarefa2;
        tarefa2 = temp;
    }

    static void merge(ListaDuplamenteEncadeada<T>& arr, int left, int mid, int right) {
        int left_size = mid - left + 1;
        int right_size = right - mid;
        
        T* left_arr = new T[left_size];
        T* right_arr = new T[right_size];

        for (int i = 0; i < left_size; i++) {
            left_arr[i] = arr[left + i];
        }

        for (int j = 0; j < right_size; j++) {
            right_arr[j] = arr[mid + 1 + j];
        }

        int i = 0, j = 0, k = left;
        while (i < left_size && j < right_size) {
            if (left_arr[i] <= right_arr[j]) {
                arr[k] = left_arr[i];
                i++;
            } else {
                arr[k] = right_arr[j];
                j++;
            }
            k++;
        }

        while (i < left_size) {
            arr[k] = left_arr[i];
            i++;
            k++;
        }

        while (j < right_size) {
            arr[k] = right_arr[j];
            j++;
            k++;
        }
        delete[] left_arr;
        delete[] right_arr;
    }  
};

#endif  // ALGORITMOSORDENACAO_H


