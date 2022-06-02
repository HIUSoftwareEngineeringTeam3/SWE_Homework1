#include "InquirySoldProductUI.h"
#include "InquirySoldProduct.h"

InquirySoldProductUI::InquirySoldProductUI(ofstream* outfp, ifstream* infp, InquirySoldProduct* controlClass) {
	out_fp = outfp;
	in_fp = infp;
	control = controlClass;
}
void InquirySoldProductUI::startInterface() {
	(*out_fp) << "3.3. �Ǹ� �Ϸ� ��ǰ ��ȸ\n";
}

void InquirySoldProductUI::loginFailed() {
	(*out_fp) << "> " << "�α����� ���� ���ּ���.\n\n";
}

void InquirySoldProductUI::clickInquirySoldProductButton() {
	control->showProduct();
}


void InquirySoldProductUI::inquirySoldOutProductFailed() {
	(*out_fp) << "> �Ǹ� �Ϸ�� ��ǰ�� �����ϴ�.\n\n";
}

void InquirySoldProductUI::inquirySoldOutProductSuccess(string productName, string companyName, int price, int quantity, float averageSatisfaction){
	(*out_fp) << "> " << productName << " " << companyName << " " << price << " " << quantity << " ";
	if (averageSatisfaction == 0) {
		(*out_fp) << "�򰡵��� ����\n";
	}
	else {
		(*out_fp) << averageSatisfaction << "\n";
	}
	
}

void InquirySoldProductUI::endOfLine() {
	(*out_fp) << "\n";
}
