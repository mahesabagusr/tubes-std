# DOKUMENTASI SISTEM MANAJEMEN TOURNAMENT ESPORT

## STRUKTUR PROJECT

```
Tubes-Std/
├── bin/
│   └── app.exe              # File executable hasil compile
├── src/
│   ├── tournament.h         # Header Tournament (struktur & deklarasi)
│   ├── tournament.cpp       # Implementasi Tournament
│   ├── match.h              # Header Match (struktur & deklarasi)
│   ├── match.cpp            # Implementasi Match
│   ├── menu.h               # Header Menu (deklarasi fungsi UI)
│   ├── menu.cpp             # Implementasi Menu
│   └── query.cpp            # Implementasi Query & Counting
├── main.cpp                 # Program utama
└── README.md                # Dokumentasi ini
```

## STRUKTUR DATA

### 1. Tournament (Parent)

```cpp
struct Tournament {
    int tournamentID;
    string tournamentName;
    string game;
    string startDate;
    string endDate;
    int totalPrize;
    adrMatch firstMatch;     // Pointer ke child list
};
```

### 2. Match (Child)

```cpp
struct Match {
    int matchID;
    string matchName;
    string team1;
    string team2;
    int scoreTeam1;
    int scoreTeam2;
    string matchDate;
    string status;
};
```

### 3. Relasi

- **Multi Level List**: Tournament → Match (One-to-Many)
- **Tournament List**: Single Linked List
- **Match List**: Single Linked List per Tournament

## PENGELOMPOKAN FUNGSI

### A. TOURNAMENT OPERATIONS (tournament.cpp)

#### 1. Inisialisasi & Pembuatan

- `createListTournament(ListTournament &L)`
- `createElmTournament(Tournament data) → adrTournament`

#### 2. Insertion

- `insertFirstTournament(ListTournament &L, adrTournament P)`
- `insertLastTournament(ListTournament &L, adrTournament P)`
- `insertAfterTournament(ListTournament &L, adrTournament Prec, adrTournament P)`

#### 3. Search & Retrieval

- `findTournamentByID(ListTournament L, int tournamentID) → adrTournament`
- `findTournamentByName(ListTournament L, string name) → adrTournament`

#### 4. Display

- `showAllTournaments(ListTournament L)`

#### 5. Update & Delete

- `updateTournament(ListTournament &L, int tournamentID)`
- `deleteTournament(ListTournament &L, int tournamentID)`
- `deleteAllTournaments(ListTournament &L)`

### B. MATCH OPERATIONS (match.cpp)

#### 1. Pembuatan

- `createElmMatch(Match data) → adrMatch`

#### 2. Insertion

- `insertFirstMatch(adrTournament P, adrMatch M)`
- `insertLastMatch(adrTournament P, adrMatch M)`

#### 3. Search

- `findMatchByID(adrTournament P, int matchID) → adrMatch`
- `findMatchByName(adrTournament P, string matchName) → adrMatch`

#### 4. Display

- `showAllMatches(adrTournament P)`

#### 5. Update & Delete

- `updateMatch(adrTournament P, int matchID)`
- `deleteMatch(adrTournament P, int matchID)`
- `deleteAllMatches(adrTournament P)`

### C. QUERY & COUNTING (query.cpp)

#### 1. Query

- `queryTournamentByPrize(ListTournament L, int minPrize)`
  - Mencari tournament dengan hadiah >= nilai tertentu

#### 2. Counting

- `countAllTournaments(ListTournament L) → int`
- `countAllMatches(ListTournament L) → int`
- `countMatchesByTournament(adrTournament P) → int`

### D. MENU & USER INTERFACE (menu.cpp)

#### 1. Display Menu

- `displayMainMenu()`
- `displayTournamentMenu()`
- `displayMatchMenu()`

#### 2. Menu Controllers

- `startMenu(ListTournament &L)` - Main loop
- `menuTournament(ListTournament &L)` - Tournament menu handler
- `menuMatch(ListTournament &L)` - Match menu handler

#### 3. Tournament UI Handlers

- `addTournament(ListTournament &L)`
- `searchTournamentByID(ListTournament L)`
- `searchTournamentByName(ListTournament L)`
- `handleUpdateTournament(ListTournament &L)`
- `handleDeleteTournament(ListTournament &L)`

#### 4. Match UI Handlers

- `addMatch(ListTournament &L)`
- `handleShowMatches(ListTournament L)`
- `searchMatchByID(ListTournament L)`
- `handleUpdateMatch(ListTournament L)`
- `handleDeleteMatch(ListTournament L)`

#### 5. Utility

- `searchTournament(ListTournament L)` - Quick search
- `queryTournament(ListTournament L)` - Query by prize
- `showStatistics(ListTournament L)` - Display stats

## FLOW PROGRAM

```
main.cpp
  └─> createListTournament()
  └─> loadSampleData()
  └─> Main Menu Loop
       ├─> 1. menuTournament()
       │    ├─> Add Tournament
       │    ├─> Show All
       │    ├─> Search by ID
       │    ├─> Search by Name
       │    ├─> Update
       │    └─> Delete
       ├─> 2. menuMatch()
       │    ├─> Add Match to Tournament
       │    ├─> Show All Matches
       │    ├─> Search Match
       │    ├─> Update Match
       │    └─> Delete Match
       ├─> 3. searchTournament()
       ├─> 4. queryTournament()
       ├─> 5. showStatistics()
       └─> 0. Exit + deleteAllTournaments()
```

## COMPILE & RUN

### Compile

```powershell
g++ main.cpp src\tournament.cpp src\match.cpp src\menu.cpp src\query.cpp -o bin\app.exe
```

### Run

```powershell
.\bin\app.exe
```

## FITUR PROGRAM

1. **Tournament Management**

   - CRUD Tournament (Create, Read, Update, Delete)
   - Search by ID atau Name
   - List semua tournament

2. **Match Management**

   - CRUD Match dalam Tournament
   - Search match by ID
   - List semua match per tournament

3. **Query & Statistics**

   - Query tournament berdasarkan minimal prize
   - Hitung total tournament
   - Hitung total match
   - Hitung match per tournament

4. **Sample Data**
   - MPL Season 12 (Mobile Legends)
     - Grand Final: RRQ vs ONIC
     - Semi Final: EVOS vs RRQ
   - VCT Masters (Valorant)
     - Quarter Final: PRX vs DRX

## CATATAN TEKNIS

- **Library**: Hanya menggunakan `<iostream>` dan `<string>`
- **Input Style**: `cin>>` (no getline, kecuali di search)
- **Output Style**: `cout<<` (no spacing)
- **Formatting**: Variasi style (if/while spacing, brace position)
- **Pause**: `cin.ignore() + cin.get()` setelah list display
- **Memory Management**: Manual delete dengan deleteAll functions
