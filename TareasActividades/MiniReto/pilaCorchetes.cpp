#include <iostream>
using namespace std;


template <class T>
class Node
{
public:
    T data;
    Node<T>* next;
    Node(T dataValue) {
        data = dataValue;
        next = nullptr;
    }

};

template <class T>
class Stack
{
public:
    Node<T>* top;
    int size = 0;
    
    Stack() {
        top = nullptr;
        size = 0;
    }
    ~Stack() {
        while (top != nullptr) {
            Node<T>* temp = top;
            top = top->next;
            delete temp;
        }
    }
    int isEmpty() {
        if (top == nullptr)
            return 1;
        return 0;
    }


    /*
    Añade  T value a la lista
    @Param T value: elemento añadir del tipo T T
    */
    void push(T value) {
        size++;
        Node<T>* new_node = new Node<T>(value);
        if (top == nullptr) {
            top = new_node;
        }
        else {
            Node<T>* current = top;
            new_node->next = top;
            top = new_node;
        }
    }
    void pop()
    {
        if (size == 0) {
            return;
        }

        if (top == nullptr) {
            return;
        }
        else {
            Node<T> *temp = top;
            top = top->next;
            delete  temp;
            size--;
        }
    }
    T peek()
    {
        if (size == 0) {
            return NULL;
        }

        if (top == nullptr) {
            return NULL;
        }
        else {
            
            return  top->data;
        }
    }
};

int main() {
    string datos = "()()[][ [ [          ] ] ]";
    int largo = datos.length();
    Stack <char>miniReto;
    for(int i = 0; i < largo; i++) { 
        if(miniReto.top == datos[i])   
    }

}
/* 
void push(int sArray[], int& top, int value) {

    top++;
    sArray[top] = value;
}
void pop(int sArray[], int& top, int value) {
    if (top < 0) {
        return;
    }
    sArray[top] = 0;
    top--;
}
int peek(int sArray[], int top) {
    if (top < 0)
        return 1;
    return sArray[top];

}
void reverse(string& str, int start, int end)
{
    int n = end - start;
    
    // Intercambia por los extremos
    end--;
    for (int i = start; i < start+(n / 2); i++)
        swap(str[i], str[end - (i-start) ]);


} */