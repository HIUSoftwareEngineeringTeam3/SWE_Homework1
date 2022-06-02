#include "InquirySoldProductUI.h"
#include "InquirySoldProduct.h"
#include "Member.h"
#include "MemberList.h"
#include "Product.h"


InquirySoldProduct::InquirySoldProduct(ofstream* outfp, ifstream* infp, MemberList* memList) {
	boundary = new InquirySoldProductUI(outfp, infp, this);
	memberList = memList;


	boundary->startInterface();


}

void InquirySoldProduct::showProduct() {
	if (memberList->checkNowLoginMember()==false) {
		boundary->loginFailed();
	}
	else {
		vector<Product*>* soldOutProductVector = memberList->getNowLoginMember()->getSoldOutProductVector();
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
					nowLookingProduct->getmadeCompanyName(), nowLookingProduct->getproductPrice(), nowLookingProduct->getSelledProductQuantity(),
					nowLookingProduct->getAverageSatisfaction());
			}
			boundary->endOfLine();

		}
	}
	
}

InquirySoldProductUI* InquirySoldProduct::getBoundary() {
	return boundary;
}
