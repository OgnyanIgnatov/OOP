struct Inventory {
    int salty;
    int sweet;
    int drinks;

    void changeSalty(int quantity);
    void changeSweets(int quantity);
    void changeDrinks(int quantity);
    void print();
};

class VendingMachine {
    int id;
    char* address;
    Inventory inventory;
    char** warningMessages;
    int numWarningMsgs;
    int capacity;

public:
    VendingMachine(); 
    VendingMachine(char* address, Inventory inventory);
    VendingMachine(VendingMachine const& other); 
    VendingMachine(VendingMachine&& other); 
    VendingMachine& operator=(VendingMachine const& other);
    ~VendingMachine();

    
};


class VendingController {
    VendingMachine* vendingMachineList;
    int numMachines;
    int capacity;

public:
    
    void addVendingMachine(VendingMachine machine);
    void getAddressOfMachine(int machineID);
    void getInventoryOfMachine(int machineID);
    void sellProductInMachine(int machineID, char* product);
    void restockProductInMachine(int machineID, char* product);
    void seeWarningMsgForMachine(int machineID);
};