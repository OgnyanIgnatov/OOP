
struct Inventory {
    int salty;
    int sweet;
    int drinks;

    void changeSalty(int quantity);
    void changeSweets(int quantity);
    void changeDrinks(int quantity);
    void print();
    int getSalty();
    int getSweet();
    int getDrinks();
};

class VendingMachine {
    int id;
    char* address;
    Inventory inventory;
    char** warningMessages;
    int numWarningMsgs;
    int capacity;

public:
    int getID();
    char* getAddress();
    Inventory getInventory();
    char** getWarningMessages();
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
    void resize();
public:
    VendingController();
    VendingController(int numMachines, int capacity);
    VendingController(VendingController const& other);
    ~VendingController();
    void addVendingMachine(VendingMachine machine);
    char* getAddressOfMachine(int machineID);
    Inventory getInventoryOfMachine(int machineID);
    void sellProductInMachine(int machineID, char* product);
    void restockProductInMachine(int machineID, char* product);
    void seeWarningMsgForMachine(int machineID);
};    
