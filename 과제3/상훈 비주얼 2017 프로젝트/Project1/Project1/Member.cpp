#include "Member.h"

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

void Member::registerProduct(string productName, string madeCompanyName, int productPrice, int productQuantity)
{
	Product* newProduct = new Product(productName, madeCompanyName, productPrice, productQuantity);
	sellingProductVector.push_back(newProduct);
	
	(*out_fp) << "3.1. �Ǹ� �Ƿ� ���\n>" << productName << " " << madeCompanyName << " " << productPrice << " " << productQuantity << "\n\n";
		
}

void Member::evaluateSatisfaction(string productName, int evaluateNum) 
{
	Product* evaluatingProduct = NULL;
	for (int i = 0; i < boughtProductVector.size; i++)
	{
		Product* nowLookingProduct = boughtProductVector[i];
		if (nowLookingProduct->getProductName().compare(productName)==0)
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
		(*out_fp) << "4.4. ��ǰ ���Ÿ����� ��\n>" << evaluatingProduct->getSellingMember()->getMemberName() << " " << evaluatingProduct->getProductName << " " << evaluatingProduct->getAverageSatisfaction
			<< "\n\n";
	}
}

void Member::printSelledProductStatistics() 
{
	(*out_fp) << "5.1. �Ǹ� ��ǰ ���\n>";
	if (selledProductVector.size == 0) 
	{
		(*out_fp) << "�Ǹŵ� ��ǰ�� �����ϴ�\n\n";
	}
	else 
	{
		for (int i = 0; i < selledProductVector.size; i++)
		{
			Product* nowLookingProduct = selledProductVector[i];
			nowLookingProduct->printStatistics();
		}
	}
	
}