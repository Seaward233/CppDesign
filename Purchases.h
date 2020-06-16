#pragma once
class Purchases
{
public:
    Purchases(void);
    ~Purchases(void);
    unsigned int id;
    unsigned int priority;
    unsigned long int quantity;
    string ISBN;
    string detail;
};
