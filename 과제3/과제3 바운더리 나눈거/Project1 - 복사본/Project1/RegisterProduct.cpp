#include "RegisterProductUI.h"
#include "RegisterProduct.h"
#include "Member.h"
#include "MemberCollection.h"


RegisterProduct::RegisterProduct(ofstream* outfp, ifstream* infp, MemberCollection* memList) {
	boundary = new RegisterProductUI(outfp, infp, this);
	memberCollection = memList;
	boundary->startInterface();
}
void RegisterProduct::registerProduct(string productName, string companyName, int price, int quantity) {
	
	if (memberCollection->checkNowLoginMember() == false) {
		boundary->registerProductFailed();
	}
	else {
		Member* nowLoginMember = memberCollection->getNowLoginMember();
		nowLoginMember->registerProduct(productName, companyName, price, quantity);
		boundary->registerProductSuccess(productName, companyName, price, quantity);
	}
	
}

RegisterProductUI* RegisterProduct::getBoundary() {
	return boundary;
}
