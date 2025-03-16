// set waktu
#include <chrono>
// library nullptr
#include <cstddef>
// standart library for input output
#include <iostream>
// library untuk delay
#include <string>
#include <thread>
using namespace std;

class Node {
public:
  string data;
  Node *next;

  Node(string val) {
    data = val;
    next = nullptr;
  }
};

// Circular Linked List
class LinkedList {
private:
  Node *head;

public:
  LinkedList() { head = nullptr; }
  ~LinkedList() {
    if (head == nullptr)
      return;

    Node *temp = head;
    Node *nextNode;
    do {
      nextNode = temp->next;
      delete temp;
      temp = nextNode;
    } while (temp != head);

    head = nullptr;
  }

  void insertAtTheEnd(string val) {
    Node *newNode = new Node(val);
    // cek jika belum ada node sama sekali di linked list
    if (head == nullptr) {
      head = newNode;
      head->next = head;
    } else { // iterasi sampai ke belakang untuk menaruh node baru di paling
      // belakang
      Node *temp = head;
      while (temp->next != head) {
        temp = temp->next;
      }
      temp->next = newNode;
      newNode->next = head;
    }
  }

  void Play() {
    // cek kalau list nya kosong, langsung exit
    if (head == nullptr) {
      cout << "there is not song inside this playlist" << endl;
      return;
    }
    // ngeiterasiin dari node awal (HEAD) ke Head lagi
    Node *temp = head;
    do {
      cout << "now playing : " << temp->data << endl;
      cout << "next song -> "
           << ((temp->next->data == head->data) ? "the end of the playlist"
                                                : temp->next->data)
           << endl;
      this_thread::sleep_for(chrono::seconds(3));
      temp = temp->next;
    } while (temp != head);
    cout << "end" << endl;
  }
};

int main() {
  LinkedList ll;
  bool end = false;
  int choice;
  string song;
  char c;
  while (!end) {
    cout << "Songs make you feel good!" << endl;
    cout << "1. Insert song" << endl;
    cout << "2. Play the playlist" << endl;
    cin >> choice;
    switch (choice) {
    case 1:
      cout << "Enter the title of the song: ";
      cin.ignore();
      getline(cin, song);
      ll.insertAtTheEnd(song);
      break;
    case 2:
      ll.Play();
      break;
    default:
      break;
    }
    cout << "Its done? press x to exit or n to continue: ";
    cin >> c;
    if (c == 'x') {
      end = true;
      break;
    } else {
      continue;
    }
  }
}
