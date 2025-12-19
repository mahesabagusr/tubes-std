# Sistem Manajemen Tournament Esport

Program C++ untuk mengelola tournament esport dengan implementasi Multi-Linked List (MLL) 1-N.

## Struktur Data

### Parent: Tournament

- `tournamentID` (int): ID unik tournament
- `tournamentName` (string): Nama tournament
- `game` (string): Nama game (Mobile Legends, Valorant, dll)
- `startDate` (string): Tanggal mulai (DD/MM/YYYY)
- `endDate` (string): Tanggal selesai (DD/MM/YYYY)
- `totalPrize` (int): Total hadiah dalam dollar
- `firstMatch` (pointer): Pointer ke list match

### Child: Match

- `matchID` (int): ID unik match
- `matchName` (string): Nama match (Grand Final, Semi Final, dll)
- `team1` (string): Nama tim pertama
- `team2` (string): Nama tim kedua
- `scoreTeam1` (int): Skor tim pertama
- `scoreTeam2` (int): Skor tim kedua
- `matchDate` (string): Tanggal match (DD/MM/YYYY)
- `status` (string): Status match (Scheduled/Ongoing/Completed)

## Fitur Program

### 1. CRUD Operations

#### Tournament (Parent)

- **Create**: Tambah tournament baru dengan validasi ID unik
- **Read**: Lihat semua tournament, cari by ID, cari by nama
- **Update**: Update informasi tournament
- **Delete**: Hapus tournament beserta semua match-nya

#### Match (Child)

- **Create**: Tambah match ke tournament tertentu
- **Read**: Lihat semua match dalam tournament, cari match by ID
- **Update**: Update informasi match
- **Delete**: Hapus match dari tournament

### 2. Variasi Search

- **Search Tournament by Game**: Cari tournament berdasarkan nama game
- **Search Match by Team**: Cari semua match yang diikuti tim tertentu
- **Search Match by Status**: Cari match berdasarkan status (Scheduled/Ongoing/Completed)

### 3. Operasi Query & Filter

- **Query by Minimum Prize**: Tampilkan tournament dengan hadiah >= nilai tertentu
- **Show Tournament with Match Count**: Tampilkan tournament dengan jumlah match
- **Query Completed Matches**: Tampilkan semua match yang sudah selesai beserta pemenangnya
- **Query by Date Range**: Tampilkan tournament dalam periode tanggal tertentu
- **Show Matches with High Score**: Tampilkan match dengan total score >= nilai tertentu

### 4. Operasi Statistik

- **Count All Tournaments**: Hitung total tournament
- **Count All Matches**: Hitung total match di semua tournament
- **Count Matches by Tournament**: Hitung match dalam tournament tertentu
- **Max Prize**: Cari tournament dengan hadiah terbesar
- **Min Prize**: Cari tournament dengan hadiah terkecil

## Cara Compile dan Menjalankan

### Windows (MSYS2/MinGW)

```bash
# Compile
g++ -fdiagnostics-color=always -g src\tournament.cpp main.cpp -o bin\app.exe

# Jalankan
.\bin\app.exe
```

### Linux/Mac

```bash
# Compile
g++ -g src/tournament.cpp main.cpp -o bin/app

# Jalankan
./bin/app
```

## Struktur File

```
Tubes-Std/
├── src/
│   ├── tournament.h      # Header file (deklarasi struktur & fungsi)
│   └── tournament.cpp    # Implementation file (definisi fungsi)
├── bin/
│   └── app.exe          # Executable file
├── main.cpp             # Program utama dengan menu interaktif
└── README.md            # Dokumentasi
```

## Data Sample

Program sudah dilengkapi dengan data sample untuk testing:

### Tournament 1: MPL Season 12

- Game: Mobile Legends
- Hadiah: $100,000
- Match:
  - Grand Final: RRQ vs ONIC (3-2, Completed)
  - Semi Final: EVOS vs RRQ (1-3, Completed)

### Tournament 2: VCT Masters

- Game: Valorant
- Hadiah: $250,000
- Match:
  - Quarter Final: PRX vs DRX (2-1, Ongoing)

## Menu Program

### Menu Utama

```
1.  Tambah Tournament Baru
2.  Lihat Semua Tournament
3.  Update Tournament
4.  Hapus Tournament
5.  Cari Tournament by ID
6.  Cari Tournament by Nama
7.  Tambah Match ke Tournament
8.  Lihat Semua Match dalam Tournament
9.  Update Match
10. Hapus Match
11. Cari Match by ID
12. Search Tournament by Game
13. Search Match by Team
14. Search Match by Status
15. Query Tournament by Minimum Prize
16. Show Tournament with Match Count
17. Show Completed Matches
18. Query Tournament by Date Range
19. Show Matches with High Score
20. Show Statistics (Count, Max, Min)
0.  Keluar
```

## Contoh Penggunaan

### Menambah Tournament Baru

1. Pilih menu 1
2. Masukkan ID unik (contoh: 3)
3. Masukkan nama tournament (contoh: PMPL Season 5)
4. Masukkan nama game (contoh: PUBG Mobile)
5. Masukkan tanggal mulai dan selesai
6. Masukkan total hadiah

### Menambah Match ke Tournament

1. Pilih menu 7
2. Masukkan ID tournament yang sudah ada
3. Masukkan ID match unik
4. Masukkan informasi match (nama, tim, score, tanggal, status)

### Search Match by Team

1. Pilih menu 13
2. Masukkan nama tim (contoh: RRQ)
3. Sistem akan menampilkan semua match yang melibatkan tim tersebut

### Query Tournament by Minimum Prize

1. Pilih menu 15
2. Masukkan minimum hadiah (contoh: 150000)
3. Sistem akan menampilkan tournament dengan hadiah >= $150,000

## Implementasi MLL 1-N

Program menggunakan struktur Multi-Linked List dengan relasi 1-N:

- **1 Tournament** dapat memiliki **banyak Match** (1-N)
- **1 Match** hanya dimiliki oleh **1 Tournament**

Setiap Tournament memiliki pointer `firstMatch` yang menunjuk ke linked list Match.

## Validasi

Program dilengkapi dengan validasi:

- ✅ Validasi ID unik untuk Tournament
- ✅ Validasi ID unik untuk Match dalam satu Tournament
- ✅ Konfirmasi sebelum menghapus data
- ✅ Pengecekan tournament tidak ditemukan
- ✅ Pengecekan match tidak ditemukan

## Fitur Tambahan

- **Clear Screen**: Membersihkan layar untuk tampilan yang rapi
- **Pause Screen**: Menunggu input user sebelum melanjutkan
- **Sample Data**: Data contoh untuk testing langsung
- **Memory Management**: Proper deallocation dengan deleteAllMatches dan deleteAllTournaments

## Kriteria Tugas Besar (Tubes)

✅ **MLL 1-N**: Implementasi Multi-Linked List dengan relasi 1-N  
✅ **Tipe Bentukan**: Struktur Tournament dan Match dengan atribut tipe dasar  
✅ **CRUD Lengkap**: Create, Read, Update, Delete untuk Parent dan Child  
✅ **Variasi Search**: Search by name parent, search by child  
✅ **Operasi Tabel**: Query/filter, max, min, counting (all & by criteria)

## Author

Program Manajemen Tournament Esport dengan Implementasi MLL 1-N
