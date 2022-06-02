#include "InquiryBoughtProductUI.h"
#include "InquiryBoughtProduct.h"

InquiryBoughtProductUI::InquiryBoughtProductUI(ofstream* outfp, ifstream* infp) {
	out_fp = outfp;
	in_fp = infp;
}
void InquiryBoughtProductUI::startInterface() {
	(*out_fp) << "4.3. ��ǰ ���� ���� ��ȸ\n";
}

void InquiryBoughtProductUI::clickInquiryBoughtProduct() {
	control->showProduct();

}

void InquiryBoughtProductUI::loginFailed() {
	(*out_fp) << "> " << "�α����� ���� ���ּ���.\n\n";
}

void InquiryBoughtProductUI::inquiryBoughtProductFailed() {
	(*out_fp) << "> " << "������ ��ǰ�� �����ϴ�.\n\n";
}

void InquiryBoughtProductUI::inquiryBoughtProductSuccess(string sellerID, string productName, string companyName, int price, int quantity,float averageSatisfaction) {
	(*out_fp) << "> " << sellerID << " " << productName << " " << companyName << " " << price << " " << quantity << " ";
	if (averageSatisfaction == 0) {
		(*out_fp) << "�򰡵��� ����";
	}
	else {
		(*out_fp) << averageSatisfaction;
	}
	
}

void InquiryBoughtProductUI::endOfLine() {
	(*out_fp) << "\n";
}
