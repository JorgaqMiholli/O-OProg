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
};