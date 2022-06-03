#include "InquiryBoughtProductUI.h"
#include "InquiryBoughtProduct.h"
#include "Member.h"
#include "MemberCollection.h"
#include "ProductCollection.h"
#include "Product.h"


InquiryBoughtProduct::InquiryBoughtProduct(ofstream* outfp, ifstream* infp, MemberCollection* memList) {
	boundary = new InquiryBoughtProductUI(outfp, infp, this);
	memberCollection = memList;
	boundary->startInterface();
	
	
	
}

void InquiryBoughtProduct::showProduct() {


	if (memberCollection->checkNowLoginMember() == false) {
		boundary->loginFailed();
	}
	else {
		vector<Product*>* boughtProductVector = memberCollection->getNowLoginMember()->getBoughtProductCollection()->getProductVector();
		if (boughtProductVector->size() == 0)
		{
			boundary->inquiryBoughtProductFailed();
		}
		else
		{
			for (int i = 0; i < boughtProductVector->size(); i++)
			{
				Product* nowLookingProduct = (*boughtProductVector)[i];
				boundary->inquiryBoughtProductSuccess(nowLookingProduct->getSellingMember()->getMemberID(),
					nowLookingProduct->getProductName(), nowLookingProduct->getMadeCompanyName(),
					nowLookingProduct->getProductPrice(), nowLookingProduct->remainProductQuantity(),
					nowLookingProduct->getAverageSatisfaction());
			}
			boundary->endOfLine();			
		}
	}

}

InquiryBoughtProductUI* InquiryBoughtProduct::getBoundary() {
	return boundary;
}
