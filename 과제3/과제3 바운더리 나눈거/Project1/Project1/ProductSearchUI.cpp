#include "ProductSearch.h"
#include "ProductSearchUI.h"

ProductSearchUI::ProductSearchUI(ofstream* outfp, ifstream* infp,ProductSearch* controlClass) {
	out_fp = outfp;
	in_fp = infp;
	control = controlClass;
}
void ProductSearchUI::startInterface() {
	(*out_fp) << "4.1. 상품 정보 검색\n> ";
}

void ProductSearchUI::productListFailed() {
	(*out_fp) << "일치하는 상품이 없습니다\n\n";
}



void ProductSearchUI::productListSuccess(string sellerID,string productName, string companyName, int price, int quantity, float averageSatisfaction) {
	(*out_fp)  << sellerID << " " << productName << " " << companyName << " " << price << " " << quantity << " ";
	if (averageSatisfaction == 0) {
		(*out_fp) << "평가되지 않음\n\n";
	}
	else{
		(*out_fp) << averageSatisfaction << "\n\n";
	}
	//리메인
	
}

void ProductSearchUI::inputProductName() {
	string productName;
	(*in_fp) >> productName;
	control->showProductList(productName);
}
