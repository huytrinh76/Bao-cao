#include<iostream>
using namespace std;
struct sach{
	int masach;
	char tensach[50];
	int nxb;
	int gia;
};
void nhap(sach m[], int n){
	for(int i=0;i<n;i++){
		cout<<"Nhap thong tin sach thu "<<i+1<<" "<<endl;
		cout<<"Nhap ma sach: ";
		cin>>m[i].masach;
		cout<<"Nhap ten sach: ";
		fflush(stdin);
		gets(m[i].tensach);
		cout<<"Nhap nam xuat ban: ";
		cin>>m[i].nxb;
		cout<<"Nhap gia thanh: ";
		cin>>m[i].gia;
	}

}
void xuat(sach m[], int n){
	for(int i=0;i<n;i++){
		cout<<"Danh sach thu "<<i+1<<" la: "<<endl;
		cout<<"Ma sach: "<<m[i].masach<<endl;
		cout<<"Ten sach: "<<m[i].tensach<<endl;
		cout<<"Nam xuat ban: "<<m[i].nxb<<endl;
		cout<<"Gia thanh: "<<m[i].gia<<endl;
	}
}
void swap(int &a, int &b){
	int tg = a;
	a = b;
	b = tg;
}
void heapify(sach m[], int n, int i)
{
	int largest = i; 
	int left = 2 * i + 1; 
	int right = 2 * i + 2; 
	if (left < n && m[left].gia > m[largest].gia){
		largest = left;
	}
	if (right < n && m[right].gia > m[largest].gia){
		largest = right;
	}
	if (largest != i){
		swap(m[i], m[largest]);
		heapify(m, n, largest);
	}
}
void heapSort(sach m[], int n){
	for (int i = n / 2 - 1; i >= 0; i--){
		heapify(m, n, i);
	}
	for (int i = n - 1; i >= 0; i--){
		swap(m[0], m[i]);
		heapify(m, i, 0);
	}
}
int main()
{
	sach m[100];
	int n;
	cout<<"Nhap so luong sach: ";
	cin>>n;
	nhap(m,n);
	cout<<"=========================="<<endl;
	cout<<"Danh sach da nhap la: "<<endl;
	xuat(m,n);
	cout<<"=========================="<<endl;
	cout<<"Danh sach sap xep theo Heap Sort la: "<<endl;
	heapSort(m,n);
	xuat(m,n);
}
