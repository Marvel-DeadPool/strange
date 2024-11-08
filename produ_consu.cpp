#include <iostream>
using namespace std;

class Buffer {
    private:
    int produced=0;
    int available=3;

    public:
    void producer() {
        if (available > 0) {
            produced++;
            available--;
            cout << "Producer produces the item" << produced << endl;    
        } else {
            cout << "Buffer is full!" << endl;
        }
    }

    void consumer() {
        if (produced > 0) {
            produced--;
            available++;
            cout << "Consumer consumes item" << available << endl;
        } else {
            cout << "Buffer is empty!" << endl;
        }
    }

    void BufferStatus() {
        cout << "Buffer Status :";
        cout << "Produced items :" << produced << endl;
        cout << "Available space :" << available << endl;
    }
};

int main() {
    int choice;
    Buffer buffer;

    while(true) {
        cout << "1.Producer 2.Consumer 3.Show buffer status 4.Exit \nEnter your choice";
        cin >> choice;

        switch(choice) {

            case 1:
            buffer.producer();
            break;
            case 2:
            buffer.consumer();
            break;
            case 3:
            buffer.BufferStatus();
            break;
            case 4:
            cout << "Exiting the program..!";
            return 0;
            default:
            cout << "Invalid Choice!";
        } 
    }
    return 0;
}
