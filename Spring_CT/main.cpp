// Common header files
#include <iostream>
#include <list>

// Socket header files
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

using namespace std;

// tcp server class
class TCPServer {

public:

  // default ctor
  TCPServer() {
    init();
  }

  // create socket
  int createSocket() {
    cout << "Creating TCPServer socket ..." << endl;
    int listening = socket(AF_INET, SOCK_STREAM, 0);
    if (-1 == listening) {
        cerr << "Error while creating TCP/IP socket !!!";
        return -1;
    }
  }

  // bind it
  int bindSocket() {
    cout << "Binding TCPServer socket to sockaddr ..." << endl;
    if (bind(listening, (struct sockaddr *)&hint, sizeof(hint)) == -1) {
        std::cerr << "Error while binding to IP/port";
        return -2;
    }
  }

  // let's listen
  int startListening() {
      cout << "Begin socket for listening ..." << endl;
      if (listen(listening, SOMAXCONN) == -1) {
        std::cerr << "Error while listening socket !";
        return -3;
      }
  }

private:

  void init() {
    listening = socket(AF_INET, SOCK_STREAM, 0);
    hint.sin_family = AF_INET;
    hint.sin_port = htons(54000);
    inet_pton(AF_INET, "0.0.0.0", &hint.sin_addr);
  }

  struct sockaddr_in hint;
  int listening;
};

// tcp client class
class TCPClient {
public:
  bool connectToServer() {}

  void processRequest() {}

  bool disconnectClient() {}
};

// represents a single ticket
class TicketItem {
public:
  // ctor
  TicketItem(uint time, uint max, string name) : m_maxBookingLimit(max), m_startTime(time), m_name(name) {}

  uint getMaxLimit() { return m_maxBookingLimit; }

  uint getStartTime() { return m_startTime; }

  string getName() { return m_name; }

  uint getAvailable() { return m_maxBookingLimit - m_bookedItems; }

private:
  uint m_startTime;
  uint m_maxBookingLimit;
  uint m_bookedItems;
  string m_name;
};

// ticket manager class
class GenericTicketBookingServer : public TCPServer {
public:

  void displayAllTicketList() { printTicketList(m_allTicketList); }

  list<TicketItem> getAllTicketList() { return m_allTicketList; }

  void displayAvailaibleTicketList() {
    printTicketList(getAvailableTicketList());
  }

  list<TicketItem> getAvailableTicketList() { return tallyAvailability(); }

private:
  list<TicketItem> tallyAvailability() {
    m_availableTicketList.clear();
    list<TicketItem>::iterator itr = m_allTicketList.begin();
    for (itr; itr != m_allTicketList.end(); ++itr) {
      TicketItem temp = *itr;
      if (0 != temp.getAvailable()) {
        m_availableTicketList.push_back(temp);
      }
    }
  }

  void printTicketList(list<TicketItem> lst) {
    list<TicketItem>::iterator itr = lst.begin();
    for (itr; itr != lst.end(); ++itr) {
      cout << "***********Item Start ***********" << endl;
      cout << "Ticket Name :- " << (*itr).getName() << endl;
      cout << "Ticket Availaibility Count :- " << (*itr).getAvailable() << endl;
      cout << "***********Item End ***********" << endl;
    }
  }
  void init() {
    createSocket();
    bindSocket();
    
  }
  // data memebers
  list<TicketItem> m_allTicketList;
  list<TicketItem> m_availableTicketList;
};

// ticket booking client
class GenericTicketBookingClient : public TCPClient {
public:
  bool bookTicket() {}

private:
};

int main() {
  GenericTicketBookingClient cl1;
  GenericTicketBookingClient cl2;
  GenericTicketBookingClient cl3;
  GenericTicketBookingClient cl4;
  GenericTicketBookingClient cl5;

  cout << "Hello World!\n"; 
}