#include "PrintStatisticsUI.h"
#include "PrintStatistics.h"
#include "Member.h"
#include "MemberList.h"
#include "Product.h"


PrintStatistics::PrintStatistics(ofstream* outfp, ifstream* infp, MemberList* memList) {
	boundary = new PrintStatisticsUI(outfp, infp);
	memberList = memList;


	boundary->startInterface();


}

void PrintStatistics::showProduct() {
	if (memberList->checkNowLoginMember() == false) {
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

				nowLookingProduct->printSoldProductList();
				boundary->inquirySoldOutProductSuccess(nowLookingProduct->getProductName(),
					nowLookingProduct->getmadeCompanyName(), nowLookingProduct->getproductPrice(), nowLookingProduct->getSelledProductQuantity(),
					nowLookingProduct->getAverageSatisfaction());
			}
			boundary->endOfLine();

		}
	}

}

PrintStatisticsUI* PrintStatistics::getBoundary() {
	return boundary;
}
