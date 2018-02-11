#pragma once
#include "Product.h"

// X00111602
// Conor Griffin

class Book : public Product
{
public:
	Book();
	Book(double netPriceIn);
	double getGrossPrice();
private:
	double price;
};

