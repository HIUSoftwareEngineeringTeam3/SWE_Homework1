#include "InquirySellingProductUI.h"
#include "InquirySellingProduct.h"

InquirySellingProductUI::InquirySellingProductUI(ofstream* outfp, ifstream* infp, InquirySellingProduct* controlClass) {
	out_fp = outfp;
	in_fp = infp;
	control = controlClass;

}
void InquirySellingProductUI::startInterface() {
	(*out_fp) << "3.2. 등록 상품 조회\n";
}

void InquirySellingProductUI::clickInquiryProduct() {
	control->showProduct();
	
}

void InquirySellingProductUI::loginFailed() {
	(*out_fp) << "> " << "로그인을 먼저 해주세요.\n\n";
}

void InquirySellingProductUI::inquiryProductFailed() {
	(*out_fp) << "> " << "등록한 상품이 없습니다.\n\n";
}

void InquirySellingProductUI::inquiryProductSuccess(string productName, string companyName, int price, int quantity){
	(*out_fp) << "> " << productName << " " << companyName << " " << price << " " << quantity << "\n";
}

void InquirySellingProductUI::endOfLine() {
	(*out_fp) << "\n";
}
