#include "PrintStatisticsUI.h"
#include "PrintStatistics.h"
PrintStatisticsUI::PrintStatisticsUI(ofstream* outfp, ifstream* infp, PrintStatistics* controlClass) {
	out_fp = outfp;
	in_fp = infp;
	control = controlClass;
}
void PrintStatisticsUI::startInterface() {
	(*out_fp) << "5.1. 판매 상품 통계\n";
}

void PrintStatisticsUI::loginFailed() {
	(*out_fp) << "> 로그인을 먼저 해주세요.\n\n";
}


void PrintStatisticsUI::printStatisticsFailed() {
	(*out_fp) << "> 판매된 상품이 없습니다\n\n";
}
void PrintStatisticsUI::printStatisticsButton() {
	control->showStatistics();
}

void PrintStatisticsUI::printStatisticsSuccess(string productName, int price, float averageSatisfaction) {
	(*out_fp) <<"> "<< productName << " " << price << " ";
	if (averageSatisfaction == 0) {
		(*out_fp) << "평가되지 않음\n";
	}
	else {
		(*out_fp) << averageSatisfaction << "\n";
	}
	
}

void PrintStatisticsUI::endOfLine() {
	(*out_fp) << "\n";
}
