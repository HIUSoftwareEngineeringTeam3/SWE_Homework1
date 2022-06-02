#include "EvaluateSatisfaction.h"
#include "EvaluateSatisfactionUI.h"
#include "Member.h"
#include "MemberList.h"
#include "Product.h"


EvaluateSatisfaction::EvaluateSatisfaction(ofstream* outfp, ifstream* infp, MemberList* memList) {
	boundary = new EvaluateSatisfactionUI(outfp, infp);
	memberList = memList;
	boundary->startInterface();

}

void EvaluateSatisfaction::confirmScore(string productName, int evaluateNum) {
	if (memberList->checkNowLoginMember()) {
		boundary->loginFailed();
	}
	else {
		Product* evaluatingProduct = NULL;
		vector<Product*>* boughtProductVector = memberList->getNowLoginMember()->getBoughtProductVector();
		for (int i = 0; i < boughtProductVector->size(); i++)
		{
			Product* nowLookingProduct = (*boughtProductVector)[i];
			if (nowLookingProduct->getProductName().compare(productName) == 0)
			{
				evaluatingProduct = nowLookingProduct;
				break;
			}
		}
		if (evaluatingProduct == NULL)
		{
			boundary->productNotFoundFailed();
			//cout<< "4.4. ��ǰ ���Ÿ����� ��\n> ��ġ�ϴ� ��ǰ�� �����ϴ�\n\n";
		}
		else
		{
			evaluatingProduct->evaluateSatisfaction(evaluateNum);
			boundary->evaluateSuccess(evaluatingProduct->getSellingMember()->getMemberName(), evaluatingProduct->getProductName(), evaluatingProduct->getAverageSatisfaction());


			//cout << "4.4. ��ǰ ���Ÿ����� ��\n> " << evaluatingProduct->getSellingMember()->getMemberName() << " " << evaluatingProduct->getProductName() << " " << evaluatingProduct->getAverageSatisfaction()
			//	<< "\n\n";
		}
	}
	
}

EvaluateSatisfactionUI* EvaluateSatisfaction::getBoundary() {
	return boundary;
}
