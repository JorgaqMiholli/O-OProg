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

int main()
{
    return 0;
}