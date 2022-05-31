#include "Product.h"

Product::Product(ofstream* fp)
{
	out_fp = fp;
}

Product::Product(string pName, string companyName, int price, int quantity) 
{
	productName = pName;
	madeCompanyName = companyName;
	productPrice = price;
	productQuantity = quantity;
	selledProductQuantity = 0;
	satisfactionNumber = 0;
	satisfactionQuantity = 0;
}

string Product::getProductName() 
{
	return productName;
}

Member* Product::getSellingMember() 
{
	return sellingMember;
}

void Product::evaluateSatisfaction(int evaluateNum) 
{
	satisfactionNumber += evaluateNum;
	satisfactionQuantity++;
}

void Product::printStatistics() 
{
	(*out_fp) << productName << " " << selledProductQuantity * productPrice << " ";
	if (satisfactionQuantity == 0) {
		(*out_fp) << "평가되지 않음";
	}
	else {
		(*out_fp) << getAverageSatisfaction();
	}
	(*out_fp) << "\n\n";
}

float Product::getAverageSatisfaction()
{
	if (satisfactionQuantity == 0) 
	{
		return -1;
	}
	return satisfactionNumber / satisfactionQuantity;
}