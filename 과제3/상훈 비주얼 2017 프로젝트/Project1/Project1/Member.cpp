#include "Member.h"
#include "Product.h"

ofstream* Member::out_fp;

Member::Member(ofstream* fp)
{
	out_fp = fp;
}

Member::Member(string name, string number, string id, string pwd)
{
	memberName = name;
	memberNumber = number;
	memberID = id;
	memberPWD = pwd;
}

string Member::getMemberName() {
	return memberName;
}
string Member::getMemberNumber() {
	return memberNumber;
}
string Member::getMemberID() {
	return memberID;
}
string Member::getMemberPWD() {
	return memberPWD;
}

void Member::myProductList()
{
	if (sellingProductVector.size() == 0)
	{
		(*out_fp) << "> " << "등록한 상품이 없습니다.\n\n";
	}
	else
	{
		int size = sellingProductVector.size();
		for (int i = 0; i <size; i++)
		{
			Product* nowLookingProduct = sellingProductVector[i];
			nowLookingProduct->printMyProducts();
		}
		(*out_fp) << "\n";
	}
}




void Member::boughtProductList()
{
	if (boughtProductVector.size() == 0)
	{
		(*out_fp) << "> " << "구매한 상품이 없습니다.\n\n";
	}
	else
	{
		for (int i = 0; i < boughtProductVector.size(); i++)
		{
			Product* nowLookingProduct = boughtProductVector[i];
			nowLookingProduct->printBoughtProducts();
		}
		(*out_fp) << "\n";
	}
}

void Member::registerProduct(string productName, string madeCompanyName, int productPrice, int productQuantity)
{
	Product* newProduct = new Product(productName, madeCompanyName, productPrice, productQuantity);
	sellingProductVector.push_back(newProduct);

	(*out_fp) << "3.1. 판매 의류 등록\n>" << productName << " " << madeCompanyName << " " << productPrice << " " << productQuantity << "\n\n";

}

void Member::evaluateSatisfaction(string productName, int evaluateNum)
{
	Product* evaluatingProduct = NULL;
	for (int i = 0; i < boughtProductVector.size(); i++)
	{
		Product* nowLookingProduct = boughtProductVector[i];
		if (nowLookingProduct->getProductName().compare(productName) == 0)
		{
			evaluatingProduct = nowLookingProduct;
			break;
		}
	}
	if (evaluatingProduct == NULL)
	{
		(*out_fp) << "4.4. 상품 구매만족도 평가\n> 일치하는 상품이 없습니다\n\n";
	}
	else
	{
		evaluatingProduct->evaluateSatisfaction(evaluateNum);
		(*out_fp) << "4.4. 상품 구매만족도 평가\n>" << evaluatingProduct->getSellingMember()->getMemberName() << " " << evaluatingProduct->getProductName() << " " << evaluatingProduct->getAverageSatisfaction()
			<< "\n\n";
	}
}

void Member::printSelledProductStatistics()
{
	(*out_fp) << "5.1. 판매 상품 통계\n>";
	if (selledProductVector.size() == 0)
	{
		(*out_fp) << "판매된 상품이 없습니다\n\n";
	}
	else
	{
		for (int i = 0; i < selledProductVector.size(); i++)
		{
			Product* nowLookingProduct = selledProductVector[i];
			nowLookingProduct->printStatistics();
		}
	}

}

/*
 함수 이름 : inquirySoldProductList
 기능 : 판매 완료된 상품 조회
 매개변수 : 없음
 반환값 : 없음
*/
void Member::inquirySoldProductList()
{
	(*out_fp) << "3.3. 판매 완료 상품 조회\n>";

	if (selledProductVector.size() == 0)
	{
		(*out_fp) << "> 판매 완료된 상품이 없습니다.\n\n";
	}
	else
	{
		for (int i = 0; i < selledProductVector.size(); i++)
		{
			Product* nowLookingProduct = selledProductVector[i];
			nowLookingProduct->printSoldProductList();
		}
	}

}

/*
 함수 이름 : searchProductDetail
 기능 : 상품 정보 검색 기능
 매개변수 : 없음
 반환값 : 없음
*/
void Member::searchProductDetail(string productName)
{
	Product* searchingProduct = NULL;
	for (int i = 0; i < sellingProductVector.size(); i++)  //모든 상품을 베이스로 searching 해야 하는데.... product에 선언하면... 어떻게 풀어야 할지 모르겠음
	{
		Product* nowLookingProduct = sellingProductVector[i];
		if (nowLookingProduct->getProductName().compare(productName) == 0)
		{
			searchingProduct = nowLookingProduct;
			break;
		}
	}
	if (searchingProduct == NULL)
	{
		(*out_fp) << "4.1. 상품 정보 검색\n> 상품을 검색해주세요\n\n";
	}
	else
	{
		(*out_fp) << "4.1. 상품 정보 검색\n> " << searchingProduct->getSellingMember()->getMemberID() << " " << searchingProduct->getProductName() << " "
			<< searchingProduct->getmadeCompanyName() << " " << searchingProduct->getproductPrice() << " " << searchingProduct->remainProductQuantity() << " " << searchingProduct->getAverageSatisfaction() << "\n\n";
	}
}

/*
 함수 이름 : purchaseProduct
 기능 : 상품 구매
 매개변수 : 없음
 반환값 : 없음
*/
void Member::purchaseProduct()
{
	if (searchingProduct == NULL)
	{
		(*out_fp) << "4.2. 상품 구매\n> 상품을 검색하세요\n\n";
	}
	else
	{
		(*out_fp) << "4.2. 상품 구매\n> " << searchingProduct->getSellingMember()->getMemberID() << " " << searchingProduct->getProductName() << "\n\n";
	}


}