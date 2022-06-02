#include "PrintStatisticsUI.h"
#include "PrintStatistics.h"
#include "Member.h"
#include "MemberList.h"
#include "Product.h"


PrintStatistics::PrintStatistics(ofstream* outfp, ifstream* infp, MemberList* memList) {
	boundary = new PrintStatisticsUI(outfp, infp, this);
	memberList = memList;


	boundary->startInterface();


}

void PrintStatistics::showStatistics() {
	if (memberList->checkNowLoginMember() == false) {
		boundary->loginFailed();
	}
	else {
		vector<Product*>* soldOutProductVector = memberList->getNowLoginMember()->getSoldOutProductVector();
		vector<Product*>* sellingProductVector = memberList->getNowLoginMember()->getSellingProductVector();
		//cout << "5.1. �Ǹ� ��ǰ ���\n";
		if (soldOutProductVector->size() == 0 && sellingProductVector->size() == 0)
		{
			boundary->printStatisticsFailed();
			
			//cout << "> �Ǹŵ� ��ǰ�� �����ϴ�\n";
		}
		else
		{
			for (int i = 0; i < soldOutProductVector->size(); i++)
			{
				Product* nowLookingProduct = (*soldOutProductVector)[i];
				boundary->printStatisticsSuccess(nowLookingProduct->getProductName(),
					nowLookingProduct->getSelledProductQuantity()*nowLookingProduct->getproductPrice(),
					nowLookingProduct->getAverageSatisfaction());
			}
			for (int i = 0; i < sellingProductVector->size(); i++)
			{
				Product* nowLookingProduct = (*sellingProductVector)[i];
				if (nowLookingProduct->getSelledProductQuantity() == 0) {
					continue;
				}
				boundary->printStatisticsSuccess(nowLookingProduct->getProductName(),
					nowLookingProduct->getSelledProductQuantity()*nowLookingProduct->getproductPrice(),
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
