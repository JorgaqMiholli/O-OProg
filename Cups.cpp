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

int main()
{
    return 0;
}