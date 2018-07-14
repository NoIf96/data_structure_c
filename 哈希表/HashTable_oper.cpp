#include<stdio.h>
#include<stdlib.h>
#include "HashTable_oper.h"
#include "tool_base.h"

int hashsize = 18;
int hashxx,m;

/*  构造
 *  H为哈希表             *
 *  构造一个空的哈希表    *
 */
Status InitHash(HashTable & H)
{
	H.elem = (ElemType *)malloc(hashsize * sizeof(ElemType));
	H.count = 0;
	H.sizeindex = hashsize;
	
	if (!H.elem)
		exit(ERROR);

	for (int i = 0;i < hashsize;i++)
		H.elem[i].key = NULLKEY;

	return OK;
}

/*  构造
 *                         *
 */
void CreatHash(HashTable &H,double &C)
{
	int x = 12;
	ElemType e[20];
	
	Pos(8, 28);
	printf("测试数据{19 38 12 40 41 39 54 76 35 47 80 14 9 45 60}\n");
	Pos(10, 42);
	printf("请输入输入元素数：");
	scanf_s("%d", &m);
	
	Posx(x, 26);
	printf("请录入数据:");

	for (int i = 0;i < m;i++) {
		
		e[i].datachar = '0';
		e[i].dataint = 0;

		scanf_s("%d", &e[i].key);
	}
	x++;
	Posx(x, 26);
	printf("请输入哈希函数: key MOD ");
	scanf_s("%d", &hashxx);

	C = m;
	for(int i = 0;i<m;i++)
		InsertHash(H, e[i],C);
}


/*  销毁
 *  H为哈希表             *
 *  销毁哈希表            *
 */
void DestoryHash(HashTable & H)
{
	free(H.elem);
	H.elem = NULL;
	H.count = 0;
	H.sizeindex = 0;
}

/*  哈希函数
 *  K为关键字             *
 *  计算的哈希地址        *
 */
int Hash(KeyType K)
{
	return K % hashxx;
}

/*  冲突
 *  p为哈希地址           *
 *  c为冲突次数           *
 *  线性探测散列          *
 */
int collision(int p, int c)
{
	return p = (p + c) % hashxx;
}

/*  查找
 *  H为哈希表，p为哈希地址*
 *  K为关键字，c为冲突次数*
 *  查找关键字应该插入地址*
 */
Status SearchHash(HashTable H, KeyType K, int & p, int & c)
{
	//获取哈希地址
	p = Hash(K);
	//若该位置有记录，且关键字并不相等，则求下一探查地址
	while (H.elem[p].key != NULLKEY && !(K == H.elem[p].key)) {
		p = collision(p, 1);
		++c;
	}
	//查找成功返回地址
	if (K == H.elem[p].key)
		return SUCCESS;
	//查找失败返回插入位置
	else
		return UNSUCCESS;
}



/*  插入
 *  H为哈希表             *
 *  e为数据元素           *
 *  将数据元素插入哈希表  *
 */
Status InsertHash(HashTable & H, ElemType e,double &C)
{
	int c = 0,p = 0;
	
	if (SearchHash(H, e.key, p, c))
		return DUPLICATE;
	else {
		H.elem[p] = e;
		++H.count;
		C += c;
		return OK;
	}
}

void CreatHashList(HashTableList HL[],int &n)
{
	
	int x = 12;
	ElemType e[20];

	Pos(8, 28);
	printf("测试数据{19 38 12 40 41 39 54 76 35 47 80 14 9 45 60}\n");
	Pos(10, 42);
	printf("请输入输入元素数：");
	scanf_s("%d", &m);

	Posx(x, 32);
	printf("请输入输入哈希链表数组大小：");
	scanf_s("%d", &n);

	x++;
	Posx(x, 26);
	printf("请录入数据:");


	for (int i = 0;i < m;i++) {

		e[i].datachar = '0';
		e[i].dataint = 0;

		scanf_s("%d", &e[i].key);
	}

	x++;
	Posx(x, 26);
	printf("请输入哈希函数: key MOD ");
	scanf_s("%d", &hashxx);

	for (int i = 0;i < n;i++) {
		if (!(HL[i] = (HashTableNode *)malloc(hashsize * sizeof(HashTableNode))))   //为结点分配空间
			exit(OVERFLOW);
		HL[i]->next = NULL;
		HL[i]->data.key = NULLKEY;
	}

	for (int i = 0;i < m;i++)
		InsertListHash(HL, e[i]);
		
}

void DestoryHashList(HashTableList HL[],int n)
{
	HashTableList p, q;
	for (int i = 0;i < n;i++) {
		if (HL[i]->next)
			for (p = HL[i];p;p = p->next) {
				q = p;
				free(q);
				q->next = NULL;
			}

	}
}

Status InsertListHash(HashTableList HL[], ElemType e)
{
	HashTableList s,q;
	int c = 0, p = 0;
	
	p = Hash(e.key);
	
	for (q = HL[p];q->next != NULL && q->next->data.key > e.key;q = q->next);

	if (!(s = (HashTableNode *)malloc(hashsize * sizeof(HashTableNode))))   //为结点分配空间
		exit(OVERFLOW);
	s->next = NULL;

	s->data = e;

	s->next = q->next;
	q->next = s;


	return OK;
}

Status HashTraverse(HashTable H, Status(*Visit)(ElemType e),double C)
{
	int i;
	double ASL;
	printf("地址    ");
	for (i = 0;i < H.sizeindex;i++)
		printf("%3d", i);
	printf("\n");
	printf("关键字  ");
	for (i = 0;i < H.sizeindex;i++)
		Visit(H.elem[i]);

	printf("\n");
	ASL = C / m;
	printf("ASL(%d) = %.2f", m, ASL);
	return OK;
}

Status HashTraverseList(HashTableList HL[], Status(*Visit)(ElemType e),int n)
{
	HashTableList p;
	
	double C = 0, ASL;
	for (int i = 0;i < n;i++) {
		if (HL[i]->next) {
			printf("第%2d链表：", i);
			int k;
			for (p = HL[i], k = 0;p;p = p->next,k++)
				if (p->data.key != NULLKEY) {
					Visit(p->data);
					C += k;
				}
			printf("\n");
		}
	
	}

	ASL = C / m;
	printf("ASL(%d) = %.2f", m, ASL);
	return OK;
}


Status PrintKey(ElemType e)
{
	printf("%3d", e.key);

	return OK;
}


