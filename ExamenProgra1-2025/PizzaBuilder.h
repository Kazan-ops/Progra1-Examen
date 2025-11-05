#pragma once
#include <vector>
#include <string>
#include "TomatoesRepository.h"

class PizzaBuilder {
public:
    PizzaBuilder();

    void BuildPizza();
    void DisplayFinalPizza() const;

private:
    void DisplayAvailableTomatoes();
    bool AddTomatoToPizza(const std::string& tomatoType);

    TomatoesRepository tomatoRepo_;
    std::vector<std::string> selectedIngredients_;
    const std::vector<std::string> availableTomatoes_ = {"Cherry", "Roma", "Beefsteak", "Heirloom", "Grape"};
};