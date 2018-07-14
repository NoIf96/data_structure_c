#include<stdio.h>
#include<stdlib.h>
#include "SqList_sort.h"
#include "tool_base.h"

/*  折半查找
 *  L为顺序表             *
 */
void BInsertSort(SqList L)
{
	int low, high, m;                      //上下中边界
	int count = 0;

	//折半排序
	for (int i = 2;i <= L.length;i++) {
		L.r[0] = L.r[i];                   //将L.r[i]寄存到L.[0]中
		low = 1;  high = i - 1;            //获取上下边界
		while (low <= high) {              //在L[low,high]中折半
			m = (low + high) / 2;          //折半
			//判断折半区间
			if (L.r[0].key < L.r[m].key)
				high = m - 1;
			else
				low = m + 1;
		}
		//记录后移
		for (int j = i - 1;j >= high + 1;j--) 
			L.r[j + 1] = L.r[j];

		L.r[high + 1] = L.r[0];            //插入


		printf("第%d趟折半排序：", ++count);
		SqListTraverse(L, PrintKey);

		
	}
	printf("\n\n总计%d次排序\n\n", count);
}

/*  冒泡排序
 *  L为顺序表             *
 */
void BubbleSort(SqList L)
{
	int lastExchangeIndex; 
	int count = 0;
	for (int i = L.length;i > 1;i = lastExchangeIndex) {

		lastExchangeIndex = 1;
		for(int j = 1;j<i;j++)
			//相互交换
			if (L.r[j + 1].key < L.r[j].key) {
				L.r[0] = L.r[j];
				L.r[j] = L.r[j + 1];
				L.r[j + 1] = L.r[0];
				lastExchangeIndex = j;        //记录交换位置
	
			}

		printf("第%d趟冒泡排序：", ++count);
		SqListTraverse(L, PrintKey);

	}
	printf("\n\n总计%d次排序\n\n", count);
}

/*  大顶堆
 *  H为堆  s，m为上下边界  *
 */
void HeapAdjuset(HeapType & H, int s, int m)
{

	H.r[0] = H.r[s];                   //保存根节点
	//沿关键字较大的结点向下筛选
	for (int j = 2 * s;j <= m;j *= 2) {
		// j为较大关键字下标
		if (j < m && H.r[j].key < H.r[j + 1].key)
			j++;
		//无需调整，跳出
		if (!(H.r[0].key < H.r[j].key)) {

			break;
		}
		//调整
		H.r[s] = H.r[j];
		s = j;
	}
	H.r[s] = H.r[0];

}

/*  堆排序
 *  H为堆                  *
 */
void HeapSort(HeapType H)
{
	int i, count = 0;
	//建大堆顶
	for (i = H.length / 2;i > 0;i--)
		HeapAdjuset(H, i, H.length);

	/*//堆排序
	for (i = H.length;i > 1;i--) {
		H.r[0] = H.r[1];
		H.r[1] = H.r[i];
		H.r[i] = H.r[0];

		//重新调整大堆顶
		HeapAdjuset(H, 1, i - 1);*/
		printf("第%d趟堆排序：", ++count);
		SqListTraverse(H, PrintKey);
	//}

	printf("\n\n总计%d次排序\n\n", count);
}


/*  2-路归并排序
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
	printf("2-路归并排序：");
	SqListTraverse(L, PrintKey);
	printf("\n\n");
}

/*  构造
 *                         *
 */
void CreatSqList(SqList & L)
{
	int n;
	printf("请输入输入元素数：");
	scanf_s("%d", &n);
	L.r[0].key = 0;
	Pos(12, 26);
	printf("请录入数据:");
	for (int i = 1;i <= n;i++) {
		scanf_s("%d", &L.r[i].key);
		L.length++;
	}
}




void SqListTraverse(SqList L, void(*Visit)(RcdType e))
{
	int i;
	printf("哨兵：%3d\n", L.r[0]);
	printf("地址    ");
	for (i = 1;i <= L.length;i++)
		printf("%3d", i);
	printf("\n");
	printf("关键字  ");
	for (i = 1;i <= L.length;i++)
		Visit(L.r[i]);
	printf("\n");
}

void PrintKey(RcdType e)
{
	printf("%3d", e.key);
}



