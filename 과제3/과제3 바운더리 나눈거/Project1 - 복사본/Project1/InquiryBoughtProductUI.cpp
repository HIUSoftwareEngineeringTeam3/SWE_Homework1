#include "InquiryBoughtProductUI.h"
#include "InquiryBoughtProduct.h"

InquiryBoughtProductUI::InquiryBoughtProductUI(ofstream* outfp, ifstream* infp, InquiryBoughtProduct* controlClass) {
	out_fp = outfp;
	in_fp = infp;
	control = controlClass;
}
void InquiryBoughtProductUI::startInterface() {
	(*out_fp) << "4.3. 상품 구매 내역 조회\n";
}

void InquiryBoughtProductUI::clickInquiryBoughtProduct() {
	control->showProduct();

}

void InquiryBoughtProductUI::loginFailed() {
	(*out_fp) << "> " << "로그인을 먼저 해주세요.\n\n";
}

void InquiryBoughtProductUI::inquiryBoughtProductFailed() {
	(*out_fp) << "> " << "구매한 상품이 없습니다.\n\n";
}

void InquiryBoughtProductUI::inquiryBoughtProductSuccess(string sellerID, string productName, string companyName, int price, int quantity,float averageSatisfaction) {
	(*out_fp) << "> " << sellerID << " " << productName << " " << companyName << " " << price << " " << quantity << " ";
	if (averageSatisfaction == 0) {
		(*out_fp) << "평가되지 않음\n";
	}
	else {
		(*out_fp) << averageSatisfaction<<"\n";
	}
	
}

void InquiryBoughtProductUI::endOfLine() {
	(*out_fp) << "\n";
}
