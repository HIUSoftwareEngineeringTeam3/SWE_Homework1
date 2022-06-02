#include "RegisterProductUI.h"
#include "RegisterProduct.h"
#include "Member.h"
#include "MemberList.h"


RegisterProduct::RegisterProduct(ofstream* outfp, ifstream* infp, MemberList* memList) {
	boundary = new RegisterProductUI(outfp, infp, this);
	memberList = memList;
	boundary->startInterface();
}
void RegisterProduct::registerProduct(string productName, string companyName, int price, int quantity) {
	
	if (memberList->checkNowLoginMember() == false) {
		boundary->registerProductFailed();
	}
	else {
		Member* nowLoginMember = memberList->getNowLoginMember();
		nowLoginMember->registerProduct(productName, companyName, price, quantity);
		boundary->registerProductSuccess(productName, companyName, price, quantity);
	}
	
}

RegisterProductUI* RegisterProduct::getBoundary() {
	return boundary;
}
