#include<iostream>
using namespace std;

void addElement(int arr[], int &size)
{
    int item;
    cout << "Enter an element to be added: ";
    cin >> item;

    arr[size] = item;
    size++;
}

void deleteElement(int arr[], int& size)
{
    int pos;
    cout << "Enter the position of the element to delete (0-" << size - 1 << "): ";
    cin >> pos;

    if (pos < 0 || pos >= size)
    {
        cout << "Invalid position." << endl;
        return;
    }

    for (int i = pos; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    size--;
    cout << "Element deleted successfully." << endl;
}

void updateElement(int arr[], int& size)
{
    int pos;
    cout << "Enter the position of the element to update (0-" << size - 1 << "): ";
    cin >> pos;

    if (pos < 0 || pos >= size)
    {
        cout << "Invalid position." << endl;
        return;
    }

    int newValue;
    cout << "Enter the new value: ";
    cin >> newValue;

    arr[pos] = newValue;
    cout << "Element updated successfully." << endl;
}

void displayElement(int arr[], int& size)
{
    if (size == 0)
    {
        cout << "The array is empty." << endl;
        return;
    }

    cout << "Array elements: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    const int MAX_SIZE = 10;
    int arr[MAX_SIZE];
    int size = 0;

    int ch;
    do
    {
        cout << "List of operations" << endl;
        cout << "1. Add element \n2. Delete element \n3. Update element \n4. Display \n5. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            if (size >= MAX_SIZE)
            {
                cout << "The array is full." << endl;
            }
            else
            {
                addElement(arr, size);
            }
            break;
        case 2:
            if (size == 0)
            {
                cout << "The array is empty." << endl;
            }
            else
            {
                deleteElement(arr, size);
            }
            break;
        case 3:
            if (size == 0)
            {
                cout << "The array is empty." << endl;
            }
            else
            {
                updateElement(arr, size);
            }
            break;
        case 4:
            displayElement(arr, size);
            break;
        case 5:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice." << endl;
            break;
        }
    } while (ch != 5);

    return 0;
}
