#include <iostream> 
#include <string> 

using namespace std;

void displayMenu();
void viewAllGuests();


// Room types
string roomTypes[4] = {"SINGLE", "DOUBLE", "SUITE", "DELUXE"};

// Store reservation details
string customerNames[100];      // To store multiple customer names
string customerNICs[100];       // To store multiple NICs
int customerRoomTypes[100];     // To store room types for each customer
int customerRooms[100];         // To store number of rooms booked
int customerNights[100];        // To store number of nights

int customerCount = 0;          // To keep track of the number of reservations (for checkout option)

int main() 
{
    displayMenu();

    // Available Rooms
    int availableRooms[4] = {20, 30, 20, 30};

    // Room rates
    int roomRates[4] = {15000, 20000, 25000, 30000};

    int choice = 0, numNights = 0, roomTypeNumber = 0, numRooms = 0, count = 0, bill;
    string customerName, customerNIC;

    cout << "Enter your choice: ";
    cin >> choice;
    
	// (KIC-DCSAI-242-F-015)
    // Loop - if the user chooses 5, then exit
    while (choice != 5) 
    {  
    	// View Rooms
        if (choice == 1) 
        {	
            cout << "...Room Details..." << endl;
            for (count = 0; count < 4; count++) 
            {
                cout << "Type: " << count+1 << "\t" << roomTypes[count] << "\t"
				<< "available rooms: "<<availableRooms[count]<<"\t" 
                << "(Rate: Rs." << roomRates[count] << " One Room Per Night)\n" << endl;
            }
        } 
        
        // (KIC-DCSAI-242-F-014)
        // Check In
        else if (choice == 2)
        {
            cout << "...Room Details..." << endl;
            for (count = 0; count < 4; count++) 
            {
            	 cout << "Type: " << count+1 << "\t" << roomTypes[count] << "\t"
				<< "available rooms: "<<availableRooms[count]<<"\t" 
                << "(Rate: Rs." << roomRates[count] << " One Room Per Night)\n" << endl;
            }
        
            // Get customer details 
			cout << "Enter Customer Name Without Spaces: ";
            cin >> customerName;
            
            cout << "Enter Customer NIC number (without letters): ";
            cin >> customerNIC;
            
            cout << "Enter the room type number: ";
			cin >> roomTypeNumber;
			
   			cout << "How many rooms does the customer want? ";
			cin >> numRooms;
			
   			cout << "Enter number of nights to stay: ";
            cin >> numNights;
            
            // Ensure availability
            if (availableRooms[roomTypeNumber - 1] >= numRooms)
            {
            	
            	// Store reservation details
				customerNames[customerCount] = customerName;         // Store Customer Name
				customerNICs[customerCount] = customerNIC;           // Store NIC
            	customerRoomTypes[customerCount] = roomTypeNumber - 1;  // Store room type
            	customerRooms[customerCount] = numRooms;             // Store number of rooms
            	customerNights[customerCount] = numNights;           // Store number of nights

            	customerCount++; // Increment customer count
            
            	// Update room availability (customer checked in, so reduce from available room count)
            	if (roomTypeNumber==1)
				{
				availableRooms[0]=availableRooms[0]-numRooms;
				}
				else if (roomTypeNumber==2)
				{
				availableRooms[1]=availableRooms[1]-numRooms;
				}
				else if (roomTypeNumber==3)
				{
				availableRooms[2]=availableRooms[2]-numRooms;
				}
				else
				{
				availableRooms[3]=availableRooms[3]-numRooms;
				}
				
				
				cout << "Reservation Successful" << endl;
            }
            else 
        	{
            	cout << "Sorry, only " << availableRooms[roomTypeNumber-1] 
          	  		 << " rooms are available for this type." << endl;
       		}
			

        }
        
        // (KIC-DCSAI-242-F-17)
        // Check Out
        else if (choice == 3)
        {
	 		cout << "Enter Customer NIC number (without letters) for checkout: ";
            cin >> customerNIC;
            
            for (count = 0; count < customerCount; count++) 
            {
             	if (customerNICs[count] == customerNIC) 
             	{
		            // Display customer details
                	cout << "Customer Name: " << customerNames[count] << endl;
                	cout << "Customer NIC: " << customerNICs[count] << endl;
                	cout << "Room Type: " << roomTypes[customerRoomTypes[count]] << endl;
                	cout << "Rooms Booked: " << customerRooms[count] << endl;
                    cout << "Nights Stayed: " << customerNights[count] << endl;
                
                	// Calculate and display bill
                	bill = customerRooms[count] * customerNights[count] * roomRates[customerRoomTypes[count]];
                	cout << "Amount due = Rs. " << bill << endl;
                
                	// Update room availability (customer checked out, so rooms are freed up)
                    if (roomTypeNumber==1)
					{
						availableRooms[0]=availableRooms[0]+numRooms;
					}
					else if (roomTypeNumber==2)
					{
						availableRooms[1]=availableRooms[1]+numRooms;
					}
					else if (roomTypeNumber==3)
					{
						availableRooms[2]=availableRooms[2]+numRooms;
					}
					else
					{
						availableRooms[3]=availableRooms[3]+numRooms;
					}
					
					// Remove the customer from arrays 
            		for (int i = count; i < customerCount - 1; i++) 
            		{
           				customerNames[i] = customerNames[i+1];
                		customerNICs[i] = customerNICs[i+1];
                		customerRoomTypes[i] = customerRoomTypes[i+1];
                		customerRooms[i] = customerRooms[i+1];
                		customerNights[i] = customerNights[i+1];
            		}

                     
                    customerCount--; // Decrease customer count after checkout
                    cout << "Check out Successful" << endl;
		            break;
             	}
            }
        }
        
        // (KIC-DCSAI-242-F-16)
        // View All Guests
        else if (choice == 4)
        {
            viewAllGuests();
        }
        else
        {
            cout << "Invalid choice..." << endl;
        }
		
        displayMenu();
        
        // Ask for user input again after each loop
        cout << "Enter your choice: ";
        cin >> choice;
    }

    return 0;
}

// To Display Menu
void displayMenu()
{
    cout << "...Hotel Menu..." << endl;
    cout << "1. View Rooms" << endl;
    cout << "2. Check In" << endl;
    cout << "3. Check Out" << endl;
    cout << "4. View All Guests" << endl;
    cout << "5. Exit" << endl;
}

// To Display Guest Details
void viewAllGuests()
{
	int count=0;
    if (customerCount == 0) 
    {
        cout << "No guests have booked yet..." << endl;
    }
    else 
    {
        cout << "...List of all Guests..." << endl;
        for (count = 0; count < customerCount; count++) 
        {
            cout << "Customer Name: " << customerNames[count] << "\t" 
            	 << "Customer NIC: " << customerNICs[count] << "\t"
          		 << "Room Type: " << roomTypes[customerRoomTypes[count]] << "\t"
          		 << "Number of Rooms Booked: " << customerRooms[count] << "\t"
            	 << "Nights Stayed: " << customerNights[count] << endl;
        }
    }
}
