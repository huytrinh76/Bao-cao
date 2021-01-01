#include<iostream>
using namespace std;
struct sach{
	int masach;
	char tensach[50];
	int nxb;
	int gia;
};
void nhap(sach a[], int n){
	for(int i=0;i<n;i++){
		cout<<"Nhap cuon sach thu "<<i+1<<endl;
		cout<<"Nhap ma sach: ";
		cin>>a[i].masach;
		cout<<"Nhap ten sach: ";
		fflush(stdin);
		gets(a[i].tensach);
		cout<<"Nhap nam xuat ban: ";
		cin>>a[i].nxb;
		cout<<"Nhap gia thanh: ";
		cin>>a[i].gia;
		cout<<"======================="<<endl;
	}
}
void xuat(sach a[], int n){
	for(int i=0;i<n;i++){
		cout<<"Danh sach thu "<<i+1<<endl;
		cout<<"Ma sach: "<<a[i].masach<<endl;
		cout<<"Ten cuon sach: "<<a[i].tensach<<endl;
		cout<<"Nam xuat ban: "<<a[i].nxb<<endl;
		cout<<"Gia cuon sach: "<<a[i].gia<<endl;
		cout<<"========================"<<endl;
	}
}
void sapxep(sach a[], int r, int l){
	int i, j, x;
	x=a[(l+r)/2].gia;
	i=l;j=r;
	do{
		while(a[i].gia<x)i++;
		while(a[i].gia>x)j--;
		if(i<=j){
			sach tg=a[i];
			a[i]=a[j];
			a[j]=tg;
			i++;
			j--;
		}
	}
	while(i<j);
	if(l<j){
	sapxep(a, l, j);
	}
	if(i<r){
	sapxep(a, i, r);
	}
}
int main(){
	sach a[100];
	int n;
	cout<<"Nhap so luong sach: ";
	cin>>n;
	nhap(a, n);
	xuat(a, n);
	cout<<"Danh sach sap xep theo Quick Sort la: "<<endl;
	sapxep(a, 0, n-1);
	xuat(a, n);
}
