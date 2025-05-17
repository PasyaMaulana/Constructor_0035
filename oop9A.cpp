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