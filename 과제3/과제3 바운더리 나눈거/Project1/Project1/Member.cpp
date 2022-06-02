#include "Member.h"
#include "Product.h"

ofstream* Member::out_fp;
vector<Member*>* Member::wholeMemberVector;

Member::Member(ofstream* fp, vector<Member*>* memberVector)
{
	out_fp = fp;
	wholeMemberVector = memberVector;
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

vector<Product*>*  Member::getSellingProductVector()
{
	return &sellingProductVector;
}

vector<Product*>*  Member::getSoldOutProductVector()
{
	return &soldOutProductVector;
}
vector<Product*>*  Member::getBoughtProductVector()
{
	return &boughtProductVector;
}





void Member::boughtProductList()
{
	if (boughtProductVector.size() == 0)
	{
		(*out_fp) << "> " << "구매한 상품이 없습니다.\n\n";
		//cout<< "> " << "구매한 상품이 없습니다.\n\n";
	}
	else
	{
		for (int i = 0; i < boughtProductVector.size(); i++)
		{
			Product* nowLookingProduct = boughtProductVector[i];
			nowLookingProduct->printBoughtProducts();
		}
		(*out_fp) << "\n";
		//cout << "\n";
	}
}

void Member::registerProduct(string productName, string madeCompanyName, int productPrice, int productQuantity)
{
	Product* newProduct = new Product(this,productName, madeCompanyName, productPrice, productQuantity);
	sellingProductVector.push_back(newProduct);

	//(*out_fp) << "3.1. 판매 의류 등록\n> " << productName << " " << madeCompanyName << " " << productPrice << " " << productQuantity << "\n\n";
	//cout << "3.1. 판매 의류 등록\n> " << productName << " " << madeCompanyName << " " << productPrice << " " << productQuantity << "\n\n";

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
		//cout<< "4.4. 상품 구매만족도 평가\n> 일치하는 상품이 없습니다\n\n";
	}
	else
	{
		evaluatingProduct->evaluateSatisfaction(evaluateNum);
		(*out_fp) << "4.4. 상품 구매만족도 평가\n> " << evaluatingProduct->getSellingMember()->getMemberName() << " " << evaluatingProduct->getProductName() << " " << evaluatingProduct->getAverageSatisfaction()
			<< "\n\n";

		//cout << "4.4. 상품 구매만족도 평가\n> " << evaluatingProduct->getSellingMember()->getMemberName() << " " << evaluatingProduct->getProductName() << " " << evaluatingProduct->getAverageSatisfaction()
		//	<< "\n\n";
	}
}

void Member::printSelledProductStatistics()
{
	(*out_fp) << "5.1. 판매 상품 통계\n";
	//cout << "5.1. 판매 상품 통계\n";
	if (soldOutProductVector.size() == 0 && sellingProductVector.size()==0)
	{
		(*out_fp) << "> 판매된 상품이 없습니다\n";
		//cout << "> 판매된 상품이 없습니다\n";
	}
	else
	{
		for (int i = 0; i < soldOutProductVector.size(); i++)
		{
			Product* nowLookingProduct = soldOutProductVector[i];
			nowLookingProduct->printStatistics();
		}
		for (int i = 0; i < sellingProductVector.size(); i++)
		{
			Product* nowLookingProduct = sellingProductVector[i];
			if (nowLookingProduct->getSelledProductQuantity() == 0) {
				continue;
			}
			nowLookingProduct->printStatistics();
		}
	}
	(*out_fp) <<"\n";
	//cout << "\n";

}

/*
 함수 이름 : inquirySoldProductList
 기능 : 판매 완료된 상품 조회
 매개변수 : 없음
 반환값 : 없음
*/
void Member::inquirySoldProductList()
{
	(*out_fp) << "3.3. 판매 완료 상품 조회\n";
	//cout << "3.3. 판매 완료 상품 조회\n";

	if (soldOutProductVector.size() == 0)
	{
		(*out_fp) << "> 판매 완료된 상품이 없습니다.\n";
		//cout << "> 판매 완료된 상품이 없습니다.\n";
	}
	else
	{
		for (int i = 0; i < soldOutProductVector.size(); i++)
		{
			Product* nowLookingProduct = soldOutProductVector[i];
			nowLookingProduct->printSoldProductList();
		}
	}
	(*out_fp) << "\n";
	//cout << "\n";
}

