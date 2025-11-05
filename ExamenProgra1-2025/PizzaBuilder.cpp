#include "PizzaBuilder.h"
#include <iostream>

PizzaBuilder::PizzaBuilder() {
}

void PizzaBuilder::BuildPizza() {
    std::cout << "=== Pizza Builder ===" << std::endl;
    std::cout << "Let's build your pizza!" << std::endl;

    while (true) {
        DisplayAvailableTomatoes();

        std::cout << "\nEnter tomato type (or 'done' to finish): ";
        std::string userChoice;
        std::getline(std::cin, userChoice);

        if (userChoice == "done" || userChoice == "DONE") {
            break;
        }

        AddTomatoToPizza(userChoice);
    }
}

void PizzaBuilder::DisplayFinalPizza() const {
    std::cout << "\n=== Your Pizza ===" << std::endl;
    if (selectedIngredients_.empty()) {
        std::cout << "No ingredients selected." << std::endl;
    } else {
        std::cout << "Your pizza contains:" << std::endl;
        for (const auto& ingredient : selectedIngredients_) {
            std::cout << "- " << ingredient << std::endl;
        }
    }
}

void PizzaBuilder::DisplayAvailableTomatoes() {
    std::cout << "\nAvailable tomato types:" << std::endl;
    for (const auto& tomato : availableTomatoes_) {
        try {
            int quantity = tomatoRepo_.GetAvailableQuantity(tomato);
            std::cout << "- " << tomato << " (Available: " << quantity << ")" << std::endl;
        } catch (const std::invalid_argument&) {
            std::cout << "- " << tomato << " (Not available)" << std::endl;
        }
    }
}

bool PizzaBuilder::AddTomatoToPizza(const std::string& tomatoType) {
    try {
        int quantity = tomatoRepo_.GetAvailableQuantity(tomatoType);
        if (quantity > 0) {
            selectedIngredients_.push_back(tomatoType);
            tomatoRepo_.UpdateQuantity(tomatoType, quantity - 1);
            std::cout << "Added " << tomatoType << " to your pizza!" << std::endl;
            return true;
        } else {
            std::cout << "Sorry, " << tomatoType << " tomato can't be added at this time. Please choose another one." << std::endl;
            return false;
        }
    } catch (const std::invalid_argument&) {
        std::cout << "Sorry, " << tomatoType << " is not a valid tomato type. Please choose from the available options." << std::endl;
        return false;
    }
}