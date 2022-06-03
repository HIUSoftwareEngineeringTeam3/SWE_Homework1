#include "PrintStatisticsUI.h"
#include "PrintStatistics.h"
#include "Member.h"
#include "MemberCollection.h"
#include "ProductCollection.h"
#include "Product.h"


PrintStatistics::PrintStatistics(ofstream* outfp, ifstream* infp, MemberCollection* memList) {
	boundary = new PrintStatisticsUI(outfp, infp, this);
	memberCollection = memList;


	boundary->startInterface();


}

void PrintStatistics::showStatistics() {
	if (memberCollection->checkNowLoginMember() == false) {
		boundary->loginFailed();
	}
	else {
		vector<Product*>* soldOutProductVector = memberCollection->getNowLoginMember()->getSoldOutProductCollection()->getProductVector();
		vector<Product*>* sellingProductVector = memberCollection->getNowLoginMember()->getSellingProductCollection()->getProductVector();
		//cout << "5.1. 판매 상품 통계\n";
		if (soldOutProductVector->size() == 0 && sellingProductVector->size() == 0)
		{
			boundary->printStatisticsFailed();
			
			//cout << "> 판매된 상품이 없습니다\n";
		}
		else
		{
			for (int i = 0; i < soldOutProductVector->size(); i++)
			{
				Product* nowLookingProduct = (*soldOutProductVector)[i];
				boundary->printStatisticsSuccess(nowLookingProduct->getProductName(),
					nowLookingProduct->getSelledProductQuantity()*nowLookingProduct->getProductPrice(),
					nowLookingProduct->getAverageSatisfaction());
			}
			for (int i = 0; i < sellingProductVector->size(); i++)
			{
				Product* nowLookingProduct = (*sellingProductVector)[i];
				if (nowLookingProduct->getSelledProductQuantity() == 0) {
					continue;
				}
				boundary->printStatisticsSuccess(nowLookingProduct->getProductName(),
					nowLookingProduct->getSelledProductQuantity()*nowLookingProduct->getProductPrice(),
					nowLookingProduct->getAverageSatisfaction());
			}
			boundary->endOfLine();
		}
		
		//cout << "\n";
	}

}

PrintStatisticsUI* PrintStatistics::getBoundary() {
	return boundary;
}
