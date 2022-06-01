#include "Member.h"
#include "Product.h"

ofstream* Product::out_fp;

Product::Product(ofstream* fp)
{
	out_fp = fp;
}

Product::Product(Member* seller,string pName, string companyName, int price, int quantity)
{
	sellingMember = seller;
	productName = pName;
	madeCompanyName = companyName;
	productPrice = price;
	productQuantity = quantity;
	selledProductQuantity = 0;
	satisfactionNumber = 0;
	satisfactionQuantity = 0;
	if (quantity > 0) {
		nowSelling = true;
	}
	else {
		nowSelling = false;
	}
	
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
	cout << "> " << productName << " " << madeCompanyName << " " << productPrice << " " << productQuantity << "\n";
}

void Product::printBoughtProducts()
{
	(*out_fp) << "> " << getSellingMember()->getMemberID() << " " << productName << " " << madeCompanyName << " " << productPrice << " " << remainProductQuantity() << " ";
	cout << "> " << getSellingMember()->getMemberID() << " " << productName << " " << madeCompanyName << " " << productPrice << " " << remainProductQuantity() << " ";
	if (satisfactionQuantity == 0) {
		(*out_fp) << "�򰡵��� ����";
		cout << "�򰡵��� ����";
	}
	else {
		(*out_fp) << getAverageSatisfaction();
		cout << getAverageSatisfaction();
	}
	(*out_fp) << "\n";
	cout << "\n";
}

void Product::evaluateSatisfaction(int evaluateNum)
{
	satisfactionNumber += evaluateNum;
	satisfactionQuantity++;
}

void Product::printStatistics()
{
	(*out_fp)<< "> " << productName << " " << selledProductQuantity * productPrice << " ";
	cout<<"> " << productName << " " << selledProductQuantity * productPrice << " ";
	if (satisfactionQuantity == 0) {
		(*out_fp) << "�򰡵��� ����";
		cout << "�򰡵��� ����";
	}
	else {
		(*out_fp) << getAverageSatisfaction();
		cout << getAverageSatisfaction();
	}
	(*out_fp) << "\n";
	cout << "\n";
}

float Product::getAverageSatisfaction()
{
	if (satisfactionQuantity == 0)
	{
		return 0;
	}
	float avg = (float)satisfactionNumber / (float)satisfactionQuantity;
	avg *= 10;
	avg = round(avg);
	avg /= 10;
	return avg;
}

/*
 �Լ� �̸� : inquirySoldProductList
 ��� : �Ǹ� �Ϸ�� ��ǰ ��ȸ
 �Ű����� : ����
 ��ȯ�� : ����
*/
void Product::printSoldProductList()
{
	(*out_fp) << "> " << getProductName() << " " << getmadeCompanyName() << " " << getproductPrice() << " " << selledProductQuantity << " " << getAverageSatisfaction();

	(*out_fp) << "\n";

	cout << "> " << getProductName() << " " << getmadeCompanyName() << " " << getproductPrice() << " " << selledProductQuantity << " " << getAverageSatisfaction();

	cout << "\n";
}

/*
 �Լ� �̸� : remainProductQuantity
 ��� : ���� ���� ����
 �Ű����� : ����
 ��ȯ�� : int productQuantity - selledProductQuantity
*/
int Product::remainProductQuantity()
{
	return productQuantity - selledProductQuantity;
}

void Product::buyProduct() 
{
	selledProductQuantity++;
	if (remainProductQuantity() <= 0) 
	{
		nowSelling = false;
		sellingMember->productSoldOut(this);
	}
}

bool Product::getNowSelling() {
	return nowSelling;
}

int Product::getSelledProductQuantity() {
	return selledProductQuantity;
}