/*
 함수 이름 : searchProductDetail
 기능 : 상품 정보 검색 기능
 매개변수 : 없음
 반환값 : 없음
*/
void Member::searchProductDetail(string productName)
{
	searchingProduct = NULL;
	for (int j = 0; j < (*wholeMemberVector).size(); j++) 
	{
		for (int i = 0; i < (*wholeMemberVector)[j]->sellingProductVector.size(); i++)  //모든 상품을 베이스로 searching 해야 하는데.... product에 선언하면... 어떻게 풀어야 할지 모르겠음
		{
			Product* nowLookingProduct = (*wholeMemberVector)[j]->sellingProductVector[i];
			if (nowLookingProduct->getProductName().compare(productName) == 0)
			{
				if (nowLookingProduct->getNowSelling() == true){
					searchingProduct = nowLookingProduct;
					break;
				}
			}
		}
		if (searchingProduct != NULL) 
		{
			break;
		}
	}
	if (searchingProduct == NULL)
	{
		(*out_fp) << "4.1. 상품 정보 검색\n> 일치하는 상품이 없습니다\n\n";
		//cout << "4.1. 상품 정보 검색\n> 일치하는 상품이 없습니다\n\n";
	}
	else
	{
		(*out_fp) << "4.1. 상품 정보 검색\n> " << searchingProduct->getSellingMember()->getMemberID() << " " << searchingProduct->getProductName() << " "
			<< searchingProduct->getmadeCompanyName() << " " << searchingProduct->getproductPrice() << " " << searchingProduct->remainProductQuantity() << " " << searchingProduct->getAverageSatisfaction() << "\n\n";

		//cout << "4.1. 상품 정보 검색\n> " << searchingProduct->getSellingMember()->getMemberID() << " " << searchingProduct->getProductName() << " "
			//<< searchingProduct->getmadeCompanyName() << " " << searchingProduct->getproductPrice() << " " << searchingProduct->remainProductQuantity() << " " << searchingProduct->getAverageSatisfaction() << "\n\n";
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
		//cout << "4.2. 상품 구매\n> 상품을 검색하세요\n\n";
	}
	else
	{
		if (searchingProduct->getNowSelling() == false) 
		{
			(*out_fp) << "4.2. 상품 구매\n> 판매가 중지된 상품입니다.\n\n";
			//cout << "4.2. 상품 구매\n> 판매가 중지된 상품입니다.\n\n";
		}
		else {
			(*out_fp) << "4.2. 상품 구매\n> " << searchingProduct->getSellingMember()->getMemberID() << " " << searchingProduct->getProductName() << "\n\n";
			//cout << "4.2. 상품 구매\n> " << searchingProduct->getSellingMember()->getMemberID() << " " << searchingProduct->getProductName() << "\n\n";
			searchingProduct->buyProduct();
			
			boughtProductVector.push_back(searchingProduct);
			searchingProduct = NULL;
		}

	}


}

void Member::productSoldOut(Product* product)
{
	auto soldOutProduct = find(sellingProductVector.begin(), sellingProductVector.end(), product);
	if (soldOutProduct != sellingProductVector.end())
	{
		//cout << product->getProductName() << "은 다팔렸어용\n\n";
		sellingProductVector.erase(soldOutProduct);
		soldOutProductVector.push_back(product);
	}
}

void Member::deleteMemory() {
	int sellSize = sellingProductVector.size();
	int soldSize = soldOutProductVector.size();
	for (int i = 0; i < sellSize; i++) {
		delete sellingProductVector[i];
	}
	for (int i = 0; i < soldSize; i++) {
		delete soldOutProductVector[i];
	}
}