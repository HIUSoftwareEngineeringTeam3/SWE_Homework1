

// ��� ����
#include <stdio.h>
#include <string.h>
// ��� ����
#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"


struct ProductStruct {
	Member* sellingMember;
	char productName[MAX_STRING];
	char madeCompanyName[MAX_STRING];
	int productPrice;
	int productQuantity;

	int satisfactionNumber;
	int satisfactionQuantity;
	Product* nextProductNode;
}typedef Product;


struct MemberStruct {
	char memberName[MAX_STRING];
	char memberNumber[MAX_STRING];
	char memberID[MAX_STRING];
	char memberPWD[MAX_STRING];

	Product* sellingProductList;
	Product* selledProductList;		//�����Ϳű��
	Product* boughtProductList;	//��������

	Member* nextMemberNode;
} typedef Member;


// �Լ� ����
void doTask();
void join();
void programExit();
void registerProduct(Member* oneMember);
void setSatisfaction(Member* oneMember);

// ���� ����
FILE* in_fp, *out_fp;
int main()
{ // ���� ������� ���� �ʱ�ȭ
	FILE* in_fp = fopen(INPUT_FILE_NAME, "r+"); FILE* out_fp = fopen(OUTPUT_FILE_NAME, "w+");
	doTask();
	return 0;
}

void doTask()
{ // �޴� �Ľ��� ���� level ������ ���� ����
	int menu_level_1 = 0, menu_level_2 = 0;
	int is_program_exit = 0;
	Member* nowMember = (Member*)malloc(sizeof(Member));
	memset(nowMember, 0x0, sizeof(Member));
	while (!is_program_exit)
	{ // �Է����Ͽ��� �޴� ���� 2���� �б�
		fscanf(in_fp, "%d %d ", &menu_level_1, &menu_level_2);
		
		// �޴� ���� �� �ش� ���� ����
		switch (menu_level_1)
		{
			case 1:
				switch (menu_level_2)
				{
					case 1:
						join();
						break;
				}
				break;
			case 7:
				switch (menu_level_2)
				{
					case 1: // "6.1. ���ᡰ �޴� �κ�
						programExit();
						is_program_exit = 1;
						break;
				}
				break;
		}
	}

	free(nowMember);
}
void join()
{
	char user_type[MAX_STRING], name[MAX_STRING], SSN[MAX_STRING],
		address[MAX_STRING], ID[MAX_STRING], password[MAX_STRING];
	// �Է� ���� : �̸�, �ֹι�ȣ, ID, Password�� ���Ϸκ��� ����
	fscanf(in_fp, "%s %s %s %s", name, SSN, ID, password);
	// �ش� ��� ����

		// ��� ����
	fprintf(out_fp, "1.1. ȸ������\n"); fprintf(out_fp, "%s %s %s %s\n", name, SSN, ID, password);
}

void programExit()
{

}

void registerProduct(Member* oneMember) 
{
	char productName[MAX_STRING], madeCompanyName[MAX_STRING];
	int productPrice = 0, productQuantity = 0;
	Product* mallocProduct = (Product*)malloc(sizeof(Product));
	Product* nowProductNode;
	Product* lastProductNode;
	fscanf(in_fp, "%s %s %d %d", productName, madeCompanyName, productPrice, productQuantity);

	memset(mallocProduct, 0x0, sizeof(Product));
	mallocProduct->sellingMember = oneMember;
	strncpy(mallocProduct->productName, productName, MAX_STRING);
	strncpy(mallocProduct->madeCompanyName, productName, MAX_STRING);
	mallocProduct->productPrice = productPrice;
	mallocProduct->productQuantity = productQuantity;

	nowProductNode = oneMember->sellingProductList;
	lastProductNode = NULL;
	if (nowProductNode == NULL)
	{
		oneMember->sellingProductList = mallocProduct;
	}
	else
	{
		while (nowProductNode != NULL) 
		{
			lastProductNode = nowProductNode;
			nowProductNode = nowProductNode->nextProductNode;
		}
		lastProductNode->nextProductNode = mallocProduct;
	}
	printf("3.1. �Ǹ� �Ƿ� ���\n> %s %s %d %d\n\n",productName,madeCompanyName,productPrice,productQuantity);
}

void setSatisfaction(Member* oneMember) 
{
	char productName[MAX_STRING];
	int productSatisfaction;
	Product* nowProductNode;
	fscanf(in_fp, "%s %d", productName, productSatisfaction);

	nowProductNode = oneMember->boughtProductList;
	if (nowProductNode == NULL)
	{
		printf("4.4. ��ǰ ���Ÿ����� ��\n> ��ġ�ϴ� ��ǰ�� �����ϴ�\n\n");
	}
	else
	{
		while (nowProductNode != NULL)
		{
			if (strcmp(nowProductNode->productName, productName) == 0) 
			{
				break;
			}
			nowProductNode = nowProductNode->nextProductNode;
		}
	}
	if (nowProductNode == NULL) 
	{
		printf("4.4. ��ǰ ���Ÿ����� ��\n> ��ġ�ϴ� ��ǰ�� �����ϴ�\n\n");
	}
	else {
		nowProductNode->satisfactionNumber += productSatisfaction;
		nowProductNode->satisfactionQuantity++;
	}
	printf("4.4. ��ǰ ���Ÿ����� ��\n> [�Ǹ���ID] [��ǰ��] [���Ÿ�����]",oneMember);
}

