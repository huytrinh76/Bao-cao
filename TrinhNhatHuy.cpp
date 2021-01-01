//Trinh Nhat Huy MSV: 18810310496
#include<iostream>
using namespace std;
struct sach{
	int masach;
	char tensach[50];
	int nxb;
	int gia;
};
void nhap(sach a[], int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<"nhap thong tin sach thu "<<i+1<<" "<<endl;
		cout<<"nhap ma sach: ";
		cin>>a[i].masach;
		cout<<"nhap ten sach: ";
		fflush(stdin);
		gets(a[i].tensach);
		cout<<"nhap nam xuat ban: ";
		cin>>a[i].nxb;
		cout<<"nhap gia: ";
		cin>>a[i].gia;
	}

}
void xuat(sach a[], int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<"Danh sach thu "<<i+1<<" la: "<<endl;
		cout<<"Ma sach: "<<a[i].masach<<endl;
		cout<<"Ten sach: "<<a[i].tensach<<endl;
		cout<<"Nam xuat ban: "<<a[i].nxb<<endl;
		cout<<"Gia thanh: "<<a[i].gia<<endl;
	}
}
void QuickSort(sach a[], int left, int right)
{
	
	int i = left, j = right;
	int x = a[(left + right)/2].gia;
	do{
		while(a[i].gia < x) i++;
		while(a[j].gia > x) j--;
		if(i<=j)
		{
			sach tg = a[i];
			a[i] = a[j];
			a[j] = tg;
			i++;
			j--;
		}
	}while(i<j);
	if(left < j)
	{
		QuickSort(a,left,j);	
	}
	if(i < right)
	{
		QuickSort(a,i,right);	
	}
	
}
int main()
{
	sach a[100];
	int n;
	cout<<"Nhap so luong sach: ";
	cin>>n;
	nhap(a,n);
	cout<<"<==========================>"<<endl;
	cout<<"Danh sach da nhap la: "<<endl;
	xuat(a,n);
	cout<<"<==========================>"<<endl;
	cout<<"Sap xep theo QuickSort la: "<<endl;
	QuickSort(a,0,n-1);
	xuat(a,n);
}
