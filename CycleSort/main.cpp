#include <iostream>
using namespace std;

void cycleSort (int arr[], int n){
    //Membuat sebuah variabel
	int writes = 0;

	//melintasi elemen array dan meletakkannya
	//di tempat yang tepat
	for (int cycle_start=0; cycle_start<=n-2; cycle_start++){
        //Inisialisasi item sebagai titik awal
		int item = arr[cycle_start];

        //Temukan posisi di mana kita meletakkan item.
        //Kami pada dasarnya hitung semua elemen yang lebih
        //kecil di sisi kanan item.
		int pos = cycle_start;
		for (int i = cycle_start+1; i<n; i++)
			if (arr[i] < item)
				pos++;

        //Jika item sudah berada di posisi yang tepat
		if (pos == cycle_start)
			continue;
        //abaikan semua elemen duplikat
		while (item == arr[pos])
			pos += 1;

        //Meletakkan item pada posisi yang benar
		if (pos != cycle_start)
		{
			swap(item, arr[pos]);
			writes++;
		}
		//Putar sisa siklus
		while (pos != cycle_start)
		{
			pos = cycle_start;
			//Temukan posisi di mana kita meletakkan elemen
			for (int i = cycle_start+1; i<n; i++)
				if (arr[i] < item)
					pos += 1;
            //abaikan semua elemen duplikat
			while (item == arr[pos])
				pos += 1;
            //letakkan item di posisi yang tepat
			if (item != arr[pos])
			{
				swap(item, arr[pos]);
				writes++;
			}
		}
	}
}


int main()
{
    cout << "Sebuah array dengan nilai 1, 8, 3, 9, 10, 10, 2, 4" << endl;
    cout << endl;
	int arr[] = {1, 8, 3, 9, 10, 10, 2, 4 };
	int n = sizeof(arr)/sizeof(arr[0]);
	cycleSort(arr, n) ;

	cout << "Setelah sorting : " <<endl;
	for (int i =0; i<n; i++)
		cout << arr[i] << " ";
	return 0;
}
