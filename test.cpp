#include <iostream>
#include <cstring>
using namespace std;

class Nhanvien
{
private:
    char *Manv;
    char *Hoten;
    int Sdt;

public:
    Nhanvien *next;
    Nhanvien(char *manv, char *hoten, int sdt)
    {
        Manv = new char[strlen(manv) + 1];
        strcpy(Manv, manv);

        Hoten = new char[strlen(hoten) + 1];
        strcpy(Hoten, hoten);

        Sdt = sdt;

        next = NULL; // Thay thế nullptr bằng NULL
    }

    ~Nhanvien()
    {
        delete[] Manv;
        delete[] Hoten;
    }

    char *GetHoten()
    {
        return Hoten;
    }

    char *GetManv()
    {
        return Manv;
    }

    int GetSdt()
    {
        return Sdt;
    }
};

class Quanly
{
private:
    Nhanvien *first;

public:
    Quanly()
    {
        first = NULL; // Thay thế nullptr bằng NULL
    }
    void Nhap();
    void SapXep();
    Nhanvien *TimKiemTheoMa(char *manv);
    void Xuat();
};

void Quanly::Nhap()
{
    char manv[100];
    char hoten[100];
    int sdt;

    while (true)
    {
        cout << "Nhap ma nhan vien ( nhap rong de ket thuc qua trinh nhap) :";
        cin.getline(manv, 100);

        if (strlen(manv) == 0)
        {
            break;
        }

        cout << "Nhap ho ten: ";
        cin.getline(hoten, 100);
        cin.ignore(); // Thêm dòng này để xóa kí tự xuống dòng dư thừa

        cout << "Nhap so dien thoai: ";
        cin >> sdt;
        cin.ignore(); // Thêm dòng này để xóa kí tự xuống dòng dư thừa

        Nhanvien *nv = new Nhanvien(manv, hoten, sdt);
        if (first == NULL)
        {
            first = nv;
        }
        else
        {
            Nhanvien *temp = first;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = nv;
        }
    }
}

void Quanly::SapXep()
{
    if (first == NULL)
    {
        return;
    }

    bool swapped;
    Nhanvien *ptr1;
    Nhanvien *lptr = NULL;

    do
    {
        swapped = false;
        ptr1 = first;

        while (ptr1->next != lptr)
        {
            if (strcmp(ptr1->GetHoten(), ptr1->next->GetHoten()) > 0)
            {
                swap(ptr1, ptr1->next);
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

Nhanvien *Quanly::TimKiemTheoMa(char *manv)
{
    Nhanvien *temp = first;

    while (temp != NULL)
    {
        if (strcmp(temp->GetManv(), manv) == 0)
        {
            return temp;
        }
        temp = temp->next;
    }

    return NULL;
}

void Quanly::Xuat()
{
    Nhanvien *temp = first;

    while (temp != NULL)
    {
        cout << " Ma nhan vien: " << temp->GetManv() << endl;
        cout << " Ho ten: " << temp->GetHoten() << endl;
        cout << " So dien thoai: " << temp->GetSdt() << endl;
        cout << endl;

        temp = temp->next;
    }
}

int main()
{
    Quanly ql;

    cout << " Nhap du lieu cho danh sach nhan vien: " << endl;

    ql.Nhap();

    cout << endl << " Danh sach nhan vien truoc khi sap xep:" << endl;
    ql.Xuat();

    ql.SapXep();
    cout << endl << " Danh sach nhan vien sau khi sap xep: " << endl;
    ql.Xuat();

    char manvTiemKiem[100];
    cout << endl << " Nhap ma nhan vien can tim kiem:" << endl;
    cin.getline(manvTiemKiem, 100);
    Nhanvien *nvTimKiem = ql.TimKiemTheoMa(manvTiemKiem);
    if (nvTimKiem != NULL)
    {
        cout << "Thong tin nhan vien co ma " << manvTiemKiem << ":" << endl;
        cout << "Ho ten: " << nvTimKiem->GetHoten() << endl;
        cout << "So dien thoai: " << nvTimKiem->GetSdt() << endl;
    }
    else
    {
        cout << "Khong tim thay nhan vien co ma " << manvTiemKiem << endl;
    }

    return 0;
}