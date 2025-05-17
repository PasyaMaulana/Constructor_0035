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