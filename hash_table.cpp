#include <iostream>
#include <vector>
using namespace std;

const int TABLE_SIZE = 10;

class HashTable {
private:
    vector<pair<int, string>> table[TABLE_SIZE];

    // A simple hash function to map keys to positions in the array
    int hash(int key) {
        return key % TABLE_SIZE;
    }

public:
    // Insert a key-value pair into the hash table
    void insert(int key, const string& value) {
        int index = hash(key);
        table[index].push_back(make_pair(key, value));
    }

    // Search for a key and return its corresponding value
    string search(int key) {
        int index = hash(key);
        for (const auto& entry : table[index]) {
            if (entry.first == key)
                return entry.second;
        }
        return "Key not found";
    }

    // Delete a key-value pair from the hash table
    void remove(int key) {
        int index = hash(key);
        auto& bucket = table[index];
        for (auto it = bucket.begin(); it != bucket.end(); it++) {
            if (it->first == key) {
                bucket.erase(it);
                return;
            }
        }
    }
};

int main() {
    HashTable ht;

    int choice, key;
    string value;

    do {
        cout << "Hash Table Operations:" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Search" << endl;
        cout << "3. Delete" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter key and value to insert: ";
                cin >> key >> value;
                ht.insert(key, value);
                break;
            case 2:
                cout << "Enter key to search: ";
                cin >> key;
                cout << "Search result for key " << key << ": " << ht.search(key) << endl;
                break;
            case 3:
                cout << "Enter key to delete: ";
                cin >> key;
                ht.remove(key);
                cout << "Key " << key << " deleted." << endl;
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
