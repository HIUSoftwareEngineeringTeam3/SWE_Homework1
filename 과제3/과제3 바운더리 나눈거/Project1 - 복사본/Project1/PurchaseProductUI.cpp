#include "PurchaseProduct.h"
#include "PurchaseProductUI.h"

PurchaseProductUI::PurchaseProductUI(ofstream* outfp, ifstream* infp, PurchaseProduct* controlClass) {
	out_fp = outfp;
	in_fp = infp;
	control = controlClass;
}
void PurchaseProductUI::startInterface() {
	(*out_fp) << "4.2. ��ǰ ����\n> ";
}

void PurchaseProductUI::notSearchedProductFailed() {
	(*out_fp) << "��ǰ�� �˻��ϼ���\n\n";
}

void PurchaseProductUI::loginFailed() {
	(*out_fp) << "�α����� ���ּ���\n\n";
}

void PurchaseProductUI::productEmptyFailed() {
	(*out_fp) << "�ǸŰ� ������ ��ǰ�Դϴ�.\n\n";
}



void PurchaseProductUI::purchaseSuccess(string sellerID, string productName) {

	(*out_fp) << sellerID << " " << productName << "\n\n";
	//������

}

void PurchaseProductUI::purchaseButton() {

	control->purchaseProduct();
}
