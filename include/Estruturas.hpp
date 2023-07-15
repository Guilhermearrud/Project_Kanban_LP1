#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

#include <iostream>
using namespace std;

template <typename T>
class No
{
public:
    T valor;
    No *prev;
    No *next;

    No(T valor) : valor(valor), prev(nullptr), next(nullptr) {}
    ~No() {}
};

template <typename T>
class ListaDuplamenteEncadeada
{
private:
    No<T> *comeco;
    No<T> *fim;

public:
    ListaDuplamenteEncadeada() : comeco(nullptr), fim(nullptr) {}

    ~ListaDuplamenteEncadeada()
    {
        clear();
    }

    No<T> *getcomeco() const
    {
        return comeco;
    }

    void pushFront(T value)
    {
        No<T> *newNo = new No<T>(value);
        if (isEmpty())
        {
            comeco = fim = newNo;
        }
        else
        {
            newNo->next = comeco;
            comeco->prev = newNo;
            comeco = newNo;
        }
    }

    bool removeValue(const T& value){
      if(isEmpty()){
        return false;
      }

      No<T>* current = comeco;

      if(current->valor == value){
        comeco = current->next;

        if(comeco != NULL){
          comeco->prev = NULL;
        }else{
          fim = NULL;
        }

        delete current;
        return true;
      }

      while(current != NULL) {
        if(current->valor == value) {
          No<T>* prevNo = current->prev;
          No<T>* nextNo = current->next;

          if(prevNo != NULL) {
            prevNo->next = nextNo;
          }

          if(nextNo != NULL) {
            nextNo->prev = prevNo;
          }else{
            fim = prevNo;
          }

          delete current;
          return true;
        }
        current = current->next;
      }
      return false;
    }


    void pushBack(T value)
    {
        No<T> *newNo = new No<T>(value);
        if (isEmpty())
        {
            comeco = fim = newNo;
        }
        else
        {
            fim->next = newNo;
            newNo->prev = fim;
            fim = newNo;
        }
    }

    bool isEmpty() const
    {
        return comeco == nullptr;
    }

    void clear()
    {
        No<T> *current = comeco;

        while (current != nullptr)
        {
            No<T> *nextNo = current->next;
            delete current;
            current = nextNo;
        }

        comeco = fim = nullptr;
    }

    T &get(int index) const
    {
        if (index < 0 || index >= PegarTamanhoQuadro())
        {
            throw std::out_of_range("Index não encontrado.");
        }

        No<T> *current = comeco;
        int currentIndex = 0;

        while (current != NULL)
        {
            if (currentIndex == index)
            {
                return current->valor;
            }
            current = current->next;
            currentIndex++;
        }

        throw std::out_of_range("Index não encontrado.");
    }

    int PegarTamanhoQuadro() const
    {
        int size = 0;

        No<T> *current = comeco;

        while (current != NULL)
        {
            size++;
            current = current->next;
        }

        return size;
    }
};

#endif
