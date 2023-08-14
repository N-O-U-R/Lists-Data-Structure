
# Doubly Linked List with MinGW C++

This project showcases a C++ application using MinGW to demonstrate operations on a doubly linked list. It primarily processes data from a `Veri.txt` file to perform actions on the list.

## 📖 Description

Upon initialization, the program reads from `Veri.txt`, a file that outlines operations and associated data. This file contains line-by-line instructions to either add to or remove from the list:

- **Addition**: Specified by `E(INDEX#DATA)`, e.g., `E(2#Mehmet Can)`.
  - Here, "E" denotes the addition, and the data `Mehmet Can` should be added at the 2nd index. If the index is not present, the program appends data to the list's end.

- **Deletion**: Denoted by `S(INDEX)`, such as `S(3)`.
  - "S" signifies deletion, intending to remove the data at the 3rd index. If the index doesn't exist, the program removes the list's last element.

A pivotal aspect is that the doubly linked list should mimic array behavior. Elements are added or removed as if shifting in an array.

## 🚀 Setup & Execution

1. **Clone the Repository**
   ```bash
   git clone <repository-url>
   ```

2. **Navigate to Directory**
   ```bash
   cd <repository-directory>
   ```

3. **Compile with MinGW**
   ```bash
   g++ source.cpp -o output
   ```

4. **Run the Program**
   ```bash
   ./output
   ```

The modified list gets printed, showcasing the operations performed.

## 🚫 Assumptions

- The program handles large files.
- The input won't have more delete operations than additions.
- Absence of delete commands when the list is empty.
- Always expect a consistent input file.
