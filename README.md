# Inverted Search (Index) in C

## 📌 Project Overview

The **Inverted Search** project is a file indexing and searching application developed using C programming.

It uses a **Hash Table and Linked Lists** to create an inverted index, which maps each word to the files in which it appears along with the number of occurrences.

Instead of searching every file individually, the application searches the indexed database, making word searching more efficient.

## 🎯 Features

- **Command Line Argument Validation:** Validates input filenames and checks file availability.
- **Duplicate File Removal:** Removes duplicate and empty files from the input list.
- **Create Database:** Reads input files and creates an inverted index.
- **Display Database:** Displays indexed words, file names, and word occurrence counts.
- **Search Word:** Searches for a particular word in the database.
- **Save Database:** Saves the created database into a backup file.
- **Update Database:** Updates the database using a previously saved backup file.
- **Menu-Driven Application:** Provides an interactive menu to perform different operations.

## 🛠️ Technologies Used

- Programming Language: C
- Data Structures: Hash Table, Singly Linked Lists
- Concepts:
  - File Handling
  - Dynamic Memory Allocation
  - Structures
  - Pointers
  - String Manipulation
  - Linked Lists
  - Hashing

## 📂 Project Structure

```text
Inverted_Search/
│
├── main.c
├── header.h
├── list.c
├── create.c
├── display.c
├── search.c
├── save.c
├── update.c
├── Makefile
```

## ⚙️ Hash Table Implementation

The project uses a hash table of size **27**.

- Index 0–25: Alphabetic characters (a–z).
- Index 26: Non-alphabetic characters.

Each hash table entry maintains a linked list of words. Each word node maintains another linked list containing the filenames and occurrence counts.

## 🚀 Compilation and Execution

### 1. Clone the Repository

```bash
git clone <your-repository-link>
```

### 2. Navigate to the Project Directory

```bash
cd Inverted_Search
```

### 3. Compile the Project

Using Makefile:

```bash
make
```

Alternatively, compile manually:

```bash
gcc *.c -o a.out
```

### 4. Run the Program

Pass the input text files as command-line arguments:

```bash
./a.out file1.txt file2.txt file3.txt
```

**Note:** Input files should be valid, non-empty `.txt` files.

## 📋 Operations

After execution, the application displays the following menu:

```text
1. Create Database
2. Display Database
3. Search Word
4. Save Database
5. Update Database
6. Exit
```

Select the required option to perform the corresponding operation.

## 💡 Learning Outcomes

Through this project, I gained practical experience in:

- Implementing Hash Tables and Linked Lists.
- Understanding inverted indexing concepts.
- Handling files using C file handling functions.
- Managing dynamic memory allocation.
- Working with pointers and structures.
- Developing menu-driven applications.
- Implementing searching and database backup operations.

## 👩‍💻 Author

**K S Gowthami**

Electronics and Communication Engineering Graduate

Interested in C Programming, Data Structures, Embedded Systems, and Firmware Development.

---
