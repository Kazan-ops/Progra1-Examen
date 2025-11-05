#include "PizzaBuilder.h"
#include <iostream>

int main() {
    try {
        PizzaBuilder builder;

        builder.BuildPizza();
        builder.DisplayFinalPizza();

    } catch (const std::exception& ex) {
        std::cerr << "Fatal error: " << ex.what() << std::endl;                
        return 1;
    }

    system("pause");
    return 0;
}