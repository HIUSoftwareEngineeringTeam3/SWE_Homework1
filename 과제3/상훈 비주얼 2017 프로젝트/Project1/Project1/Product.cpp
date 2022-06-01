#include "Member.h"
#include "Product.h"

ofstream* Product::out_fp;

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
string Product::getmadeCompanyName()
{
	return madeCompanyName;
}
int Product::getproductPrice()
{
	return productPrice;
}
Member* Product::getSellingMember()
{
	return sellingMember;
}

void Product::printMyProducts()
{
	(*out_fp) << "> " << productName << " " << madeCompanyName << " " << productPrice << " " << productQuantity << "\n";
}

void Product::printBoughtProducts()
{
	(*out_fp) << "> " << getSellingMember() << " " << productName << " " << madeCompanyName << " " << productPrice << " " << productQuantity << " ";
	if (satisfactionQuantity == 0) {
		(*out_fp) << "평가되지 않음";
	}
	else {
		(*out_fp) << getAverageSatisfaction();
	}
	(*out_fp) << "\n";
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

/*
 함수 이름 : inquirySoldProductList
 기능 : 판매 완료된 상품 조회
 매개변수 : 없음
 반환값 : 없음
*/
void Product::printSoldProductList()
{
	(*out_fp) << "> " << getProductName() << " " << getmadeCompanyName() << " " << getproductPrice() << " " << selledProductQuantity << " " << getAverageSatisfaction();

	(*out_fp) << "\n\n";
}

/*
 함수 이름 : remainProductQuantity
 기능 : 남은 수량 리턴
 매개변수 : 없음
 반환값 : int productQuantity - selledProductQuantity
*/
int Product::remainProductQuantity()
{
	return productQuantity - selledProductQuantity;
}