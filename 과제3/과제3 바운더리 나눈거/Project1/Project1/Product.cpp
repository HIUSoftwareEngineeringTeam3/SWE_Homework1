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




void Product::evaluateSatisfaction(int evaluateNum)
{
	satisfactionNumber += evaluateNum;
	satisfactionQuantity++;
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
 함수 이름 : remainProductQuantity
 기능 : 남은 수량 리턴
 매개변수 : 없음
 반환값 : int productQuantity - selledProductQuantity
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