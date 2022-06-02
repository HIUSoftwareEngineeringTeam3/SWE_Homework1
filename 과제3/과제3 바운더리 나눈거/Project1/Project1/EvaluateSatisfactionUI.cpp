#include "EvaluateSatisfaction.h"
#include "EvaluateSatisfactionUI.h"

EvaluateSatisfactionUI::EvaluateSatisfactionUI(ofstream* outfp, ifstream* infp) {
	out_fp = outfp;
	in_fp = infp;
}
void EvaluateSatisfactionUI::startInterface() {
	(*out_fp) << "4.4. 상품 구매만족도 평가\n> ";
}

void EvaluateSatisfactionUI::productNotFoundFailed() {
	(*out_fp) << "일치하는 상품이 없습니다\n\n";
}



void EvaluateSatisfactionUI::evaluateSuccess(string sellerName, string productName,  float averageSatisfaction) {
	(*out_fp) <<sellerName << " " << productName << " " << productName <<" " << averageSatisfaction << "\n\n";
	//리메인

}


void EvaluateSatisfactionUI::loginFailed() {
	(*out_fp) << "로그인을 해주세요\n\n";
}

void EvaluateSatisfactionUI::inputScore() {
	string productName;
	int evaluateNum;
	(*in_fp) >> productName >> evaluateNum;
	control->confirmScore(productName, evaluateNum);
}
