#include "InquirySoldProductUI.h"
#include "InquirySoldProduct.h"

InquirySoldProductUI::InquirySoldProductUI(ofstream* outfp, ifstream* infp) {
	out_fp = outfp;
	in_fp = infp;
}
void InquirySoldProductUI::startInterface() {
	(*out_fp) << "3.3. �Ǹ� �Ϸ� ��ǰ ��ȸ\n";
}

void InquirySoldProductUI::loginFailed() {
	(*out_fp) << "> " << "�α����� ���� ���ּ���.\n\n";
}


void InquirySoldProductUI::inquirySoldOutProductFailed() {
	(*out_fp) << "> �Ǹ� �Ϸ�� ��ǰ�� �����ϴ�.\n";
}

void InquirySoldProductUI::inquirySoldOutProductSuccess(string productName, string companyName, int price, int quantity, float averageSatisfaction){
	(*out_fp) << "> " << productName << " " << companyName << " " << price << " " << quantity << " " << averageSatisfaction << "\n";
}

void InquirySoldProductUI::endOfLine() {
	(*out_fp) << "\n";
}
