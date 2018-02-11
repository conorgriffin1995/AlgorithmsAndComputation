#pragma once
#include "Product.h"

// X00111602
// Conor Griffin

class Software : public Product {
public:
	Software();
	Software(double netPriceIn);
private:
	double price;
};