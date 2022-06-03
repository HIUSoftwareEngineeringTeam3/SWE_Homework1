#include "InquirySoldProductUI.h"
#include "InquirySoldProduct.h"
#include "Member.h"
#include "MemberCollection.h"
#include "ProductCollection.h"
#include "Product.h"


InquirySoldProduct::InquirySoldProduct(ofstream* outfp, ifstream* infp, MemberCollection* memList) {
	boundary = new InquirySoldProductUI(outfp, infp, this);
	memberCollection = memList;


	boundary->startInterface();


}

void InquirySoldProduct::showProduct() {
	if (memberCollection->checkNowLoginMember()==false) {
		boundary->loginFailed();
	}
	else {
		vector<Product*>* soldOutProductVector = memberCollection->getNowLoginMember()->getSoldOutProductCollection()->getProductVector();
		if (soldOutProductVector->size() == 0)
		{
			boundary->inquirySoldOutProductFailed();
		}
		else
		{
			for (int i = 0; i < soldOutProductVector->size(); i++)
			{
				Product* nowLookingProduct = (*soldOutProductVector)[i];
				boundary->inquirySoldOutProductSuccess(nowLookingProduct->getProductName(),
					nowLookingProduct->getMadeCompanyName(), nowLookingProduct->getProductPrice(), nowLookingProduct->getSelledProductQuantity(),
					nowLookingProduct->getAverageSatisfaction());
			}
			boundary->endOfLine();

		}
	}
	
}

InquirySoldProductUI* InquirySoldProduct::getBoundary() {
	return boundary;
}
