#include <iostream>  
using namespace std;

int main() 
{
    cout << "...Hotel Menu..." << endl;
    cout << "1. View Rooms" << endl;
    cout << "2. Book a Room" << endl;
    cout << "3. Check Out" << endl;
    cout << "4. Exit" << endl;

    // Room numbers
    int room[5] = {101, 102, 103, 104, 105};

    // Room types
    string room_t[5] = {"Single","Single", "Double", "Suite", "Deluxe"};

    // Room rates
    int room_r[5] = {15000, 15000, 20000, 25000, 30000};
    

    
    int choice = 0, room_n=0, no_nights=0;

    cout << "Enter your choice: ";
    cin >> choice;

	// Loop - if the user chooses 4, then exit
    while (choice != 4) 
	{  
        if (choice == 1) 
		{	
            cout << "Room Details:" << endl;
            for (int i = 0; i < 5; i++) 
			{
                cout << "Room Number: " << room[i]<<"\t" 
                     << "Type: " << room_t[i]<<"\t" 
                     << "Rate: Rs." << room_r[i] << " Per Night" << endl;
 
            }

        } 
		else if (choice == 2)
		{
			cout << "Room Details:" << endl;
            for (int i = 0; i < 5; i++) 
			{
                cout << "Room Number: " << room[i]<<"\t" 
                     << "Type: " << room_t[i]<<"\t" 
                     << "Rate: Rs." << room_r[i] << " Per Night" << endl;
 
            }
            
			cout<<"Enter the room number to book =";
			cin>>room_n;
			
   			cout << "Enter number of nights to stay = ";
            cin >> no_nights;
			
		
		}
		
	 	 cout << "...Hotel Menu..." << endl;
   		 cout << "1. View Rooms" << endl;
   		 cout << "2. Book a Room" << endl;
   		 cout << "3. Check Out" << endl;
   		 cout << "4. Exit" << endl;
        
        // Ask for user input again after each loop
        cout << "Enter your choice: ";
        cin >> choice;
    }

    

    return 0;
}
