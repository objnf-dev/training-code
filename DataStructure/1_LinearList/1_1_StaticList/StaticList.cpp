#include "StaticList.h"

SqList* init_list()
{
   ElementType *listData = new ElementType[INITSIZE];
   SqList *newList = new SqList{listData, INITSIZE, 0};
   return newList;
}

void destroy_list(SqList **sqList)
{
    delete (*sqList)->data;
    delete *sqList;
    return;
}

// 插入
int insert_element(SqList *sqList, ElementType data)
{
    if (check_list_full(sqList)) {
        return 1;
    }

    sqList->data[sqList->length] = data;
    sqList->length++;
    return 0;
}

// 删除，pos为下标，下同
int delete_element(SqList *sqList, int pos)
{
    // pos不合法
    if (pos < 0 || pos >= sqList->length) {
        return 1;
    }
    sqList->length--;
    for(int i = pos; i < sqList->length; i++) {
        sqList->data[i + 1] = sqList->data[i];
    }
    return 0;
}

// 按位查找
int search_by_position(SqList *sqList, int pos, ElementType *data)
{
    // pos不合法
    if (pos < 0 || pos >= sqList->length) {
        return 1;
    }

    *data = sqList->data[pos];
    return 0;
}

// 按值查找
int search_by_value(SqList *sqList, ElementType data, int *pos)
{
    for (int i = 0; i < sqList->length; i++) {
        if (sqList->data[i] == data) {
            *pos = i;
            return 0;
        }
    }
    return 1;
}

// 长度扩展
int expand_list(SqList *sqList, int length)
{
    // 指定长度小于数据长度
    if (length < sqList->length) {
        return 1;
    }

    ElementType *newData = new ElementType[length];
    // 考试要求：不使用std::copy
    // std::copy(sqList->data, (sqList->data) + sqList->length, newData);

}

// 判空
bool check_list_empty(SqList *sqList)
{
    if (sqList->length) {
        return false;
    }
    return true;
}

// 判满
bool check_list_full(SqList *sqList)
{
    if(sqList->length == sqList->size) {
        return true;
    }
    return false;
}

// 非标准：求表长
int get_list_length(SqList *sqList)
{
    return sqList->length;
}

// 非标准：遍历输出
void print_list(SqList *sqList)
{
    for (int i = 0; i < sqList->length; i++) {
        std::cout << sqList->data[i] << " ";
    }
    std::cout << std::endl;
    return;
}
