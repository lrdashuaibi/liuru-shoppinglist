/*实例：购物清单的链式表示
我们将使用 C 语言来演示购物清单的链式表示。首先定义一个链表节点结构来表示每个购
物清单项：
struct ShoppingItem {
 char name[50]; // 商品名称
 int quantity; // 商品数量
 struct ShoppingItem* next; // 指向下一个节点的指针
};
然后，我们创建一个链表头指针，表示购物清单的起始点：
struct ShoppingItem* shoppingList = NULL; // 初始化购物清单为空
1. 添加商品到购物清单：*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
const int N = 50 ,M = 2000;
typedef struct ShoppingItem 
{
 char name[50]; // 商品名称
 int quantity; // 商品数量
 struct ShoppingItem* next; // 指向下一个节点的指针
}shangping;
//然后，我们创建一个链表头指针，表示购物清单的起始点：
//struct ShoppingItem* shoppingList = NULL; // 初始化购物清单为空
//创建链表头指针表示购物的初始
shangping *shoppinglist = NULL;
shangping *shoppinglist2 = NULL;


//1. 添加商品到购物清单：
void addItem(char itemName[], int itemQuantity) 
{
 shangping *newItem = (shangping *)malloc(sizeof(shangping));
 
//头插法创建单链表
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
//2. 从购物清单中移除商品：
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

//3. 查看购物清单：
void displaylist() {
 struct ShoppingItem* current = shoppinglist;
 printf("购物清单:\n");
 while (current != NULL) {
 printf("%s - 数量：%d\n", current->name, current->quantity);
 current  =  current ->next;
 }
}
//4. 修改购物清单中商品的数量：
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
//5. 清空购物清单：
void clearlist() 
{
 while (shoppinglist != NULL) 
 {
 shangping *temp = shoppinglist;
 shoppinglist - shoppinglist -> next;
 free(temp);
 }
}
//6. 计算购物清单中商品的总数量：
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
//7. 查找购物清单中的商品：
void finditem(char itemName[]) 
{
 shangping * current = shoppinglist;
 printf("查找商品 \"%s\" ：\n", itemName);
 while (current != NULL) {
 if (strcmp(current->name, itemName) == 0) 
 {
 printf("%s - 数量：%d\n", current->name, current->quantity);
 return;
 }
 current = current ->next;
 }
 printf("未找到商品 \"%s\"。\n", itemName);
}
//8. 排序购物清单：
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
 // 交换商品信息
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
//9. 合并购物清单：
//假设你有两个不同的购物清单，你希望将它们合并成一个。
void mergelists(shangping *list1, shangping *list2) {
 shangping *current = list1;

 // 遍历到第一个购物清单的末尾
 while(current->next!=NULL){
 	current = current->next;
 }
 // 将第二个购物清单连接到第一个清单的末尾
 current->next = list2;
 list2 = NULL; // 清空第二个购物清单的头指针，防止误用
}
//10. 删除购物清单中的商品：
//实现一个函数，可以根据商品名称删除购物清单中的商品项。如果有多个相同名称的商品，
//可以选择删除其中一个或全部。
void deleteItem(char itemName[], int deleteAll) {
 struct ShoppingItem* current = shoppinglist;
 struct ShoppingItem* prev = NULL;
 while (current != NULL) {
 if (strcmp(current->name, itemName) == 0) {
 if (prev == NULL) {
 // 如果要删除的是第一个节点
 shangping * temp = shoppinglist;
 current = shoppinglist ;
  shoppinglist = shoppinglist->next;
 free(temp);
 if (!deleteAll) break;
 }
  else 
 {
 // 如果要删除的不是第一个节点
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
    printf("输入商品数目：\n");
    int n;//商品数目
    char itemname[M][N];//商品名称
    int itemcnt; //商品数目
    scanf("%d", &n);
    for (int i = 0; i < n; i ++ ) 
    {    
        scanf("%s%d", itemname[i], &itemcnt);
        addItem(itemname[i], itemcnt);
    }
    
    //查看购物清单：
    displaylist();
    printf("\n");

    //删掉第1件商品
    printf("删掉第[1]商品:\n");
    removeitem(itemname[1]);
    //查看购物清单：
    displaylist();
    printf("\n");
    //把第0件商品数量改为100;
    printf("把第0件商品数量改为100\n");
    updatequantity(itemname[0], 100);
    //查看购物清单：
    displaylist();
    printf("\n");    
    printf("计算购物清的总数量 = %d\n", totalquantity());
    printf("查找3商品:\n");
    finditem(itemname[3]);
    printf("排序");
    sortlist();
    //查看购物清单：
    displaylist();
    printf("\n");    
    printf("创建2:\n");
    for (int i = 0; i < 3; i ++)
        addItem(itemname[0], 3);
    shangping *list1 = shoppinglist, *list2 = shoppinglist2;
    printf("合并1和2:\n");
    mergelists(list1, list2);
    //查看购物清单：
    displaylist();
    printf("\n");    
    printf("删除所有名称为itemname[0]的商品\n");
    deleteItem(itemname[0], 1);
    //查看购物清单：
    displaylist();
    printf("\n");      
    printf ("清空: \n");
    clearlist();
    //查看购物清单：
    displaylist();
    printf("\n");     
    return 0;
}
