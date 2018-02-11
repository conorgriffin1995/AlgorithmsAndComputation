#include "Book.h"

// X00111602
// Conor Griffin

Book::Book()
{
}

Book::Book(double netPriceIn) : Product(netPriceIn) {
	price = netPriceIn;
}

double Book::getGrossPrice() {
	return price;
}

