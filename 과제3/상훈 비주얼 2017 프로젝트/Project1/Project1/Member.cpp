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
		(*out_fp) << "> " << "����� ��ǰ�� �����ϴ�.\n\n";
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
		(*out_fp) << "> " << "������ ��ǰ�� �����ϴ�.\n\n";
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

	(*out_fp) << "3.1. �Ǹ� �Ƿ� ���\n>" << productName << " " << madeCompanyName << " " << productPrice << " " << productQuantity << "\n\n";

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
	}
	else
	{
		evaluatingProduct->evaluateSatisfaction(evaluateNum);
		(*out_fp) << "4.4. ��ǰ ���Ÿ����� ��\n>" << evaluatingProduct->getSellingMember()->getMemberName() << " " << evaluatingProduct->getProductName() << " " << evaluatingProduct->getAverageSatisfaction()
			<< "\n\n";
	}
}

void Member::printSelledProductStatistics()
{
	(*out_fp) << "5.1. �Ǹ� ��ǰ ���\n>";
	if (selledProductVector.size() == 0)
	{
		(*out_fp) << "�Ǹŵ� ��ǰ�� �����ϴ�\n\n";
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
 �Լ� �̸� : inquirySoldProductList
 ��� : �Ǹ� �Ϸ�� ��ǰ ��ȸ
 �Ű����� : ����
 ��ȯ�� : ����
*/
void Member::inquirySoldProductList()
{
	(*out_fp) << "3.3. �Ǹ� �Ϸ� ��ǰ ��ȸ\n>";

	if (selledProductVector.size() == 0)
	{
		(*out_fp) << "> �Ǹ� �Ϸ�� ��ǰ�� �����ϴ�.\n\n";
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
 �Լ� �̸� : searchProductDetail
 ��� : ��ǰ ���� �˻� ���
 �Ű����� : ����
 ��ȯ�� : ����
*/
void Member::searchProductDetail(string productName)
{
	Product* searchingProduct = NULL;
	for (int i = 0; i < sellingProductVector.size(); i++)  //��� ��ǰ�� ���̽��� searching �ؾ� �ϴµ�.... product�� �����ϸ�... ��� Ǯ��� ���� �𸣰���
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
		(*out_fp) << "4.1. ��ǰ ���� �˻�\n> ��ǰ�� �˻����ּ���\n\n";
	}
	else
	{
		(*out_fp) << "4.1. ��ǰ ���� �˻�\n> " << searchingProduct->getSellingMember()->getMemberID() << " " << searchingProduct->getProductName() << " "
			<< searchingProduct->getmadeCompanyName() << " " << searchingProduct->getproductPrice() << " " << searchingProduct->remainProductQuantity() << " " << searchingProduct->getAverageSatisfaction() << "\n\n";
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
	}
	else
	{
		(*out_fp) << "4.2. ��ǰ ����\n> " << searchingProduct->getSellingMember()->getMemberID() << " " << searchingProduct->getProductName() << "\n\n";
	}


}