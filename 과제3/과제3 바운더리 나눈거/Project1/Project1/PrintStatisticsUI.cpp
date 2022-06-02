#include "PrintStatisticsUI.h"
#include "PrintStatistics.h"
PrintStatisticsUI::PrintStatisticsUI(ofstream* outfp, ifstream* infp) {
	out_fp = outfp;
	in_fp = infp;
}
void PrintStatisticsUI::startInterface() {
	(*out_fp) << "3.3. �Ǹ� �Ϸ� ��ǰ ��ȸ\n";
}

void PrintStatisticsUI::loginFailed() {
	(*out_fp) << "> " << "�α����� ���� ���ּ���.\n\n";
}


void PrintStatisticsUI::inquirySoldOutProductFailed() {
	(*out_fp) << "> �Ǹ� �Ϸ�� ��ǰ�� �����ϴ�.\n";
}

void PrintStatisticsUI::inquirySoldOutProductSuccess(string productName, string companyName, int price, int quantity, float averageSatisfaction) {
	(*out_fp) << "> " << productName << " " << companyName << " " << price << " " << quantity << " " << averageSatisfaction << "\n";
}

void PrintStatisticsUI::endOfLine() {
	(*out_fp) << "\n";
}
