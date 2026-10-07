#include <iostream>
#include <string>
using namespace std;

// Câu 1: 
struct KhachHang
{
    int maKH;
    string tenKH;
    string soDienThoai;
    double tongTienThanhToan;
};

// Câu 2: 
void nhap(KhachHang a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "\nNhap khach hang thu " << i + 1 << ":\n";

        cout << "Ma khach hang: ";
        cin >> a[i].maKH;
        cin.ignore();

        cout << "Ten khach hang: ";
        getline(cin, a[i].tenKH);

        cout << "So dien thoai: ";
        getline(cin, a[i].soDienThoai);

        cout << "Tong tien thanh toan: ";
        cin >> a[i].tongTienThanhToan;
    }
}

// Câu 3:
void xuat(KhachHang a[], int n)
{
    cout << "\n===== DANH SACH KHACH HANG =====\n";

    for (int i = 0; i < n; i++)
    {
        cout << "\nKhach hang thu " << i + 1 << ":\n";
        cout << "Ma KH: " << a[i].maKH << endl;
        cout << "Ten KH: " << a[i].tenKH << endl;
        cout << "So dien thoai: " << a[i].soDienThoai << endl;
        cout << "Tong tien thanh toan: "
             << a[i].tongTienThanhToan << endl;
    }
}

// Câu 4:
void insertionSort(KhachHang a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        KhachHang x = a[i];
        int j = i - 1;

        while (j >= 0 &&
               a[j].tongTienThanhToan > x.tongTienThanhToan)
        {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = x;
    }
}

// Câu 5: 
void timKiemNhiPhan(KhachHang a[], int n, double X)
{
    int left = 0;
    int right = n - 1;
    bool timThay = false;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (a[mid].tongTienThanhToan == X)
        {
            
            int i = mid;

            while (i >= 0 &&
                   a[i].tongTienThanhToan == X)
            {
                i--;
            }

            i++;

            cout << "\n===== KHACH HANG CO TONG TIEN = " << X << " =====\n";

            while (i < n &&
                   a[i].tongTienThanhToan == X)
            {
                cout << "\nMa KH: " << a[i].maKH << endl;
                cout << "Ten KH: " << a[i].tenKH << endl;
                cout << "So dien thoai: " << a[i].soDienThoai << endl;
                cout << "Tong tien: "
                     << a[i].tongTienThanhToan << endl;

                timThay = true;
                i++;
            }

            break;
        }
        else if (a[mid].tongTienThanhToan < X)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    if (!timThay)
    {
        cout << "\nKhong tim thay khach hang co tong tien = "
             << X << endl;
    }
}

// Câu 6: Hàm main
int main()
{
    int n;
    KhachHang a[100];

    cout << "Nhap so luong khach hang n = ";
    cin >> n;

    nhap(a, n);

    cout << "\n\nDANH SACH VUA NHAP:";
    xuat(a, n);

    insertionSort(a, n);

    cout << "\n\nDANH SACH SAU KHI SAP XEP:";
    xuat(a, n);

    double X;
    cout << "\nNhap tong tien X can tim: ";
    cin >> X;

    timKiemNhiPhan(a, n, X);

    return 0;
}
