#include "Product.h"

// X00111602
// Conor Griffin

Product::Product(){

}

Product::Product(double netPriceIn)
{
	price = netPriceIn;
}

double Product::getGrossPrice() {
	return price * 1.21;
}
