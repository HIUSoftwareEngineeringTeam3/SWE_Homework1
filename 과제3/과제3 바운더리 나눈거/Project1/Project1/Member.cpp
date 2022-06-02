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






void Member::registerProduct(string productName, string madeCompanyName, int productPrice, int productQuantity)
{
	Product* newProduct = new Product(this,productName, madeCompanyName, productPrice, productQuantity);
	sellingProductVector.push_back(newProduct);

	//(*out_fp) << "3.1. 판매 의류 등록\n> " << productName << " " << madeCompanyName << " " << productPrice << " " << productQuantity << "\n\n";
	//cout << "3.1. 판매 의류 등록\n> " << productName << " " << madeCompanyName << " " << productPrice << " " << productQuantity << "\n\n";

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