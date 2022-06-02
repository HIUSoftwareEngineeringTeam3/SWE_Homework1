#include "InquirySellingProductUI.h"
#include "InquirySellingProduct.h"

InquirySellingProductUI::InquirySellingProductUI(ofstream* outfp, ifstream* infp, InquirySellingProduct* controlClass) {
	out_fp = outfp;
	in_fp = infp;
	control = controlClass;

}
void InquirySellingProductUI::startInterface() {
	(*out_fp) << "3.2. ��� ��ǰ ��ȸ\n";
}

void InquirySellingProductUI::clickInquiryProduct() {
	control->showProduct();
	
}

void InquirySellingProductUI::loginFailed() {
	(*out_fp) << "> " << "�α����� ���� ���ּ���.\n\n";
}

void InquirySellingProductUI::inquiryProductFailed() {
	(*out_fp) << "> " << "����� ��ǰ�� �����ϴ�.\n\n";
}

void InquirySellingProductUI::inquiryProductSuccess(string productName, string companyName, int price, int quantity){
	(*out_fp) << "> " << productName << " " << companyName << " " << price << " " << quantity << "\n";
}

void InquirySellingProductUI::endOfLine() {
	(*out_fp) << "\n";
}
