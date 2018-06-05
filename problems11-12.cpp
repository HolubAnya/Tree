#include "tree.cpp"
#include <cmath>

template <class T>
void Tree<T>::Task11(const T &elem, const T &elem2, Node* current)
{
    if (current == NULL) 
        return; 
	Task11(elem, current->left); //обхід дерева
	Task11(elem, current->right);
	
    char intStr[3];
    sprintf(intStr, "%d", current->data); //видалення нащадка, якщо сума його цифр знаходиться в інтрвалі
    int digit = 0;
    int sum = 0;
	for (int i = 0; i < 3; i++)
	{
		digit = (int)intStr[i] - (int)'0';
        sum = sum + digit;
        if (sum < elem2 && sum > elem) 
            Remove(current->data);
    
	}
    return;
}

template <class T>
void Tree<T>::Task12(Node* current)
{
    if (current == NULL) 
        return; 
	Task12(current->left); //обхід дерева
	Task12(current->right);      //видалення нащадка, якщо його квадратній корінь є цілим числом
    double sq = sqrt(current->data);
    int sqi = int(sq);
    if (sq == sqi) 
        Remove(current->data);
    return;
}