#include <iostream>
#include <string>

class Cup {
protected:
    std::string size;
    std::string material;
    int quantity;

public:
    Cup(std::string s, std::string m, int q) : size(s), material(m), quantity(q) {}

    std::string getSize() const { return size; }
    std::string getMaterial() const { return material; }
    int getQuantity() const { return quantity; }
    void setQuantity(int q) { quantity = q; }

    virtual void fill() const {
        std::cout << "Filling a cup made of " << material << " with size " << size << ".\n";
    }

    virtual void clean() const {
        std::cout << "Cleaning " << quantity << " cups made of " << material << " with size " << size << " by hand using hot water.\n";
    }
};

class CoffeeCup : public Cup {
private:
    static int dishwasherLimit;
    static int dishwasherCount;

public:
    CoffeeCup(std::string s, std::string m, int q) : Cup(s, m, q) {}

    void fill() const override {
        std::cout << "Filling a coffee cup made of " << material << " with size " << size << ".\n";
    }

    void clean() const override {
        if (dishwasherCount + quantity <= dishwasherLimit) {
            std::cout << "Cleaning " << quantity << " coffee cups made of " << material << " with size " << size << " using dishwasher.\n";
            dishwasherCount += quantity;
        } else {
            int canClean = dishwasherLimit - dishwasherCount;
            int remaining = quantity - canClean;
            std::cout << "Cleaning " << canClean << " coffee cups made of " << material << " with size " << size << " using dishwasher.\n";
            std::cout << remaining << " coffee cups will wait for the next dishwasher load.\n";
            dishwasherCount = dishwasherLimit;
        }
        if (dishwasherCount >= dishwasherLimit) {
            std::cout << "Dishwasher is full! Please start the dishwasher." << std::endl;
        }
    }
};

int CoffeeCup::dishwasherLimit = 20;
int CoffeeCup::dishwasherCount = 0;


class TeaCup : public Cup {
private:
    static int cleanedCount;
    int cleaningTime;

public:
    TeaCup(std::string s, std::string m, int q, int time) : Cup(s, m, q), cleaningTime(time) {}

    void fill() const override {
        std::cout << "Filling a tea cup made of " << material << " with size " << size << ".\n";
    }

    void clean() const override {
        std::cout << "Cleaning " << quantity << " tea cups made of " << material << " with size " << size << " by hand using hot water for " << cleaningTime << " minutes each.\n";
        cleanedCount += quantity;
        std::cout << "Total tea cups cleaned by hand: " << cleanedCount << std::endl;
    }
};

int TeaCup::cleanedCount = 0;


class BeerCup : public Cup {
private:
    int capacity;
    mutable int currentVolume;

public:
    BeerCup(std::string s, std::string m, int q, int cap) : Cup(s, m, q), capacity(cap), currentVolume(0) {}

    void fill() const override {
        while(currentVolume < capacity) {
            currentVolume += 50;
            std::cout << "Adding 50 ml of beer. Current volume: " << currentVolume << " ml.\n";
            if(currentVolume >= capacity) {
                std::cout << "The cup now is full.Ready to be served.\n";
                break;
            }
        }
    }

    void empty() {
        currentVolume = 0;
        std::cout << "Now, the cup is empty.\n";
    }

    void clean() const override {
        std::cout << "Throwing away " << quantity << " beer cups made of " << material << " with size " << size << " because they're made of plastic.\n";
    }
};


int main()
{
    CoffeeCup coffeeCup("Large", "Ceramic", 5);
    TeaCup teaCup1("Medium", "Glass", 8, 5);
    TeaCup teaCup2("Small", "Porcelain", 5, 3);
    BeerCup beerCup("Small", "Plastic", 20, 250);

    coffeeCup.fill();
    coffeeCup.clean();

    teaCup1.fill();
    teaCup1.clean();

    teaCup2.fill();
    teaCup2.clean();

    beerCup.fill();
    beerCup.empty();
    beerCup.clean();

    return 0;
}