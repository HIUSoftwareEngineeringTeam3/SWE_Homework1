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
		(*out_fp) << "> " << "������ ��ǰ�� �����ϴ�.\n\n";
		//cout<< "> " << "������ ��ǰ�� �����ϴ�.\n\n";
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

	//(*out_fp) << "3.1. �Ǹ� �Ƿ� ���\n> " << productName << " " << madeCompanyName << " " << productPrice << " " << productQuantity << "\n\n";
	//cout << "3.1. �Ǹ� �Ƿ� ���\n> " << productName << " " << madeCompanyName << " " << productPrice << " " << productQuantity << "\n\n";

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
		(*out_fp) << "4.4. ��ǰ ���Ÿ����� ��\n> ��ġ�ϴ� ��ǰ�� �����ϴ�\n\n";
		//cout<< "4.4. ��ǰ ���Ÿ����� ��\n> ��ġ�ϴ� ��ǰ�� �����ϴ�\n\n";
	}
	else
	{
		evaluatingProduct->evaluateSatisfaction(evaluateNum);
		(*out_fp) << "4.4. ��ǰ ���Ÿ����� ��\n> " << evaluatingProduct->getSellingMember()->getMemberName() << " " << evaluatingProduct->getProductName() << " " << evaluatingProduct->getAverageSatisfaction()
			<< "\n\n";

		//cout << "4.4. ��ǰ ���Ÿ����� ��\n> " << evaluatingProduct->getSellingMember()->getMemberName() << " " << evaluatingProduct->getProductName() << " " << evaluatingProduct->getAverageSatisfaction()
		//	<< "\n\n";
	}
}

void Member::printSelledProductStatistics()
{
	(*out_fp) << "5.1. �Ǹ� ��ǰ ���\n";
	//cout << "5.1. �Ǹ� ��ǰ ���\n";
	if (soldOutProductVector.size() == 0 && sellingProductVector.size()==0)
	{
		(*out_fp) << "> �Ǹŵ� ��ǰ�� �����ϴ�\n";
		//cout << "> �Ǹŵ� ��ǰ�� �����ϴ�\n";
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
 �Լ� �̸� : inquirySoldProductList
 ��� : �Ǹ� �Ϸ�� ��ǰ ��ȸ
 �Ű����� : ����
 ��ȯ�� : ����
*/
void Member::inquirySoldProductList()
{
	(*out_fp) << "3.3. �Ǹ� �Ϸ� ��ǰ ��ȸ\n";
	//cout << "3.3. �Ǹ� �Ϸ� ��ǰ ��ȸ\n";

	if (soldOutProductVector.size() == 0)
	{
		(*out_fp) << "> �Ǹ� �Ϸ�� ��ǰ�� �����ϴ�.\n";
		//cout << "> �Ǹ� �Ϸ�� ��ǰ�� �����ϴ�.\n";
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
 �Լ� �̸� : searchProductDetail
 ��� : ��ǰ ���� �˻� ���
 �Ű����� : ����
 ��ȯ�� : ����
*/
void Member::searchProductDetail(string productName)
{
	searchingProduct = NULL;
	for (int j = 0; j < (*wholeMemberVector).size(); j++) 
	{
		for (int i = 0; i < (*wholeMemberVector)[j]->sellingProductVector.size(); i++)  //��� ��ǰ�� ���̽��� searching �ؾ� �ϴµ�.... product�� �����ϸ�... ��� Ǯ��� ���� �𸣰���
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
		(*out_fp) << "4.1. ��ǰ ���� �˻�\n> ��ġ�ϴ� ��ǰ�� �����ϴ�\n\n";
		//cout << "4.1. ��ǰ ���� �˻�\n> ��ġ�ϴ� ��ǰ�� �����ϴ�\n\n";
	}
	else
	{
		(*out_fp) << "4.1. ��ǰ ���� �˻�\n> " << searchingProduct->getSellingMember()->getMemberID() << " " << searchingProduct->getProductName() << " "
			<< searchingProduct->getmadeCompanyName() << " " << searchingProduct->getproductPrice() << " " << searchingProduct->remainProductQuantity() << " " << searchingProduct->getAverageSatisfaction() << "\n\n";

		//cout << "4.1. ��ǰ ���� �˻�\n> " << searchingProduct->getSellingMember()->getMemberID() << " " << searchingProduct->getProductName() << " "
			//<< searchingProduct->getmadeCompanyName() << " " << searchingProduct->getproductPrice() << " " << searchingProduct->remainProductQuantity() << " " << searchingProduct->getAverageSatisfaction() << "\n\n";
	}
}

/*
 �Լ� �̸� : purchaseProduct
 ��� : ��ǰ ����
 �Ű����� : ����
 ��ȯ�� : ����
*/
void Member::purchaseProduct()
{
	if (searchingProduct == NULL)
	{
		(*out_fp) << "4.2. ��ǰ ����\n> ��ǰ�� �˻��ϼ���\n\n";
		//cout << "4.2. ��ǰ ����\n> ��ǰ�� �˻��ϼ���\n\n";
	}
	else
	{
		if (searchingProduct->getNowSelling() == false) 
		{
			(*out_fp) << "4.2. ��ǰ ����\n> �ǸŰ� ������ ��ǰ�Դϴ�.\n\n";
			//cout << "4.2. ��ǰ ����\n> �ǸŰ� ������ ��ǰ�Դϴ�.\n\n";
		}
		else {
			(*out_fp) << "4.2. ��ǰ ����\n> " << searchingProduct->getSellingMember()->getMemberID() << " " << searchingProduct->getProductName() << "\n\n";
			//cout << "4.2. ��ǰ ����\n> " << searchingProduct->getSellingMember()->getMemberID() << " " << searchingProduct->getProductName() << "\n\n";
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
		//cout << product->getProductName() << "�� ���ȷȾ��\n\n";
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