#include "Member.h"
#include "Product.h"
#include "MemberCollection.h"
#include "ProductCollection.h"

//Member::Member(ofstream* fp, vector<Member*>* memberVector)
//{
//	out_fp = fp;
//	wholeMemberVector = memberVector;
//}

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

//vector<Product*>*  Member::getSellingProductVector()
//{
//	return &sellingProductCollection;
//}
//
//vector<Product*>*  Member::getSoldOutProductVector()
//{
//	return &soldOutProdcutCollection;
//}
//vector<Product*>*  Member::getBoughtProductVector()
//{
//	return &boughtProductCollection;
//}
//

ProductCollection*  Member::getSellingProductCollection() {
	return &sellingProductCollection;
}
ProductCollection*  Member::getSoldOutProductCollection() {
	return &soldOutProductCollection;
}
ProductCollection*  Member::getBoughtProductCollection() {
	return &boughtProductCollection;
}





void Member::registerProduct(string productName, string madeCompanyName, int productPrice, int productQuantity)
{
	Product* newProduct = new Product(this,productName, madeCompanyName, productPrice, productQuantity);
	sellingProductCollection.pushProduct(newProduct);

	//(*out_fp) << "3.1. 판매 의류 등록\n> " << productName << " " << madeCompanyName << " " << productPrice << " " << productQuantity << "\n\n";
	//cout << "3.1. 판매 의류 등록\n> " << productName << " " << madeCompanyName << " " << productPrice << " " << productQuantity << "\n\n";

}



void Member::productSoldOut(Product* product)
{
	sellingProductCollection.eraseProdcut(product);
	soldOutProductCollection.pushProduct(product);
	//auto soldOutProduct = find(sellingProductCollection.begin(), sellingProductCollection.end(), product);
	//if (soldOutProduct != sellingProductCollection.end())
	//{
	//	//cout << product->getProductName() << "은 다팔렸어용\n\n";
	//	sellingProductCollection.erase(soldOutProduct);
	//	soldOutProdcutCollection.push_back(product);
	//}
}

void Member::deleteMemory() {
	sellingProductCollection.deleteMemory();
	soldOutProductCollection.deleteMemory();

}