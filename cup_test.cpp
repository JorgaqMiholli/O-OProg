#include <cassert>
#include <iostream>
#include "Cups.cpp"


void test_incorrect_inputs()
{

    try{
        Cup cupNegative("Medium", "Plastic", -1);
        assert(false);
    }
    catch (const std::invalid_argument& e){
        std::cout << "Caught an exception: " << e.what() << std::endl;
        assert(std::string(e.what()) == "Quantity cannot be negative");
    }


    try{
        Cup cupEmptySize("", "Plastic", 1);
        assert(false);
    }
    catch (const std::invalid_argument& e){
        std::cout << "Caught an exception: " << e.what() << std::endl;
        assert(std::string(e.what()) == "Size cannot be empty");
    }


    try{
        Cup cupEmptyMaterial("Medium", "", 1);
        assert(false);
    }
    catch (const std::invalid_argument& e){
        std::cout << "Caught an exception: " << e.what() << std::endl;
        assert(std::string(e.what()) == "Material cannot be empty");
    }




    try{
        TeaCup teaCupNegativeTime("Medium", "Glass", 1, -1);
        assert(false);
    }
    catch (const std::invalid_argument& e)
    {
        std::cout << "Caught an exception: " << e.what() << std::endl;
        assert(std::string(e.what()) == "Cleaning time cannot be negative");
    }


    try{
        BeerCup beerCupNegativeCapacity("Medium", "Plastic", 1, -1);
        assert(false);
    }
    catch (const std::invalid_argument& e){
        std::cout << "Caught an exception: " << e.what() << std::endl;

        assert(std::string(e.what()) == "Capacity cannot be negative");
    }
}



void test_cup(){
    Cup cup("Medium", "Plastic", 2);
    cup.fill();
    cup.clean();

    assert(cup.getSize() == "Medium");
    assert(cup.getMaterial() == "Plastic");
    assert(cup.getQuantity() == 2);


    // Test with different sizes and materials
    Cup cupLarge("Large", "Ceramic", 1);
    cupLarge.fill();
    cupLarge.clean();
    assert(cupLarge.getSize() == "Large");
    assert(cupLarge.getMaterial() == "Ceramic");
    assert(cupLarge.getQuantity() == 1);

    // Test filling multiple times
    Cup cupMultipleFill("Small", "Glass", 1);
    cupMultipleFill.fill();
    cupMultipleFill.fill();
    cupMultipleFill.clean();
    assert(cupMultipleFill.getSize() == "Small");
    assert(cupMultipleFill.getMaterial() == "Glass");
    assert(cupMultipleFill.getQuantity() == 1);

    // Test cleaning multiple times
    Cup cupMultipleClean("Medium", "Plastic", 1);
    cupMultipleClean.fill();
    cupMultipleClean.clean();
    cupMultipleClean.clean();
    assert(cupMultipleClean.getSize() == "Medium");
    assert(cupMultipleClean.getMaterial() == "Plastic");
    assert(cupMultipleClean.getQuantity() == 1);




}

void test_coffee_cup(){
    // Coffee cup
    CoffeeCup coffeeCup("Large", "Ceramic", 5);
    coffeeCup.fill();
    coffeeCup.clean();

    assert(coffeeCup.getSize() == "Large");
    assert(coffeeCup.getMaterial() == "Ceramic");
    assert(coffeeCup.getQuantity() == 5);

    // Test dishwasher limit
    CoffeeCup coffeeCup1("Large", "Ceramic", 15);
    coffeeCup1.fill();
    coffeeCup1.clean();

    CoffeeCup coffeeCup2("Medium", "Ceramic", 10);
    coffeeCup2.fill();
    coffeeCup2.clean();



    // Test dishwasher count
    assert(CoffeeCup::getDishwasherCount() == 20);

    // Test cleaning process
    CoffeeCup coffeeCup3("Small", "Ceramic", 1);
    coffeeCup3.fill();
    coffeeCup3.clean();
}



void test_tea_cup(){
    TeaCup teaCup("Medium", "Glass", 8, 5);
    teaCup.fill();
    teaCup.clean();

    assert(teaCup.getSize() == "Medium");
    assert(teaCup.getMaterial() == "Glass");
    assert(teaCup.getQuantity() == 8);

    // Test with different cleaning times
    TeaCup teaCupFast("Small", "Glass", 1, 2);
    teaCupFast.fill();
    teaCupFast.clean();
    assert(teaCupFast.getSize() == "Small");
    assert(teaCupFast.getMaterial() == "Glass");
    assert(teaCupFast.getQuantity() == 1);
}

void test_beer_cup(){
    BeerCup beerCup("Small", "Plastic", 20, 250);
    beerCup.fill();
    beerCup.empty();
    beerCup.clean();

    assert(beerCup.getSize() == "Small");
    assert(beerCup.getMaterial() == "Plastic");
    assert(beerCup.getQuantity() == 20);

    // Test with different capacities
    BeerCup beerCupLarge("Large", "Glass", 1, 500);
    beerCupLarge.fill();
    beerCupLarge.empty();
    beerCupLarge.clean();
    assert(beerCupLarge.getSize() == "Large");
    assert(beerCupLarge.getMaterial() == "Glass");
    assert(beerCupLarge.getQuantity() == 1);

    // Test filling multiple times
    BeerCup beerCupMultiple("Medium", "Plastic", 1, 100);
    beerCupMultiple.fill();
    beerCupMultiple.fill();
    beerCupMultiple.empty();
    beerCupMultiple.clean();
    assert(beerCupMultiple.getSize() == "Medium");
    assert(beerCupMultiple.getMaterial() == "Plastic");
    assert(beerCupMultiple.getQuantity() == 1);

}



int main(){
    test_incorrect_inputs();
    std::cout << "Incorrect input tests passed.";
    std::cout << "\n\n";


    std::cout << "Testing Cup class:\n";
    test_cup();
    std::cout << "Cup class tests passed.";
    std::cout << "\n\n";

    std::cout << "\nTesting CoffeeCup class:\n";
    test_coffee_cup();
    std::cout << "CoffeeCup class tests passed.";
    std::cout <<"\n\n";

    std::cout << "\nTesting TeaCup class:\n";
    test_tea_cup();
    std::cout << "TeaCup class tests passed.";
    std::cout << "\n\n";

    std::cout << "\nTesting BeerCup class:\n";
    test_beer_cup();
    std::cout << "\n";
    std::cout << "BeerCup class tests passed.";
    std::cout << "\n\n";

    return 0;
}