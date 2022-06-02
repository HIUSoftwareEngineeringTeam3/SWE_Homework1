#include "InquiryBoughtProductUI.h"
#include "InquiryBoughtProduct.h"
#include "Member.h"
#include "MemberList.h"
#include "Product.h"


InquiryBoughtProduct::InquiryBoughtProduct(ofstream* outfp, ifstream* infp, MemberList* memList) {
	boundary = new InquiryBoughtProductUI(outfp, infp);
	memberList = memList;
	boundary->startInterface();
	
	
	
}

void InquiryBoughtProduct::showProduct() {


	if (memberList->checkNowLoginMember() == false) {
		boundary->loginFailed();
	}
	else {
		vector<Product*>* boughtProductVector = memberList->getNowLoginMember()->getBoughtProductVector();
		if (boughtProductVector->size() == 0)
		{
			boundary->inquiryBoughtProductFailed();
		}
		else
		{
			for (int i = 0; i < boughtProductVector->size(); i++)
			{
				Product* nowLookingProduct = (*boughtProductVector)[i];
				boundary->inquiryBoughtProductSuccess(nowLookingProduct->getSellingMember()->getMemberID,
					nowLookingProduct->getProductName(), nowLookingProduct->getmadeCompanyName(),
					nowLookingProduct->getproductPrice(), nowLookingProduct->remainProductQuantity(),
					nowLookingProduct->getAverageSatisfaction());
			}
			boundary->endOfLine();			
		}
	}

}

InquiryBoughtProductUI* InquiryBoughtProduct::getBoundary() {
	return boundary;
}
