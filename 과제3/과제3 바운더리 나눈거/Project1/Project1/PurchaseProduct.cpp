#include "PurchaseProduct.h"
#include "PurchaseProductUI.h"
#include "Member.h"
#include "MemberCollection.h"
#include "ProductCollection.h"
#include "Product.h"


PurchaseProduct::PurchaseProduct(ofstream* outfp, ifstream* infp, MemberCollection* memList) {
	boundary = new PurchaseProductUI(outfp, infp, this);
	memberCollection = memList;

	boundary->startInterface();

}


PurchaseProductUI* PurchaseProduct::getBoundary() {
	return boundary;
}

void PurchaseProduct::purchaseProduct()
{
	if (memberCollection->checkNowLoginMember() == false) {
		boundary->loginFailed();
	}
	else {
		Member* nowLoginMember = memberCollection->getNowLoginMember();
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
				//nowLoginMember->getBoughtProductCollection()->push_back(searchingProduct);
				nowLoginMember->getBoughtProductCollection()->pushProduct(searchingProduct);
				nowLoginMember->searchingProduct = NULL;
			}

		}
	}
	


}
