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
    sprintf(intStr, "%d", current->data); //переводимо елементи в строки
    int digit = 0;
    int sum = 0;
	for (int i = 0; i < 3; i++) //циклічно
	{
		digit = (int)intStr[i] - (int)'0'; //перебираємо кожену цифру елемента
        sum = sum + digit; //знаходмимо суму цифр елемента
        if (sum < elem2 && sum > elem) //видалення нащадка, якщо сума його цифр знаходиться в інтрвалі
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
	Task12(current->right);     
    double sq = sqrt(current->data);  //знаходимо квадратний корінь елемента
    int sqi = int(sq);  //створюємо змінну цілого значення, яке відповідає кореню елемента
    if (sq == sqi) //порівнюємо ці змінні
        Remove(current->data);  //видалення нащадка, якщо його квадратній корінь є цілим числом
    return;
}
