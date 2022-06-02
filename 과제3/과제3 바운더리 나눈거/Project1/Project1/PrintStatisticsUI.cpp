#include "PrintStatisticsUI.h"
#include "PrintStatistics.h"
PrintStatisticsUI::PrintStatisticsUI(ofstream* outfp, ifstream* infp, PrintStatistics* controlClass) {
	out_fp = outfp;
	in_fp = infp;
	control = controlClass;
}
void PrintStatisticsUI::startInterface() {
	(*out_fp) << "5.1. �Ǹ� ��ǰ ���\n";
}

void PrintStatisticsUI::loginFailed() {
	(*out_fp) << "> �α����� ���� ���ּ���.\n\n";
}


void PrintStatisticsUI::printStatisticsFailed() {
	(*out_fp) << "> �Ǹŵ� ��ǰ�� �����ϴ�\n\n";
}
void PrintStatisticsUI::printStatisticsButton() {
	control->showStatistics();
}

void PrintStatisticsUI::printStatisticsSuccess(string productName, int price, float averageSatisfaction) {
	(*out_fp) <<"> "<< productName << " " << price << " ";
	if (averageSatisfaction == 0) {
		(*out_fp) << "�򰡵��� ����\n";
	}
	else {
		(*out_fp) << averageSatisfaction << "\n";
	}
	
}

void PrintStatisticsUI::endOfLine() {
	(*out_fp) << "\n";
}
