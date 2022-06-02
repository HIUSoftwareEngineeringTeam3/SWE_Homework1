#include "ProductSearch.h"
#include "ProductSearchUI.h"
#include "Member.h"
#include "MemberList.h"
#include "Product.h"


ProductSearch::ProductSearch(ofstream* outfp, ifstream* infp, MemberList* memList) {
	boundary = new ProductSearchUI(outfp, infp);
	memberList = memList;
	boundary->startInterface();

}

void ProductSearch::showProductList(string name) {
	Product* searchingProduct = NULL;
	vector<Member*>* wholeMemberVector = memberList->getMemberVector();
	for (int j = 0; j < (*wholeMemberVector).size(); j++)
	{
		for (int i = 0; i < (*wholeMemberVector)[j]->getSellingProductVector()->size(); i++)  //��� ��ǰ�� ���̽��� searching �ؾ� �ϴµ�.... product�� �����ϸ�... ��� Ǯ��� ���� �𸣰���
		{
			Product* nowLookingProduct = (*((*wholeMemberVector)[j]->getSellingProductVector()))[i];
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
		//cout << "4.1. ��ǰ ���� �˻�\n> ��ġ�ϴ� ��ǰ�� �����ϴ�\n\n";
	}
	else
	{
		boundary->productListSuccess(searchingProduct->getSellingMember()->getMemberID(), searchingProduct->getProductName(),
			searchingProduct->getmadeCompanyName(), searchingProduct->getproductPrice(),searchingProduct->remainProductQuantity() ,searchingProduct->getAverageSatisfaction());
	
	}
}

ProductSearchUI* ProductSearch::getBoundary() {
	return boundary;
}
