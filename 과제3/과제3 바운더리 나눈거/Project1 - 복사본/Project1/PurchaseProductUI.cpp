#include "PurchaseProduct.h"
#include "PurchaseProductUI.h"

PurchaseProductUI::PurchaseProductUI(ofstream* outfp, ifstream* infp, PurchaseProduct* controlClass) {
	out_fp = outfp;
	in_fp = infp;
	control = controlClass;
}
void PurchaseProductUI::startInterface() {
	(*out_fp) << "4.2. 상품 구매\n> ";
}

void PurchaseProductUI::notSearchedProductFailed() {
	(*out_fp) << "상품을 검색하세요\n\n";
}

void PurchaseProductUI::loginFailed() {
	(*out_fp) << "로그인을 해주세요\n\n";
}

void PurchaseProductUI::productEmptyFailed() {
	(*out_fp) << "판매가 중지된 상품입니다.\n\n";
}



void PurchaseProductUI::purchaseSuccess(string sellerID, string productName) {

	(*out_fp) << sellerID << " " << productName << "\n\n";
	//리메인

}

void PurchaseProductUI::purchaseButton() {

	control->purchaseProduct();
}
