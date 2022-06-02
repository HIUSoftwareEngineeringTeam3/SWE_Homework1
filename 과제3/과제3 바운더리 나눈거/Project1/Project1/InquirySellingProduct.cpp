#include "InquirySellingProductUI.h"
#include "InquirySellingProduct.h"
#include "Member.h"
#include "MemberList.h"
#include "Product.h"


InquirySellingProduct::InquirySellingProduct(ofstream* outfp, ifstream* infp, MemberList* memList) {
	boundary = new InquirySellingProductUI(outfp, infp, this);
	memberList = memList;
	boundary->startInterface();
}
void InquirySellingProduct::showProduct() {

	if (memberList->checkNowLoginMember() == false) {
		boundary->loginFailed();
	}
	else {
		Member* nowLoginMember = memberList->getNowLoginMember();
		vector<Product*>* productVector= nowLoginMember->getSellingProductVector();
		if (productVector->size() == 0) {
			boundary->inquiryProductFailed();	
		}
		else {
			for (int i = 0; i < productVector->size(); i++)
			{
				Product* nowLookingProduct = (*productVector)[i];
				boundary->inquiryProductSuccess(nowLookingProduct->getProductName(), nowLookingProduct->getmadeCompanyName(),
					nowLookingProduct->getproductPrice(), nowLookingProduct->remainProductQuantity());
			}
			boundary->endOfLine();
			//cout << "\n";
		}
	}

}

InquirySellingProductUI* InquirySellingProduct::getBoundary() {
	return boundary;
}
