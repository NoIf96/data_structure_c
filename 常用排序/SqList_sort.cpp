#include<stdio.h>
#include<stdlib.h>
#include "SqList_sort.h"
#include "tool_base.h"

/*  �۰����
 *  LΪ˳���             *
 */
void BInsertSort(SqList L)
{
	int low, high, m;                      //�����б߽�
	int count = 0;

	//�۰�����
	for (int i = 2;i <= L.length;i++) {
		L.r[0] = L.r[i];                   //��L.r[i]�Ĵ浽L.[0]��
		low = 1;  high = i - 1;            //��ȡ���±߽�
		while (low <= high) {              //��L[low,high]���۰�
			m = (low + high) / 2;          //�۰�
			//�ж��۰�����
			if (L.r[0].key < L.r[m].key)
				high = m - 1;
			else
				low = m + 1;
		}
		//��¼����
		for (int j = i - 1;j >= high + 1;j--) 
			L.r[j + 1] = L.r[j];

		L.r[high + 1] = L.r[0];            //����


		printf("��%d���۰�����", ++count);
		SqListTraverse(L, PrintKey);

		
	}
	printf("\n\n�ܼ�%d������\n\n", count);
}

/*  ð������
 *  LΪ˳���             *
 */
void BubbleSort(SqList L)
{
	int lastExchangeIndex; 
	int count = 0;
	for (int i = L.length;i > 1;i = lastExchangeIndex) {

		lastExchangeIndex = 1;
		for(int j = 1;j<i;j++)
			//�໥����
			if (L.r[j + 1].key < L.r[j].key) {
				L.r[0] = L.r[j];
				L.r[j] = L.r[j + 1];
				L.r[j + 1] = L.r[0];
				lastExchangeIndex = j;        //��¼����λ��
	
			}

		printf("��%d��ð������", ++count);
		SqListTraverse(L, PrintKey);

	}
	printf("\n\n�ܼ�%d������\n\n", count);
}

/*  �󶥶�
 *  HΪ��  s��mΪ���±߽�  *
 */
void HeapAdjuset(HeapType & H, int s, int m)
{

	H.r[0] = H.r[s];                   //������ڵ�
	//�عؼ��ֽϴ�Ľ������ɸѡ
	for (int j = 2 * s;j <= m;j *= 2) {
		// jΪ�ϴ�ؼ����±�
		if (j < m && H.r[j].key < H.r[j + 1].key)
			j++;
		//�������������
		if (!(H.r[0].key < H.r[j].key)) {

			break;
		}
		//����
		H.r[s] = H.r[j];
		s = j;
	}
	H.r[s] = H.r[0];

}

/*  ������
 *  HΪ��                  *
 */
void HeapSort(HeapType H)
{
	int i, count = 0;
	//����Ѷ�
	for (i = H.length / 2;i > 0;i--)
		HeapAdjuset(H, i, H.length);

	/*//������
	for (i = H.length;i > 1;i--) {
		H.r[0] = H.r[1];
		H.r[1] = H.r[i];
		H.r[i] = H.r[0];

		//���µ�����Ѷ�
		HeapAdjuset(H, 1, i - 1);*/
		printf("��%d�˶�����", ++count);
		SqListTraverse(H, PrintKey);
	//}

	printf("\n\n�ܼ�%d������\n\n", count);
}


/*  2-·�鲢����
 *                         *
 */
void Merge(RcdType SR[], RcdType TR[], int i, int m, int n)
{
	int j,k;
	for  (j = m + 1, k = i;i <= m && j <= n;k++)
		if (SR[i].key <= SR[j].key)
			TR[k] = SR[i++];
		else
			TR[k] = SR[j++];
	while (i <= m)
		TR[k++] = SR[i++];
	while (j <= n)
		TR[k++] = SR[j++];
}


void Msort(RcdType SR[], RcdType TR1[], int s, int t)
{
	int m;
	RcdType TR2[20];

	if (s == t) 
		TR1[s] = SR[s];
	
	else {
		m = (s + t) / 2;
		Msort(SR, TR2, s, m);
		Msort(SR, TR2, m + 1, t);
		Merge(TR2, TR1, s, m, t);

	}
	
}

void MergeSort(SqList L)
{
	int count = 0;
	Msort(L.r, L.r, 1, L.length);
	printf("2-·�鲢����");
	SqListTraverse(L, PrintKey);
	printf("\n\n");
}

/*  ����
 *                         *
 */
void CreatSqList(SqList & L)
{
	int n;
	printf("����������Ԫ������");
	scanf_s("%d", &n);
	L.r[0].key = 0;
	Pos(12, 26);
	printf("��¼������:");
	for (int i = 1;i <= n;i++) {
		scanf_s("%d", &L.r[i].key);
		L.length++;
	}
}




void SqListTraverse(SqList L, void(*Visit)(RcdType e))
{
	int i;
	printf("�ڱ���%3d\n", L.r[0]);
	printf("��ַ    ");
	for (i = 1;i <= L.length;i++)
		printf("%3d", i);
	printf("\n");
	printf("�ؼ���  ");
	for (i = 1;i <= L.length;i++)
		Visit(L.r[i]);
	printf("\n");
}

void PrintKey(RcdType e)
{
	printf("%3d", e.key);
}



