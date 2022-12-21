#include <iostream>
#include "MyArray.h"
#include <ctime>
#include <cstdlib>


int main() {
    
    MyArrayExtend my_array;
    

    srand(time(NULL));


    for(double i = 0; i < 10; i++){
        my_array.addElement(rand() % 100);
    }

    my_array.printm();
    my_array.sort(); 
    my_array.printm();
    my_array.find(10); 

    std::cout << my_array.max() << std::endl;
    std::cout << my_array.min() << std::endl;


    return 0;   
}
