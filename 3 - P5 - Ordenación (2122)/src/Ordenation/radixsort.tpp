#ifndef RADIXSORT_H
#define RADIXSORT_H

#include <iomanip> // setw
#include <algorithm> // copy
#include <iterator> // back_inserter
#include "../Auxiliar/array.tpp"
#include "../Auxiliar/traza.inl"

using namespace std;
/////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                             //
//                                 FUNCIÓN RADIXSORT                                           //
//                                                                                             //
/////////////////////////////////////////////////////////////////////////////////////////////////

template<class Key>
size_t Max(Array<Key>& a, size_t n)
{
    size_t m = 0;
    for (auto i = 0; i < n; ++i)
        if (a[i] > a[m])
            m = i;
    return m;
}

template<class Key>
void countSort(Array<Key>& a, int n, int exp)
{
	// array que contendrá el número de elementos que tienen el dígito 'i' en la posición (exp)
	Array<Key> output(n);
    int count[10] = {0};
 
	// cuenta el número de veces que aparece cada dígito en la posición exp
	for (int i = 0; i <  n; i++) count[(a[i]/exp) % 10]++; 
	for (int i = 1; i < 10; i++) count[i] += count[i-1]; // cálculo de su recuento acumulado
	
 
	// Insertando los valores de acuerdo al dígito obtenido en count[(a[i] / exp) % 10].
	for (int i = n - 1; i >= 0; i--) {
		cout << endl; traza(a,-1,-1,i,BOLD_VIOL); cout << " → ";
		int index = count[(a[i]/exp) % 10]-1;
		output[index] = a[i];

		traza(output,-1,index,-1,BOLD_CYAN); 
		count[(a[i]/exp) % 10]--;
	}
 
	// Asignando el resultado a la dirección de memoria del puntero arr de la función principal.
	for (int i = 0; i < n; i++) {	
		a[i] = output[i];
	}
		
}
 
// Sort a[] of size n using Radix Sort.
template<class Key>
Array<Key> RadixSort(Array<Key>& a, size_t sz = 0) {
    sz = (sz == 0) ? a.size() : sz;
	int div, max_pos;
	max_pos = Max(a, sz);
	// Llama a countSort() para cada dígito en la posición exp
	for(div = 1; a[max_pos]/div > 0; div *= 10) countSort(a, sz, div);
    return a;
}

#endif