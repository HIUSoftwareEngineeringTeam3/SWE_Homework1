#include "InquirySellingProductUI.h"
#include "InquirySellingProduct.h"
#include "Member.h"
#include "MemberCollection.h"
#include "ProductCollection.h"
#include "Product.h"


InquirySellingProduct::InquirySellingProduct(ofstream* outfp, ifstream* infp, MemberCollection* memList) {
	boundary = new InquirySellingProductUI(outfp, infp, this);
	memberCollection = memList;
	boundary->startInterface();
}
void InquirySellingProduct::showProduct() {

	if (memberCollection->checkNowLoginMember() == false) {
		boundary->loginFailed();
	}
	else {
		Member* nowLoginMember = memberCollection->getNowLoginMember();
		vector<Product*>* productVector= nowLoginMember->getSellingProductCollection()->getProductVector();
		if (productVector->size() == 0) {
			boundary->inquiryProductFailed();	
		}
		else {
			for (int i = 0; i < productVector->size(); i++)
			{
				Product* nowLookingProduct = (*productVector)[i];
				boundary->inquiryProductSuccess(nowLookingProduct->getProductName(), nowLookingProduct->getMadeCompanyName(),
					nowLookingProduct->getProductPrice(), nowLookingProduct->remainProductQuantity());
			}
			boundary->endOfLine();
			//cout << "\n";
		}
	}

}

InquirySellingProductUI* InquirySellingProduct::getBoundary() {
	return boundary;
}
