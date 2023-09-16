/*ʵ���������嵥����ʽ��ʾ
���ǽ�ʹ�� C ��������ʾ�����嵥����ʽ��ʾ�����ȶ���һ������ڵ�ṹ����ʾÿ����
���嵥�
struct ShoppingItem {
 char name[50]; // ��Ʒ����
 int quantity; // ��Ʒ����
 struct ShoppingItem* next; // ָ����һ���ڵ��ָ��
};
Ȼ�����Ǵ���һ������ͷָ�룬��ʾ�����嵥����ʼ�㣺
struct ShoppingItem* shoppingList = NULL; // ��ʼ�������嵥Ϊ��
1. �����Ʒ�������嵥��*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
const int N = 50 ,M = 2000;
typedef struct ShoppingItem 
{
 char name[50]; // ��Ʒ����
 int quantity; // ��Ʒ����
 struct ShoppingItem* next; // ָ����һ���ڵ��ָ��
}shangping;
//Ȼ�����Ǵ���һ������ͷָ�룬��ʾ�����嵥����ʼ�㣺
//struct ShoppingItem* shoppingList = NULL; // ��ʼ�������嵥Ϊ��
//��������ͷָ���ʾ����ĳ�ʼ
shangping *shoppinglist = NULL;
shangping *shoppinglist2 = NULL;


//1. �����Ʒ�������嵥��
void addItem(char itemName[], int itemQuantity) 
{
 shangping *newItem = (shangping *)malloc(sizeof(shangping));
 
//ͷ�巨����������
strcpy(newItem->name, itemName);
newItem -> quantity = itemQuantity;
if(shoppinglist == NULL)
{
	shoppinglist = newItem;
	newItem->next = NULL;
    shoppinglist->next = NULL;
}
else
	{
		newItem->next = shoppinglist;
        shoppinglist = newItem;
	}
}
//2. �ӹ����嵥���Ƴ���Ʒ��
void removeitem(char itemName[]) 
{
	shangping * previous = NULL;
shangping * current = shoppinglist;


 while (current != NULL) {
 if (strcmp(current->name, itemName) == 0) {
 if (previous != NULL) {
 previous->next = current->next;
 } 
 else 
 {
 shoppinglist = current->next;
 }
 free(current);
 break;
 }
previous = current;
current = current->next;
 }
}

//3. �鿴�����嵥��
void displaylist() {
 struct ShoppingItem* current = shoppinglist;
 printf("�����嵥:\n");
 while (current != NULL) {
 printf("%s - ������%d\n", current->name, current->quantity);
 current  =  current ->next;
 }
}
//4. �޸Ĺ����嵥����Ʒ��������
void updatequantity(char itemName[], int newItemQuantity) 
{
 struct ShoppingItem* current = shoppinglist;
 while (current != NULL) 
 {
 if (strcmp(current->name, itemName) == 0) 
 {
 current = current -> next;
 break;
 }
 current = current->next;
 }
}
//5. ��չ����嵥��
void clearlist() 
{
 while (shoppinglist != NULL) 
 {
 shangping *temp = shoppinglist;
 shoppinglist - shoppinglist -> next;
 free(temp);
 }
}
//6. ���㹺���嵥����Ʒ����������
int totalquantity() 
{
 struct ShoppingItem* current = shoppinglist;
 int total = 0;
 while (current != NULL) 
 {
 current = current->next;
 total ++;
 }
 return total;
}
//7. ���ҹ����嵥�е���Ʒ��
void finditem(char itemName[]) 
{
 shangping * current = shoppinglist;
 printf("������Ʒ \"%s\" ��\n", itemName);
 while (current != NULL) {
 if (strcmp(current->name, itemName) == 0) 
 {
 printf("%s - ������%d\n", current->name, current->quantity);
 return;
 }
 current = current ->next;
 }
 printf("δ�ҵ���Ʒ \"%s\"��\n", itemName);
}
//8. �������嵥��
void sortlist() {
	shangping *current = shoppinglist;
    shangping *nextItem = NULL;
 char tempName[50];
 int tempQuantity;
 while (current != NULL) 
 {
 nextItem = current->next;
 while (nextItem != NULL) 
 {
 if (strcmp(current->name, nextItem->name) > 0) 
 	{
 // ������Ʒ��Ϣ
 strcpy(tempName, current->name);
	strcpy(current->name, nextItem->name);
 	strcpy(nextItem->name, tempName);
	tempQuantity = current->quantity;
	current->quantity = nextItem->quantity;
	nextItem->quantity = tempQuantity;
 		tempQuantity = current->quantity;
 			current->quantity = nextItem->quantity;
 				nextItem->quantity = tempQuantity;
 	}
 nextItem = nextItem->next;
 }
 current = current->next;
 }
}
//9. �ϲ������嵥��
//��������������ͬ�Ĺ����嵥����ϣ�������Ǻϲ���һ����
void mergelists(shangping *list1, shangping *list2) {
 shangping *current = list1;

 // ��������һ�������嵥��ĩβ
 while(current->next!=NULL){
 	current = current->next;
 }
 // ���ڶ��������嵥���ӵ���һ���嵥��ĩβ
 current->next = list2;
 list2 = NULL; // ��յڶ��������嵥��ͷָ�룬��ֹ����
}
//10. ɾ�������嵥�е���Ʒ��
//ʵ��һ�����������Ը�����Ʒ����ɾ�������嵥�е���Ʒ�����ж����ͬ���Ƶ���Ʒ��
//����ѡ��ɾ������һ����ȫ����
void deleteItem(char itemName[], int deleteAll) {
 struct ShoppingItem* current = shoppinglist;
 struct ShoppingItem* prev = NULL;
 while (current != NULL) {
 if (strcmp(current->name, itemName) == 0) {
 if (prev == NULL) {
 // ���Ҫɾ�����ǵ�һ���ڵ�
 shangping * temp = shoppinglist;
 current = shoppinglist ;
  shoppinglist = shoppinglist->next;
 free(temp);
 if (!deleteAll) break;
 }
  else 
 {
 // ���Ҫɾ���Ĳ��ǵ�һ���ڵ�
 prev->next = current->next;
 free(current);
 current = prev->next;
 if (!deleteAll) break;
 }
 } else {
 prev = current;
 current = current->next;
 }
 }
}
int main()
{
    printf("������Ʒ��Ŀ��\n");
    int n;//��Ʒ��Ŀ
    char itemname[M][N];//��Ʒ����
    int itemcnt; //��Ʒ��Ŀ
    scanf("%d", &n);
    for (int i = 0; i < n; i ++ ) 
    {    
        scanf("%s%d", itemname[i], &itemcnt);
        addItem(itemname[i], itemcnt);
    }
    
    //�鿴�����嵥��
    displaylist();
    printf("\n");

    //ɾ����1����Ʒ
    printf("ɾ����[1]��Ʒ:\n");
    removeitem(itemname[1]);
    //�鿴�����嵥��
    displaylist();
    printf("\n");
    //�ѵ�0����Ʒ������Ϊ100;
    printf("�ѵ�0����Ʒ������Ϊ100\n");
    updatequantity(itemname[0], 100);
    //�鿴�����嵥��
    displaylist();
    printf("\n");    
    printf("���㹺����������� = %d\n", totalquantity());
    printf("����3��Ʒ:\n");
    finditem(itemname[3]);
    printf("����");
    sortlist();
    //�鿴�����嵥��
    displaylist();
    printf("\n");    
    printf("����2:\n");
    for (int i = 0; i < 3; i ++)
        addItem(itemname[0], 3);
    shangping *list1 = shoppinglist, *list2 = shoppinglist2;
    printf("�ϲ�1��2:\n");
    mergelists(list1, list2);
    //�鿴�����嵥��
    displaylist();
    printf("\n");    
    printf("ɾ����������Ϊitemname[0]����Ʒ\n");
    deleteItem(itemname[0], 1);
    //�鿴�����嵥��
    displaylist();
    printf("\n");      
    printf ("���: \n");
    clearlist();
    //�鿴�����嵥��
    displaylist();
    printf("\n");     
    return 0;
}
