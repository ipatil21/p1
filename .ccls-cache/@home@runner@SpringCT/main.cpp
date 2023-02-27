#include <iostream>
#include <list>
using namespace std;

// tcp server class
class TCPServer {
public:
  void createSocket() {}

  void bindSocket() {}

  void startListening() {}
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
  TicketItem(uint time, uint max, name) : m_maxLimit(max), m_startTime(time), m_name(name) {}

  uint getMaxLimit() { return m_maxLimit; }

  uint getStartTime() { return m_startTime; }

  string getName() { return m_name; }

  uint getAvailable() { return m_maxLimit - m_bookedItem; }

private:
  uint m_startTime;
  uint m_maxLimit;
  uint m_bookedItem;
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
    resetAvailableTicketList();
    list<TicketItem>::iterator itr = m_allTicketList.begin();
    for (itr; itr != m_allTicketList.end(); ++itr) {
      TicketItem temp = *itr;
      if (0 != temp.getAvailable()) {
        m_availableTicketList.push_back(temp);
      }
    }
  }

  void resetAvailableTicketList() { m_availableTicketList.clear(); }

  void printTicketList(list<TicketItem> lst) {
    list<TicketItem>::iterator itr = lst.begin();
    for (itr; itr != lst.end(); ++itr) {
      cout << "***********Item Start ***********" << endl;
      cout << "Ticket Name :- " << (*itr).getName() << endl;
      cout << "Ticket Availaibility Count :- " << (*itr).getAvailable() << endl;
      cout << "***********Item End ***********" << endl;
    }
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

int main() { std::cout << "Hello World!\n"; }