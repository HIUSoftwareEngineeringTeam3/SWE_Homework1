#include "ProductSearch.h"
#include "ProductSearchUI.h"

ProductSearchUI::ProductSearchUI(ofstream* outfp, ifstream* infp,ProductSearch* controlClass) {
	out_fp = outfp;
	in_fp = infp;
	control = controlClass;
}
void ProductSearchUI::startInterface() {
	(*out_fp) << "4.1. ��ǰ ���� �˻�\n> ";
}

void ProductSearchUI::productListFailed() {
	(*out_fp) << "��ġ�ϴ� ��ǰ�� �����ϴ�\n\n";
}



void ProductSearchUI::productListSuccess(string sellerID,string productName, string companyName, int price, int quantity, float averageSatisfaction) {
	(*out_fp)  << sellerID << " " << productName << " " << companyName << " " << price << " " << quantity << " ";
	if (averageSatisfaction == 0) {
		(*out_fp) << "�򰡵��� ����\n\n";
	}
	else{
		(*out_fp) << averageSatisfaction << "\n\n";
	}
	//������
	
}

void ProductSearchUI::inputProductName() {
	string productName;
	(*in_fp) >> productName;
	control->showProductList(productName);
}
