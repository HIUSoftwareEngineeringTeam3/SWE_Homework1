#include "InquirySoldProductUI.h"
#include "InquirySoldProduct.h"

InquirySoldProductUI::InquirySoldProductUI(ofstream* outfp, ifstream* infp, InquirySoldProduct* controlClass) {
	out_fp = outfp;
	in_fp = infp;
	control = controlClass;
}
void InquirySoldProductUI::startInterface() {
	(*out_fp) << "3.3. 판매 완료 상품 조회\n";
}

void InquirySoldProductUI::loginFailed() {
	(*out_fp) << "> " << "로그인을 먼저 해주세요.\n\n";
}

void InquirySoldProductUI::clickInquirySoldProductButton() {
	control->showProduct();
}


void InquirySoldProductUI::inquirySoldOutProductFailed() {
	(*out_fp) << "> 판매 완료된 상품이 없습니다.\n\n";
}

void InquirySoldProductUI::inquirySoldOutProductSuccess(string productName, string companyName, int price, int quantity, float averageSatisfaction){
	(*out_fp) << "> " << productName << " " << companyName << " " << price << " " << quantity << " ";
	if (averageSatisfaction == 0) {
		(*out_fp) << "평가되지 않음\n";
	}
	else {
		(*out_fp) << averageSatisfaction << "\n";
	}
	
}

void InquirySoldProductUI::endOfLine() {
	(*out_fp) << "\n";
}
