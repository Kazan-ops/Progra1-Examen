#pragma once
#include <vector>
#include <string>
#include "TomatoesRepository.h"
#include "HerbsRepository.h"
#include "IngredientSelector.h"
#include "MeatsRepository.h"

#include "CheeseRepository.h"

class PizzaBuilder {
public:
    PizzaBuilder();

    void BuildPizza();
    void DisplayFinalPizza() const;

private:
    void SelectTomatoes();
    void SelectCheese();
    void SelectHerb();
    void SelectMeat();

    TomatoesRepository tomatoRepo_;
    MeatsRepository meatRepo_;
	HerbsRepository herbRepo_;
	CheeseRepository cheeseRepo_;
    std::vector<std::string> selectedIngredients_;

    


    const std::vector<std::string> availableTomatoes_ = {"Cherry", "Roma", "Beefsteak", "Heirloom", "Grape"};
    const std::vector<std::string> availableCheeses_ = {"Mozzarella", "Cheddar", "Parmesan", "Cream Cheese", "Gouda", "Blue Cheese", "Feta"};
    const std::vector<std::string> availableMeat_ = { "Pepperoni", "Bacon", "Chicken", "Shrimp", "Mignon", "Ham", "Sausage", "Prosciutto" };
	const std::vector<std::string> availableHerbs_ = { "Basil", "Oregano", "Rosemary", "Thyme", "Parsley", "Cilantro", "Chives" };

};