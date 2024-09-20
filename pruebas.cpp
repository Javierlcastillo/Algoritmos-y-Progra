#include <iostream>
using namespace std;

template <class T>
void intercambia (T *a, T *b){
	T tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int main(){
    int a = 5;
    int b = 3;
    intercambia(&a,&b);
    cout << a << endl << b;
}

