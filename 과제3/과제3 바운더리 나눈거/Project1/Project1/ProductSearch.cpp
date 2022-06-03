#include "ProductSearch.h"
#include "ProductSearchUI.h"
#include "Member.h"
#include "MemberCollection.h"
#include "ProductCollection.h"
#include "Product.h"


ProductSearch::ProductSearch(ofstream* outfp, ifstream* infp, MemberCollection* memList) {
	boundary = new ProductSearchUI(outfp, infp, this);
	memberCollection = memList;
	boundary->startInterface();

}

void ProductSearch::showProductList(string name) {
	Product* searchingProduct = NULL;
	vector<Member*>* wholeMemberVector = memberCollection->getMemberVector();
	for (int j = 0; j < (*wholeMemberVector).size(); j++)
	{
		vector<Product*>* nowProductVector = (*wholeMemberVector)[j]->getSellingProductCollection()->getProductVector();
		for (int i = 0; i < nowProductVector->size(); i++)  //��� ��ǰ�� ���̽��� searching �ؾ� �ϴµ�.... product�� �����ϸ�... ��� Ǯ��� ���� �𸣰���
		{
			Product* nowLookingProduct = (*nowProductVector)[i];
			if (nowLookingProduct->getProductName().compare(name) == 0)
			{
				if (nowLookingProduct->getNowSelling() == true) {
					searchingProduct = nowLookingProduct;
					break;
				}
			}
		}
		if (searchingProduct != NULL)
		{
			break;
		}
	}
	if (searchingProduct == NULL)
	{
		boundary->productListFailed();
	}
	else
	{
		memberCollection->getNowLoginMember()->searchingProduct = searchingProduct;
		boundary->productListSuccess(searchingProduct->getSellingMember()->getMemberID(), searchingProduct->getProductName(),
			searchingProduct->getMadeCompanyName(), searchingProduct->getProductPrice(),searchingProduct->remainProductQuantity() ,searchingProduct->getAverageSatisfaction());

	}
}

ProductSearchUI* ProductSearch::getBoundary() {
	return boundary;
}
