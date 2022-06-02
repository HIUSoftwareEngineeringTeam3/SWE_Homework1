#include "PurchaseProduct.h"
#include "PurchaseProductUI.h"
#include "Member.h"
#include "MemberList.h"
#include "Product.h"


PurchaseProduct::PurchaseProduct(ofstream* outfp, ifstream* infp, MemberList* memList) {
	boundary = new PurchaseProductUI(outfp, infp, this);
	memberList = memList;

	boundary->startInterface();

}


PurchaseProductUI* PurchaseProduct::getBoundary() {
	return boundary;
}

void PurchaseProduct::purchaseProduct()
{
	if (memberList->checkNowLoginMember() == false) {
		boundary->loginFailed();
	}
	else {
		Member* nowLoginMember = memberList->getNowLoginMember();
		Product* searchingProduct = nowLoginMember->searchingProduct;
		if (searchingProduct == NULL)
		{
			boundary->notSearchedProductFailed();
		}
		else
		{
			if (searchingProduct->getNowSelling() == false)
			{
				boundary->productEmptyFailed();
				
			}
			else {
				
				boundary->purchaseSuccess(searchingProduct->getSellingMember()->getMemberID(), searchingProduct->getProductName());
				searchingProduct->buyProduct();
				nowLoginMember->getBoughtProductVector()->push_back(searchingProduct);
				nowLoginMember->searchingProduct = NULL;
			}

		}
	}
	


}
