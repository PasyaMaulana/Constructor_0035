#include <iostream>
#include <string>
using namespace std;

class Dosen;
class Staff;
class Universitas;
class Mahasiswa
{
private:
    float nilai;

public:
    string nama;
    string NIM;

    Mahasiswa(string nama, string NIM) : nama(nama), NIM(NIM), nilai(0) {}

    void tampilkanMahasiswa()
    {
        cout << "Mahasiswa: " << nama << endl;
        cout << "NIM: " << NIM << endl;
        cout << "Nilai: " << nilai << endl;
        cout << endl;
    }

    friend class Dosen;
};

class Dosen
{
private:
    string pangkat;
    int gaji;

    friend class Staff;
    friend float lihatGajiDosen(Dosen *d);

public:
    string nama;
    string NIDN;

    Dosen(string nama, string NIDN, string pangkat, int gaji) : nama(nama), NIDN(NIDN), pangkat(pangkat), gaji(gaji) {}

    void beriNilai(Mahasiswa *m, float nilai)
    {
        m->nilai = nilai;
    }

    void tampilkanDosen()
    {
        cout << "Dosen: " << nama << endl;
        cout << "NIDN: " << NIDN << endl;
        cout << "Pangkat: " << pangkat << endl;
        cout << "Gaji: Rp." << gaji << endl;
        cout << endl;
    }
};

class Staff
{
private:
    int gaji;

public:
    string nama;
    string idStaff;

    Staff(string nama, string idStaff, int gaji) : nama(nama), idStaff(idStaff), gaji(gaji) {}

    void ubahPangkat(Dosen *d, string pangkatBaru)
    {
        d->pangkat = pangkatBaru;
    }

    void tampilkanStaff()
    {
        cout << "Staff: " << nama << endl;
        cout << "ID: " << idStaff << endl;
        cout << "Gaji: Rp." << gaji << endl;
        cout << endl;
    }

    friend float lihatGajiStaff(Staff *s);
};

class Universitas
{
public:
    void cekGajiDosen(Dosen *d)
    {
        cout << "Gaji Dosen: " << lihatGajiDosen(d) << endl;
    }

    void cekGajiStaff(Staff *s)
    {
        cout << "Gaji Staff: " << lihatGajiStaff(s) << endl;
    }
};

float lihatGajiDosen(Dosen *d)
{
    return d->gaji;
}

float lihatGajiStaff(Staff *s)
{
    return s->gaji;
}

int main()
{
    Mahasiswa m1("Pasya Achmadinedja Maulana", "20240140035");
    Dosen d1("Ir. Haris Setyawan, S.T., M.Eng", "D-01", "Asisten Ahli", 15000000);
    Staff s1("Asep Ramadhan", "ST-01", 5000000);
    Universitas u;

    d1.beriNilai(&m1, 92.5);
    m1.tampilkanMahasiswa();

    d1.tampilkanDosen();
    s1.tampilkanStaff();

    s1.ubahPangkat(&d1, "Lektor");
    d1.tampilkanDosen();

    return 0;
}