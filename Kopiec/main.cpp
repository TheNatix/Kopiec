#include <iostream>

using namespace std;

void array_pop(int* tab, int& size); // Definiuje funckje aby potem nie musiec zmieniac kolejnosci 
void array_print(int* tab, int size);
void heap_sort(int*& heap, int& size);
void heap_pop(int*& heap, int& size);
void heapify(int*& heap, int size);
void swapDown(int*& heap, int i, int size);
void heap_insert(int*& heap, int& size, int element);


void array_pop(int* tab, int& size) // Usuwamy 1 elemetent tablicy przez przesuniecie w lewo i zmniejszenie rozmiaru tablicy
{
	for (int i = 0; i < size - 1; i++)
	{
		tab[i] = tab[i + 1];
	}
	size--;
	int* newTab = new int[size];
	tab = newTab;

}
void array_print(int* tab, int size) { // Drukujemy tablice
	for (int i = 0; i < size; i++) cout << tab[i] << " ";
	cout << endl;
}
void heap_sort(int*& heap, int& size) { // Najpeirw uzuwamy heapify aby na korzeniu miec najwieksza wartosc a potem drukujemy korzen
	heapify(heap, size);				// pozniej uzuwamy heap_pop aby usunac korzen(heap[0]) i uzywamy heapify aby znowu miec najwieksza wartosc w korzeniu
	while (size != 0) {
		cout << heap[0] << " ";
		heap_pop(heap, size);
		heapify(heap, size);
	}
}
void heap_pop(int*& heap, int& size) { // W miejsce korzenia przypisujemy ostatni element tablicy zmiejszamy rozmiar i uzywamy heapify aby otrzymac tabliuce odpowiadajaca strukturze kopca
	heap[0] = heap[size - 1];
	size--;
	int* newHeap = new int[size];
	for (int i = 0; i < size; i++) newHeap[i] = heap[i];
	heap = newHeap;
	heapify(heap, size);
}
void heapify(int*& heap, int size) { // Wywolujemy swapDown w petli aby uzyskac strukure kopca
	for (int i = size / 2; i >= 0; i--) swapDown(heap, i, size);
}
void swapDown(int*& heap, int i, int size) { // Najpierw sprawdzamy czy left i right nie wychodza poza tablice i czy ich wartosc nie jest wieksza of wartosci heap[max]
	int max = i;							 // Pozniej wykonujemy swapa i wywolujemy ponownie swapDown ale przekazujemy max jako argument funnkcji i 
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	if (left<size && heap[left] > heap[max]) max = left;
	if (right<size && heap[right]>heap[max]) max = right;
	if (max != i)
	{
		int temp = heap[max];
		heap[max] = heap[i];
		heap[i] = temp;
		swapDown(heap, max, size);
	}
}
void heap_insert(int*& heap, int& size, int element) { // Zwiekszamy rozmiar przepisujemy do heapDown plus dopisujemy element ktory dodajemy podajemy heapDown do heap
	size++;											   // Pozniej odbywa sie wedrowka elementu do gory ktory mozej dojsc na szczyt(1  warunek w while) 
	int *newHeap = new int[size];					   // lub w razie napotkania > lub == rodzica (2 waruenk)
	for (int i = 0; i < size - 1; i++) newHeap[i] = heap[i];
	newHeap[size - 1] = element;
	
	heap = newHeap;
	int i = size - 1,parent = (i-1)/2;
	while (i>0 && heap[i]>heap[parent])
	{
		parent = (i - 1) / 2;
		int temp = heap[i];
		heap[i] = heap[parent];
		heap[parent] = temp;
		i = parent;
	}
}
int main() {
	int tab[] = { 2,1,3,25,17,39,12 };
	int size = 7;
	int* t = tab;
	array_print(tab, size);
	heap_insert(t, size, 33);
	array_print(t, size);
	heap_sort(t, size);
	
	return 0;
}