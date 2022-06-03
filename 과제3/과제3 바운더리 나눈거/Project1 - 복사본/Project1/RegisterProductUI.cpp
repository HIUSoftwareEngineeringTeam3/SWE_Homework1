#include "RegisterProductUI.h"
#include "RegisterProduct.h"

RegisterProductUI::RegisterProductUI(ofstream* outfp, ifstream* infp,RegisterProduct* controlClass) {
	out_fp = outfp;
	in_fp = infp;
	control = controlClass;
}
void RegisterProductUI::startInterface() {
	(*out_fp) << "3.1. �Ǹ� �Ƿ� ���\n> ";
}
void RegisterProductUI::inputInformation() {
	string productName, companyName;
	int price, quantity;
	(*in_fp) >> productName >> companyName >> price >> quantity;
	control->registerProduct(productName, companyName, price, quantity);
}

void RegisterProductUI::registerProductSuccess(string productName, string companyName, int price, int quantity) {
	(*out_fp) << productName << " " << companyName << " " << price << " " << quantity << "\n\n";
}

void RegisterProductUI::registerProductFailed() {
	(*out_fp) << "�α����� ���ּ���\n\n";
}
