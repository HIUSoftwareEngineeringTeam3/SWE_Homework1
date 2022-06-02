#include "EvaluateSatisfaction.h"
#include "EvaluateSatisfactionUI.h"

EvaluateSatisfactionUI::EvaluateSatisfactionUI(ofstream* outfp, ifstream* infp) {
	out_fp = outfp;
	in_fp = infp;
}
void EvaluateSatisfactionUI::startInterface() {
	(*out_fp) << "4.4. ��ǰ ���Ÿ����� ��\n> ";
}

void EvaluateSatisfactionUI::productNotFoundFailed() {
	(*out_fp) << "��ġ�ϴ� ��ǰ�� �����ϴ�\n\n";
}



void EvaluateSatisfactionUI::evaluateSuccess(string sellerName, string productName,  float averageSatisfaction) {
	(*out_fp) <<sellerName << " " << productName << " " << productName <<" " << averageSatisfaction << "\n\n";
	//������

}


void EvaluateSatisfactionUI::loginFailed() {
	(*out_fp) << "�α����� ���ּ���\n\n";
}

void EvaluateSatisfactionUI::inputScore() {
	string productName;
	int evaluateNum;
	(*in_fp) >> productName >> evaluateNum;
	control->confirmScore(productName, evaluateNum);
}
