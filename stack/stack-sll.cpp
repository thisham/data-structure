#include <string>
#include <iostream>

using namespace std;

// ==================== EDITOR ========================
/** 
 * Clone dari : https://github.com/fwwzali/data-structure.git
 * Forked repo: https://github.com/thisham/data-structure.git
 * 
 * Mahasiswa :
 * 		Hamdan Yuwafi Mastu Wijaya
 * 		(19081010092 - Struktur Data B)
 * 
 * Riwayat Perubahan :
 * 		- Penulisan ulang source-code;
 * 		- Melengkapi fitur:
 * 			- Pop;
 *          - Element Amount;
 *          - Element Search;
 *          - Sum of Element;
 *          - Empty Stack Checker;
 *          - Full Stack Checker.
 * 
 */

struct node
{
    int data;
    node *next;
};
typedef node Node;

struct stack
{
    int count;
    node *top;
};
typedef stack Stack;

class Operation
{
    private:
        stack stackData;

    public:
        Operation& from(stack data) {
            this->stackData = data;
            return *this;
        }

        stack push(int data) {
            node *newData;
            newData = new node;
            newData->data = data;
            newData->next = this->stackData.top;
            this->stackData.top = newData;
            this->stackData.count = this->stackData.count + 1;
            return this->stackData;
        }

        void top() {
            cout << "Top Value : " << this->stackData.top->data << endl;
        }

        stack pop() {
            node *walkerNode;
            walkerNode = new node;
            if (this->stackData.top != NULL) {
                walkerNode = this->stackData.top->next;
                this->stackData.count = this->stackData.count - 1;
                delete this->stackData.top;
                this->stackData.top = walkerNode;
            }
            return this->stackData;
        }

        void amount() {
            cout << "Amount of Stack Data : " << this->stackData.count << endl;
        }

        void get(int data) {
            int counter = this->stackData.count;
            bool found = false;
            while (this->stackData.top != NULL && !found) {
                if (this->stackData.top->data == data)
                    found = true;
                else {
                    this->stackData.top = this->stackData.top->next;
                    counter--;
                }
            }
            if (found) cout << "Data found at stack number: " << counter << "." << endl;
            else cout << "Data not found!" << endl;
        }

        void sum() {
            int summary = 0;
            while (this->stackData.top != NULL) {
                summary = summary + this->stackData.top->data;
                this->stackData.top = this->stackData.top->next;
            }
            
            cout << "Total data is: " << summary << endl;
        }

        void isEmpty() {
            string reason = (this->stackData.count == 0)
                ? "Stack is empty!"
                : "Stack is not empty!";
            
            cout << reason << endl;
        }

        void isFull() {
            node *checker = new node;
            string reason = "Stack is not full.";
            if (checker == NULL) 
                reason = "Stack is full!";
            cout << reason << endl;
        }

        void print() {
            if (this->stackData.count != 0) {
                while (this->stackData.top) {
                    cout << " | " << this->stackData.top->data << "\t| " << endl;
                    this->stackData.top = this->stackData.top->next;
                }
                cout << " | NULL\t| " << endl;
            }
        }
};

class Main
{
    private:
        stack stackData;

        stack createStack() {
            this->stackData.count = 0;
            this->stackData.top = NULL;
            return this->stackData;
        }

        void isSuccess(bool operation) {
            string reason = (!operation)
                ? "Operation failed!"
                : "Operation succeed!";

            cout << reason << endl << endl;
        }

        int getData() {
            int data;
            cout << "Input Data : ";
            cin >> data;
            return data;
        }

        bool switcher(int choice) {
            int data; int counter = this->stackData.count;
            Operation useStack;
            switch (choice) {
                case 1: 
                    data = getData();
                    this->stackData = useStack.from(this->stackData).push(data);
                    this->isSuccess((this->stackData.count > counter));
                    break;

                case 2:
                    useStack.from(this->stackData).top();
                    this->isSuccess(true);
                    break;

                case 3: 
                    useStack.from(this->stackData).print();
                    this->isSuccess(true);
                    break;

                case 4:
                    this->stackData = useStack.from(this->stackData).pop();
                    this->isSuccess((this->stackData.count < counter));
                    break;

                case 5:
                    useStack.from(this->stackData).amount();
                    this->isSuccess(true);
                    break;
                
                case 6:
                    cout << "Search Data in Stack." << endl;
                    data = this->getData();
                    useStack.from(this->stackData).get(data);
                    this->isSuccess(true);
                    break;

                case 7:
                    useStack.from(this->stackData).sum();
                    this->isSuccess(true);
                    break;

                case 8:
                    useStack.from(this->stackData).isEmpty();
                    this->isSuccess(true);
                    break;
                
                case 9:
                    useStack.from(this->stackData).isFull();
                    this->isSuccess(true);
                    break;

                case 0:
                    return false;
                    break;

                default:
                    cout << "501 - Not Implemented!" << endl;
                    break;
            }

            return true;
        }

        int menu() {
            int menu;
            cout << "-----STACK MENU-----" << endl;
            cout << "1. Push element" << endl;
            cout << "2. Element in top of stack" << endl;
            cout << "3. Display Stack" << endl;
            cout << "4. Pop element" << endl;
            cout << "5. Number element of Stack" << endl;
            cout << "6. Search an element" << endl;
            cout << "7. Sum all element of Stack" << endl;
            cout << "8. is Stack empty" << endl;
            cout << "9. is Stack full" << endl;
            cout << "0. Destroy Stack and EXIT" << endl << endl;
            cout << "Enter your choice : ";
            cin >> menu;
            return menu;
        }
        
    public:
        Main() {
            int choice, num;
            bool repeating = true;
            this->stackData = this->createStack();
            
            while (repeating) {
                choice = this->menu();
                repeating = this->switcher(choice);
            }
            
        }

        ~Main() {
            node *walkerNode;
            while (this->stackData.top != NULL) {
                walkerNode = this->stackData.top->next;
                delete this->stackData.top;
                this->stackData.top = walkerNode;
            }

            cout << "Nodes has been freed and stack has been destroyed." << endl;
        }
};

int main(int argc, char const *argv[])
{
    Main main;
    return 0;
}
