#include <iostream>
#include <cstring>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <sstream>
#include <cmath>
#include <iomanip>
#include <windows.h>

using namespace std;

int currentuser;	//currentuser to display current user that is logged in 
const double taxPrice = 65.0;
const int arraySize = 33, air1=6, air2=6, t=6, title=6, d=6;
const int BSeatRow=5;		//total row for business seat
const int BSeatTot=20;		//total seat for businesss class
const int ESeatRow=45;		//total row for economy seat
const int ESeatTot=270;		//total seat for economy class
int i, j;
const int cust=20;
string airport[arraySize] = { "\n", "Kuala Lumpur (KUL)", "Subang (SZB)", "Kota Bharu (KBR)", "Kuala Terengganu (TGG)", "Johor Bahru (JHB)", "Alor Setar (AOR)", "Kerteh (KTE)", "Penang (PEN)", "Kuantan (KUA)", "Langkawi (LGK)", "Miri (MYY)", "Mulu (MZV)", "Sibu (SBW)", "Tawau (TWU)", "Labuan (LBU)", "Bintulu (BTU)", "Kuching (KCH)", "Limbang (LMN)", "Sandakan (SDK)", "Lahad Datu (LDU)", "Kota Kinabalu (BKI)", "Bario (BBN)", "Kudat (KUD)", "Lawa (LWY)", "Mukah (MKM)", "Marudi (MUR)", "Bakalalan (BKM)", "Long Akah (LKH)", "Long Banga (LBH)", "Long Lellang (LGL)", "Long Seridan (ODN)", "Tanjung Manis (TGC)"};
string airplane1[air1] = { "\n", "MH0001", "MH0003", "MH0005", "MH0007", "MH0009"};
string airplane2[air2] = { "\n", "MH0002", "MH0004", "MH0006", "MH0008", "MH0010"};
string passtitle[title] = { "\n", "Mr", "Mrs", "Ms", "Miss", "-(none)"};
string time1[t] = { "\n", "08:10 --------> 09:15", "14:05 --------> 15:10", "15:00 --------> 16:05", "17:00 --------> 18:05", "20:35 --------> 21:40" };
string time2[t] = { "\n", "08:10 --------> 10:15", "14:05 --------> 16:10", "15:00 --------> 17:05", "17:00 --------> 19:05", "20:35 --------> 22:40"};
string discountCode[d] = { "\n", "newborn10", "newborn25","newborn5", "Student25", "Seniorciti30" };
double busPrice, ecoPrice, ecoPrice2, busPrice2;

void userRegisteration();
void flightpage(char[ESeatTot][4], char[BSeatTot][4], int, string*, char[cust][70], char[cust][70], int [cust][3], string[cust]);
void payment(int*, int*, int*, int*, int*, int*, int*, int*, int*, int*, char*, int, char[9][4], double, double, double, double, int*, int*,char[cust][10],int,char[cust][70],char[cust][70],string passLName2[70],string passFName2[70],int*);
void ticket(char[cust][10], int, char[cust][70], char[cust][70],string*, string*,int*, int*,int*, int*, int*, char[9],int*,int*,int,int,char[9][4],int*,int*,int*,int*,int*); 

int main()		//main function
{
	userRegisteration();
}

void userRegisteration(){		//function (1)
	
	system("color 09");
	int user=0, dob[cust][3], expirydate[cust][3], postc[cust], number[cust], ROW;
	string email[cust], passnum[cust], address[cust], EMAIL;
	bool checkemail=false, emailValid=false;
	char PASSWORD[9], pass[cust][9], nationality[cust][20], gender[cust][7], passLName[cust][70], passFName[cust][70], option;
	char BSeat[BSeatTot][4],column[6][2]={"A", "B", "C", "D", "E", "F"}, row[5], ESeat[ESeatTot][4];
	bool login=false;
	
	
	for(ROW=1; ROW<=ESeatRow; ROW++){	// load seat for economy class
		for(i=0; i<=5; i++){
			sprintf(row,"%d", ROW);		
			strcpy(ESeat[j], row);
			strcat(ESeat[j],column[i]);	
			j++;
		}	
	}
	j=0;
	for(ROW=1; ROW<=BSeatRow; ROW++){	// load seat for business class
		for(i=0; i<=3; i++){
			sprintf(row,"%d", ROW);		
			strcpy(BSeat[j], row);
			strcat(BSeat[j],column[i]);	
			j++;
		}	
	}
	while(option !='X' && option!='x'){	
		cout << "Select an option : \n" << "(A) Register\n" << "(B) Log in\n" << "(C) Log out\n" << "(D) Book flight ticket\n" << "(X) Exit\n" ;
		cin >> option;
	
		switch (option){
			case 'A' : case 'a' :
				if(login==true){
					cout << "Current user must log out first for new user to register.\n";
					break;
				}
				cin.ignore();
				cout << "Enter email : ";
			    getline(cin, email[user]);
				if(user!=0){
					for(i=0; i< user; i++){
						while(email[i]==email[user]){		//to check wether the email registered is already exist in the system or not
							cout << "Email is not available. Please enter again : ";
							getline(cin, email[user]);
							i=0;
						}
					}
				}
				cout << "Enter password (9 characters): ";
				for(i=0; i<9; i++){
					PASSWORD[i]=getch();
					cout << "*";
				}
				PASSWORD[i]='\0';
				cout << endl;
				cout << "You have passed the hidden password. \n";
				for(i=0; PASSWORD[i]!='\0'; i++){
					cout << PASSWORD[i];
				}
				cout << endl;
				strcpy(pass[user], PASSWORD);
				
				system("pause");
				system("cls");
				
				cout << "Personal details \n";
				cout << "====================\n";
				cout << "Enter last name : ";
				cin.getline(passLName[user], 70);
				cout << "Enter first name : ";
				cin.getline(passFName[user], 70);
				cout << "Enter date of birth\nDay (dd): ";
				cin >> dob[user][0];
				while(dob[user][0]<1 || dob[user][0]>31 || dob[user][0]==false || dob[user][0]==true && dob[user][0]==false){
					cout << "Invalid day of birth. Please enter again : ";
					cin.clear();
    				cin.ignore(256,'\n');
					cin >> dob[user][0];
				}
				cout << "Month (mm): ";
				cin >> dob[user][1];
				while(dob[user][1]<1 || dob[user][1]>12 || dob[user][0]==false || dob[user][0]==true && dob[user][0]==false || dob[user][0]==31 && (dob[user][1]%2==0 && dob[user][1]<=6 || dob[user][1]==9 || dob[user][1]==11) || dob[user][1]==2 && dob[user][0]>29){
					cout << "Invalid month of birth. Please enter again : ";
					cin.clear();
        			cin.ignore(256,'\n');
					cin >> dob[user][1];
				}
				
				cout << "Year (yyyy): ";
				cin >> dob[user][2];
				while(dob[user][2]<1922 || dob[user][2]>2023 || dob[user][0]==false || dob[user][0]==false && dob[user][0]==true || dob[user][0]==28 && dob[user][1]==2 && dob[user][2]%4==0){
					cout << "Invalid year of birth. Please enter again : ";
					cin.clear();
        			cin.ignore(256,'\n');
					cin >> dob[user][2];
				}
				cout << "Date of birth : " << dob[user][0] << "/" << dob[user][1] << "/" << dob[user][2] << endl;
				cin.ignore();
				cout << "Enter gender (F/M): ";
				cin.getline(gender[user], 7);
				while(strcmpi(gender[user], "f")!=0 && strcmpi(gender[user], "m")!=0){
					cout << "Invalid input for gender. Please enter 'F' or 'M' \n";
					cout << "Enter gender (F/M): ";
					cin.getline(gender[user], 7);
				}
				if (strcmpi(gender[user], "f")==0){
					strcpy(gender[user], "Female");
				}
				else{
					strcpy(gender[user], "Male");
				}
				
				cout << "Enter nationality (eg: Malaysian): ";
				cin.getline(nationality[user], 20);
			
				if(strcmpi(nationality[user], "malaysian")!=0){
					cout << "Enter phone number (without '-'): ";
					cin >> number[cust];
					while(log10(number[cust])+1<5 || log10(number[cust])+1>13 || number[cust]==false || number[cust]==true && number[cust]==false){
						cout << "Invalid phone number. Please enter again : ";
						cin.clear();
        				cin.ignore(256,'\n');
						cin >> number[cust];
					}
					cin.clear();
        			cin.ignore(256,'\n');
					cout << "Enter passport number : ";
					getline(cin, passnum[user]);
					while(passnum[user].length()<6 || passnum[user].length()>12){
						cout << "Invalid passport number. Please enter again : ";
						cin.clear();
        				cin.ignore(256,'\n');
						getline(cin, passnum[user]);
					}
					cout << "Enter passport expiry date \n";
					cout << "Day (dd): ";
					cin >> expirydate[user][0];
					while(expirydate[user][0]<1 || expirydate[user][0]>31 || expirydate[user][0]==false || expirydate[user][0]==false && expirydate[user][0]==true){
						cout << "Invalid day. Please enter again : ";
						cin.clear();
        				cin.ignore(256,'\n');
						cin >> expirydate[user][0];
					}
					cout << "Month (mm): ";
					cin >> expirydate[user][1];
					while(expirydate[user][1]<1 || expirydate[user][1]>12 || expirydate[user][0]==false || expirydate[user][0]==false && expirydate[user][0]==true || expirydate[user][0]==31 && (expirydate[user][1]%2==0 && expirydate[user][1]<=6 || expirydate[user][1]==9 || expirydate[user][1]==11)|| expirydate[user][1]==2 && expirydate[user][0]>29){
						cout << "Invalid month. Please enter again : ";
						cin.clear();
        				cin.ignore(256,'\n');
						cin >> expirydate[user][1];
					}

					cout << "Year (yyyy): ";
					cin >> expirydate[user][2];
					while(expirydate[user][2]<2023 || expirydate[user][0]==false || expirydate[user][0]==false && expirydate[user][0]==true	|| expirydate[user][0]==28 && expirydate[user][1]==2 && expirydate[user][2]%4==0){
						cout << "Invalid year. Please enter again : ";
						cin.clear();
        				cin.ignore(256,'\n');
						cin >> expirydate[user][2];
					}				
					cout << "Passport expiry date : " << expirydate[user][0] << "/" << expirydate[user][1] << "/" << expirydate[user][2] << endl;	
				}
				else{
					cout << "Enter phone number (without '-') : ";
					cin >> number[user];
					while(log10(number[user])+2<5 || log10(number[user])+2>13 || number[user]==false || number[user]==true && number[user]==false){
						cout << "Invalid phone number. Please enter again : ";
						cin.clear();
        				cin.ignore(256,'\n');
						cin >> number[user];
					}
				}
				cin.sync();
				cout << "Enter address : ";
				getline(cin, address[user]);
				cout << "Postcode : ";
				cin >> postc[user];
				while(postc[user]==false || postc[user]==false && postc[user]==true){
					cout << "Invalid input. Please enter again : ";
					cin.clear();
					cin.ignore(256, '\n');
					cin>> postc[user];
				}
				user++;				//next customer index number
				cout << "YOU HAVE SUCCESSFULLY REGISTERED!\n\n";
				break;
														
			
			case 'B' : case 'b' :
				
				if(login==true){
					cout << "Other user is currently logged in. \n";
					break;
				}
				cin.ignore();
				cout << "Enter email : ";
				getline(cin, EMAIL);
				cin.sync();
				for(i=0; i<user; i++){
					if (email[i]==EMAIL){		//compare email to check if it exists in the system
						checkemail=true;
						currentuser=i;		
					}
				}
				if(checkemail==1){
					do{
						cout << "Enter password : ";
						for(i=0; i<9; i++){
							PASSWORD[i]=getch();
							cout << "*";
						}
						PASSWORD[i]='\0';
						cout<<endl;
						for(i=0; PASSWORD[i]!='\0'; i++){
					        cout << PASSWORD[i];
				        }
				        cout << pass[currentuser];
						if (strcmp(PASSWORD, pass[currentuser])==0){		
							login=true;
							cout << "\n\nPersonal Information\n====================\n";		//display the personal information after log in is successful
							cout << "Full Name : " << passLName[currentuser] << passFName[currentuser]<< endl;
							cout << "Date of Birth : " << dob[currentuser][0] << "/" << dob[currentuser][1] << "/" << dob[currentuser][2] << endl;
							cout << "Gender : " << gender[currentuser] << endl;
							cout << "Nationality : " << nationality[currentuser] << endl;
							cout << "Phone Number : 0" << number[currentuser] << endl ;
							if (strcmpi(nationality[currentuser], "MALAYSIAN")!=0){	
								cout << "\nTravel Document\n===================\n";
								cout << "Passport Number : " << passnum[currentuser] << endl;
								cout << "Passport Expiry Date : " << expirydate[currentuser][0] << "/" << expirydate[currentuser][1] << "/" << expirydate[currentuser][2] << endl;
							}
							cout << "Address : " << address[currentuser] << endl;
							cout << "Postcode: " << postc[currentuser] << endl;
							cout << "\nYOU HAVE LOGGED IN!\n\n";
						}
						else{
							cout << "\nWrong password. Please enter again\n";
						}
					}while(login!=true);
				}
				else{
					cout << "USER DOES NOT EXIST\n" << endl;
				}
				break;	
	
			case 'C' : case 'c' :
				if(login==false){
					cout << "YOU HAVE NOT LOGGED IN YET.\n" << endl;
				}
				else{
					login=false;
					cout << "YOU HAVE LOGGED OUT.\n";
				}
				break;
				
			case 'D' : case 'd' :
				if(login!=true){
					cout << "You must login to book flight ticket. Please login \n\n";
				}
				else{
					flightpage(ESeat, BSeat, ROW, email, passLName, passFName, dob, passnum);
				}
				break;
			case 'X' : case 'x' :
				break;
				
			default :
				cout << "Wrong input. Please enter again \n";
		}		
		cout << endl;
	}	
}

void flightpage(char EcoSeat[ESeatTot][4], char BusSeat[BSeatTot][4], int AROW, string *email, char passLName[cust][70], char passFName[cust][70], int dob[cust][3], string *passnum){
	
	int destination[cust], arrival[cust], departDay[cust], departMonth[cust], departYear[cust], returnDay[cust], returnMonth[cust], returnYear[cust], departTime[cust], returnTime[cust], numPass, passCount2, birthYear[10], dob2[numPass][3], c, f, e, k;
    char flightType[cust][10], cabin[9], user, citizen, seatPass[numPass][4];
    bool seatAvail[9];
    double totalPrice[cust];
    const double fuelPriceHour = 20000.0;
    string passLName2[70], passFName2[70], passportNum;
    int enteredTitle[10], foundReturn [cust], flagUser[cust];
    
    //return boolean for each customer
    for(i=0; i<cust; i++){
    	foundReturn[i]=0;
	}
    
    cout << " Welcome onboard, " << email[currentuser] << endl;
    
    cout << " Select departure airport :\n";
    for( i = 1; i < arraySize; i++ ){
        cout << "\t" << i << ". " << airport[i] << endl;   
	}
    cout << "From : ";
    cin >> destination[currentuser];

    while ( destination[currentuser] < 0 || destination[currentuser] > 32 || destination[currentuser] == false || destination[currentuser] == false && destination[currentuser]==true){  
    	cout << "Departure airport chosen is not on the list, please enter again : ";
        cin.clear();
        cin.ignore(256,'\n');
        cin >> destination[currentuser];
    }
    cout << destination[currentuser];
    cout << " Select arrival airport : \n";
    for( i = 1; i <arraySize; i++ ){
    	if( destination[currentuser] != i){
    	    cout << "\t" << i << ". " << airport[i] << "\n";
    	}
    } 
    cout << " To: ";
    cin >> arrival[currentuser];
    while( destination[currentuser] == arrival[currentuser] || arrival[currentuser] < 0 || arrival[currentuser] > 32 || arrival[currentuser] == false || arrival[currentuser] == false && arrival[currentuser] == true){
    	cout << "arrival airport chosen is not on the list, please enter again : ";
    	cin.clear();
        cin.ignore(256,'\n');
        cin >> arrival[currentuser]; 
    }
    cin.sync();
    cout << " One Way or Return ? ";
    cin.getline( flightType[currentuser], 9);
    cin.sync();
    while( strcmpi( flightType[currentuser], "return" )!=0 && strcmpi( flightType[currentuser], "one way" )!=0 ){
    	cout << " INVALID, please enter again : ";
    	cin.getline( flightType[currentuser], 9);
    }	
    	 // DEPART DATE 
    if(strcmpi( flightType[currentuser], "return" )==0 || strcmpi( flightType[currentuser], "one way" )==0){		
        cout << "Enter departure date day (dd) : ";
    	cin >> departDay[currentuser]; 
    	while(departDay[currentuser]>31 || departDay[currentuser]<1 || departDay[currentuser] == false || departDay[currentuser] == false && departDay[currentuser] == true){
    		cout << " Date is not valid, please enter again : ";
    		cin.clear();
            cin.ignore(256,'\n');
    		cin >> departDay[currentuser];
    	}
    	cout << "Enter departure month (mm) : ";
		cin >> departMonth[currentuser];
		while(departMonth[currentuser]>12 || departMonth[currentuser]<1 || departMonth[currentuser] == false || departMonth[currentuser] == false && departMonth[currentuser] == true){
			cout << " Month is not valid, please enter again : ";
			cin.clear();
            cin.ignore(256,'\n');
			cin >> departMonth[currentuser];
		}
		if( departMonth[currentuser] == 2){
		    if( ( departYear[currentuser]%400 == 0 ) || ( departYear[currentuser]%4 == 0 && departYear[currentuser]%100 != 0) ){
			    while(departDay[currentuser]>29 || departDay[currentuser]<=0 || departDay[currentuser] == false || departDay[currentuser] == false && departDay[currentuser] == true){
			   	    cout << " Date is not valid, please enter again : ";
			   	    cin.clear();
                    cin.ignore(256,'\n');
			   	    cin >> departDay[currentuser];
		        }
		    }else if( ( departYear[currentuser]%400 != 0 ) || ( departYear[currentuser]%4 != 0 && departYear[currentuser]%100 == 0) ){
		        while(departDay[currentuser]>28 || departDay[currentuser]<=0 || departDay[currentuser] == false || departDay[currentuser] == false && departDay[currentuser] == true){
		       	    cout << " Date is not valid, please enter again : ";
		       	    cin.clear();
                    cin.ignore(256,'\n');
			   	    cin >> departDay[currentuser];
		        }  
	        }
	    }
	    else if( departMonth[currentuser] > 0 && departMonth[currentuser] <= 12 ){
    	    if( departMonth[currentuser]%2!=0 && departMonth[currentuser] != 2){
    		    while(departDay[currentuser]>31 || departDay[currentuser]<=0 || departDay[currentuser] == false || departDay[currentuser] == false && departDay[currentuser] == true){
    		        cout << " Date is not valid, please enter again : ";
    		        cin.clear();
                    cin.ignore(256,'\n');
			   	    cin >> departDay[currentuser];
			    }
		    }else if( departMonth[currentuser]%2==0 && departMonth[currentuser] == 2){
    	 	    while(departDay[currentuser]>30 || departDay[currentuser]<=0 || departDay[currentuser] == false || departDay[currentuser] == false && departDay[currentuser] == true){
    	 	        cout << " Date is not valid, please enter again : ";
    	 	        cin.clear();
                    cin.ignore(256,'\n');
			   	    cin >> departDay[currentuser];
    	 	    }   
    	    }
        }
        cout << "Enter departure year (yyyy) : ";
		cin >> departYear[currentuser];
    	while(departYear[currentuser]<2023 || departYear[currentuser]==false || departYear[currentuser] == false && departYear[currentuser] == true){
    		cout << " Year is not valid, please enter again : ";
    		cin.clear();
            cin.ignore(256,'\n');
			cin >> departYear[currentuser];
    	}   
        
        // RETURN DATE 
        if(strcmpi( flightType[currentuser], "return" )==0){
        	foundReturn[currentuser]=1;
            cout << "Enter return date day (dd) : ";
    	    cin >> returnDay[currentuser]; 
    	    while(returnDay[currentuser]>31 || returnDay[currentuser]<1 || returnDay[currentuser]==false || returnDay[currentuser]==false && returnDay[currentuser]==true){
    		   cout << " Date is not valid, please enter again : ";
    		   cin.clear();
               cin.ignore(256,'\n');
    		   cin >> returnDay[currentuser];
    	    }
    	    cout << "Enter return month (mm) : ";
		    cin >> returnMonth[currentuser];
		    while(returnMonth[currentuser]>12 || returnMonth[currentuser]<1 || returnMonth[currentuser]==false || returnMonth[currentuser]==false && returnMonth[currentuser]==true){
			    cout << " Month is not valid, please enter again : ";
			    cin.clear();
                cin.ignore(256,'\n');
			    cin >> returnMonth[currentuser];
		    }
		    if( returnMonth[currentuser] == 2){
		        if( ( returnYear[currentuser]%400 == 0 ) || ( returnYear[currentuser]%4 == 0 && returnYear[currentuser]%100 != 0) ){
			        while(returnDay[currentuser]>29 || returnDay[currentuser]<=0 || returnDay[currentuser]==false || returnDay[currentuser]==false && returnDay[currentuser]==true){
			   	        cout << " Date is not valid, please enter again : ";
			   	        cin.clear();
                        cin.ignore(256,'\n');
			   	        cin >> returnDay[currentuser];
		            }
		        }else if( ( returnYear[currentuser]%400 != 0 ) || ( returnYear[currentuser]%4 != 0 && returnYear[currentuser]%100 == 0) ){
		            while(returnDay[currentuser]>28 || returnDay[currentuser]<=0 || returnDay[currentuser]==false || returnDay[currentuser]==false && returnDay[currentuser]==true){
		       	        cout << " Date is not valid, please enter again : ";
		       	        cin.clear();
                        cin.ignore(256,'\n');
			   	        cin >> returnDay[currentuser];
		            }  
	            }
	        }
	        else if( returnMonth[currentuser] > 0 && returnMonth[currentuser] <= 12 ){
    	        if( returnMonth[currentuser]%2!=0 && returnMonth[currentuser] != 2){  
    		        while(returnDay[currentuser]<=0 || returnDay[currentuser]>31 || returnDay[currentuser]==false || returnDay[currentuser]==false && returnDay[currentuser]==true){
    		            cout << " Date is not valid, please enter again : ";
    		            cin.clear();
                        cin.ignore(256,'\n');
			   	        cin >> returnDay[currentuser];
			        }
		        }else if( returnMonth[currentuser]%2==0 && returnMonth[currentuser] == 2){
    	 	        while(returnDay[currentuser]<=0 || returnDay[currentuser]>30 || returnDay[currentuser]==false || returnDay[currentuser]==false && returnDay[currentuser]==true){
    	 	            cout << " Date is not valid, please enter again : ";
    	 	            cin.clear();
                        cin.ignore(256,'\n');
			   	        cin >> returnDay[currentuser];
    	 	        }   
    	        }
            }
            cout << "Enter return year (yyyy) : ";
		    cin >> returnYear[currentuser];
    	    while( returnYear[currentuser]<2023 || (returnYear[currentuser]<departYear[currentuser] && returnMonth[currentuser]<=departMonth[currentuser] && returnDay[currentuser]<=departDay[currentuser] ) || (returnYear[currentuser]<=departYear[currentuser] && returnMonth[currentuser]<departMonth[currentuser] && returnDay[currentuser]<departDay[currentuser]) || (returnYear[currentuser]<=departYear[currentuser] && returnMonth[currentuser]<=departMonth[currentuser] && returnDay[currentuser]<departDay[currentuser]) || (returnYear[currentuser]<=departYear[currentuser] && returnMonth[currentuser]<departMonth[currentuser] && returnDay[currentuser]<=departDay[currentuser]) || returnYear[currentuser]==false || returnYear[currentuser]==false && returnYear[currentuser]==true){
    		    cout << " Year is not valid, please enter again : ";
    		    cin.clear();
                cin.ignore(256,'\n');
    	        cin >> returnYear[currentuser];
            }
            cout << " Your chosen date to depart is " << departDay[currentuser] << "/" << departMonth[currentuser] << "/" << departYear[currentuser] << endl;
    	    cout << " Your chosen date to return is " << returnDay[currentuser] << "/" << returnMonth[currentuser] << "/" << returnYear[currentuser] << endl;
}           
            ecoPrice = fuelPriceHour / 270.0;
        	busPrice = fuelPriceHour / 20.0;
            ecoPrice2 = fuelPriceHour*2.0 / 270.0;
        	busPrice2 = fuelPriceHour*2.0 / 20.0;
            
            //displaying flight timing and pricing
    	    for( i = 1; i < arraySize; i++ ){
                if( destination[currentuser] == i){
        	        cout << airport[i] << "\n";
        	        cout << "Departure Tickets Available :\t\tEconomic        Business \tFlight code" << endl;
        	        if(arrival[currentuser]>9 && arrival[currentuser]<33){
        	            if(i > 0 && i < 10 ){
        	                cout << setprecision(2)<<fixed;
        	                for(int c=1; c<t; c++){
        	          	 	    cout << "\t" << c << ". "<< time2[c] << "\tRM " << ecoPrice2 << "\tRM " << busPrice2 << "\t" << airplane2[c] << endl;
        	                }
                        }else if(i>9 && i<33){
        	                cout << setprecision(2)<<fixed;
        	                for(int c=1; c<t; c++){
        	          	 	    cout << "\t" << c << ". "<< time1[c] << "\tRM " << ecoPrice << "\tRM " << busPrice << "\t" << airplane1[c] << endl;
        	                }
        	            }
                    } 
                    else if(arrival[currentuser]>0 && arrival[currentuser]<10){
        	            if(i>9 && i<33){
        	               cout << setprecision(2)<<fixed;
        	               for(int c=1; c<t; c++){
        	          	 	    cout << "\t" << c << ". "<< time2[c] << "\tRM " << ecoPrice2 << "\tRM " << busPrice2 << "\t" << airplane1[c] << endl;
        	                }
                        }else if(i>0 && i<10){
        	                cout << setprecision(2)<<fixed;
        	                for(int c=1; c<t; c++){
        	          	 	    cout << "\t" << c << ". "<< time1[c] << "\tRM " << ecoPrice << "\tRM " << busPrice << "\t" << airplane2[c] << endl;
        	                }
                        }
                    }
                    cout << " Enter number your chosen time : ";
                    cin >> departTime[currentuser];
                    while(departTime[currentuser]<0 || departTime[currentuser]>5 || departTime[currentuser]==false || departTime[currentuser]==false && departTime[currentuser]==true){
        		        cout << " INVALID, please enter again : ";
        		        cin.clear();
                        cin.ignore(256,'\n');
        	     	    cin >> departTime[currentuser];
                    }
                    //displaying the time chosen by user
                    if(arrival[currentuser]>0 && arrival[currentuser]<10){
        	            if(i>9 && i<33){
                            for(j=0; j<t; j++){
                                if(j==departTime[currentuser]){
            	                   departTime[currentuser] = j;
            	                   time2[j] = time2[departTime[currentuser]];
            	                   cout << time2[departTime[currentuser]] << endl;
                                }
                            }
				        }else if(i>0 && i<10){
				   	        for(j=0; j<t; j++){
                                if(j==departTime[currentuser]){
            	                   departTime[currentuser] = j;
            	                   time1[j] = time1[departTime[currentuser]];
            	                   cout << time1[departTime[currentuser]] << endl;
                                }
		     	            }
		                }
		            }
		            if(arrival[currentuser]>9 && arrival[currentuser]<33){
        	            if(i > 0 && i < 10 ){ 
        	       	        for(j=0; j<t; j++){
                                if(j==departTime[currentuser]){
            	                   departTime[currentuser] = j;
            	                   time2[j] = time2[departTime[currentuser]];
            	                   cout << time2[departTime[currentuser]] << endl;
                                }
                            }
                        }else if(i>9 && i<33){
                   	        for(j=0; j<t; j++){
                                if(j==departTime[currentuser]){
            	                   departTime[currentuser] = j;
            	                   time2[j] = time2[departTime[currentuser]];
            	                   cout << time2[departTime[currentuser]] << endl;
                                }
                            }
                        }
                    }
                }
            } 
		}
		//displaying flight timing and pricing for return ticket
	    for( i = 1; i < arraySize; i++ ){	        
		if( arrival[currentuser] == i && foundReturn[currentuser]==1){
			cout << airport[i] << "\n";
			cout << "Return Tickets Available :\t\tEconomic        Business \tFlight code" << endl;
        	    if( destination[currentuser] > 0 && destination[currentuser] < 10){
        	        if(i>9 && i<33){
        	            cout << setprecision(2)<<fixed;
        	            for(int c=1; c < t; c++){
        	         	   cout << "\t" << c << ". " << time2[c] << "\tRM " << ecoPrice2 << "\tRM " << busPrice2 << "\t\t" << airplane1[c] << endl; 
        	            }
                    }else if(i>0 && i<10){
        	            cout << setprecision(2)<<fixed;
        	            for(int c=1; c<t; c++){
        	          	    cout << "\t" << c << ". "<< time1[c] << "\tRM " << ecoPrice << "\tRM " << busPrice << "\t" << airplane2[c] << endl;
        	            }
        	        }
                }
                else if( destination[currentuser]>9 && destination[currentuser]<33){
        	        if(i>0 && i<10){
        	            cout << setprecision(2)<<fixed;
        	            for(int c=1; c<t; c++){
        	          	    cout << "\t" << c << ". "<< time2[c] << "\tRM " << ecoPrice2<< "\tRM " << busPrice2 << "\t" << airplane2[c] << endl;
        	            }
                    }else if(i>9 && i<33){
        	            cout << setprecision(2)<<fixed;
        	            for(int c=1; c<t; c++){
        	          	    cout << "\t" << c << ". "<< time1[c] << "\tRM " << ecoPrice << "\tRM " << busPrice << "\t" << airplane1[c] << endl;
        	            }
        	        }
                } 
                cout << " Enter number your chosen time : ";
                cin >> returnTime[currentuser];
                while(returnTime[currentuser]<1 || returnTime[currentuser]>5 || returnTime[currentuser]==false || returnTime[currentuser]==false && returnTime[currentuser]==true){
        		    cout << " INVALID, please enter again : ";
        		    cin.clear();
                    cin.ignore(256,'\n');
        		    cin >> returnTime[currentuser];
                }
                //comparing if the user chose the same time for the same date, month and year in return ticket
                if(departYear[currentuser]==returnYear[currentuser] && departMonth[currentuser]==returnMonth[currentuser] && departDay[currentuser]==returnDay[currentuser]){
               	    while(returnTime[currentuser]<=departTime[currentuser] || returnTime[currentuser]==false || returnTime[currentuser]==false && returnTime[currentuser]==true){
               	        cout << " INVALID, you cant turn back the time : ";
               	  	    cin.clear();
                        cin.ignore(256,'\n');
               	  	    cin >> returnTime[currentuser];
               	    }
                }
                if( destination[currentuser] > 0 && destination[currentuser] < 10){
        	        if(i>9 && i<33){
                        for(j=0; j<t; j++){
                            if(j==returnTime[currentuser]){
            	               returnTime[currentuser] = j;
            	               time2[j] = time2[returnTime[currentuser]];
            	               cout << time2[returnTime[currentuser]] << endl;
                            }
                        }
                    }else if(i>0 && i<10){
                  	    for(j=0; j<t; j++){
                            if(j==returnTime[currentuser]){
            	               returnTime[currentuser] = j;
            	               time1[j] = time1[returnTime[currentuser]];
            	               cout << time1[returnTime[currentuser]] << endl;
                            }
                        }
                    }
                }else if( destination[currentuser]>9 && destination[currentuser]<33){
        	        if(i>0 && i<10){
        	      	    for(j=0; j<t; j++){
                            if(j==returnTime[currentuser]){
            	               returnTime[currentuser] = j;
            	               time2[j] = time2[returnTime[currentuser]];
            	               cout << time2[returnTime[currentuser]] << endl;
                            }
                        }
                    }else if(i>9 && i<33){
                  	    for(j=0; j<t; j++){
                            if(j==returnTime[currentuser]){
            	               returnTime[currentuser] = j;
            	               time1[j] = time1[returnTime[currentuser]];
            	               cout << time1[returnTime[currentuser]] << endl;
                            }
                        }
                    }
                }
            }
        }       
        //user's personal details and passengers
        while(true){
            cout << " Is user the only passenger (Y) or buying for others as well (N) ? ";
            cin >> user;
            if( user =='Y'|| user =='y'){ // to get reference from user registeration
                flagUser[currentuser]=1;
                break;
            }
            if(user =='N'|| user =='n'){
                cout << " Enter number of passengers : ";
                cin >> numPass;
        	    while(numPass<=0 || numPass>=10 || numPass==false || numPass==false && numPass==true){
        		    cout << " The limit passengers is 1 to 9, please enter again : ";
        		    cin.clear();
                    cin.ignore(256,'\n');
        		    cin >> numPass;		
        	    }
        	    break;
        	}
        }
        //flag for user's own ticket
        if(flagUser[currentuser]==1){
        	numPass=1;
		}
        passCount2=1;
                while(passCount2<=numPass){
        		    cout << "Enter cabin class for passenger "<< passCount2 << " ('E' or 'B') : ";
        	        cin >> cabin[passCount2-1];
        	        switch (cabin[passCount2-1]){
        		        case 'E' : case 'e' :		
						    for(AROW=1; AROW<=ESeatRow; AROW++){
							    for(c=0; c<66; c++){		
								    cout << "-";
							    }
							    cout << endl;
							    for(f=0; f<=5; f++){
								    cout << setw(6) << EcoSeat[k] << setw(5) << "|";			
								    k++;
							    }
							    cout << endl;	
						    }
						    do{		
							    cout << "\nEnter seat passenger " << passCount2 << " : ";
							    cin.sync();
						    	cin.getline(seatPass[passCount2-1], 4);
							    for(e=0; e<ESeatTot; e++){
								    if(strcmpi(seatPass[passCount2-1], EcoSeat[e])==0){	
									   seatAvail[passCount2-1]=true;
									   strcpy(EcoSeat[e], "X");	
								    }
							    }
							    if(seatAvail[passCount2-1]!=true){
								    cout << "Seat is not available. Please enter again \n";
							    }				
						    }while(seatAvail[passCount2-1]!=true || strcmp(seatPass[passCount2-1], "X")==0);
							    cout << endl;
							    k=0;
        		            break;
        		            case 'B' : case 'b' :			//for business class
							    for(AROW=1; AROW<=BSeatRow; AROW++){	//  function loadSeat before do-while registeration	with 45 rows
								    for(c=0; c<44; c++){			
								        cout << "-";
								    }
								    cout << endl;
								    for(f=0; f<=3; f++){
									    cout << setw(6) << BusSeat[k] << setw(5) << "|";			//displaying seating
									    k++;
								    }
								    cout << endl;	
							    }
							    do{	
								    cout << "\nEnter seat passenger " << passCount2 << " : ";
								    cin.sync();
							        cin.getline(seatPass[passCount2-1], 4);
							    	for(e=0; e<BSeatTot; e++){
									    if(strcmpi(seatPass[passCount2-1], BusSeat[e])==0){		//compare with all BSeat, if it has at least one same, seatAvail is set to true
										    seatAvail[passCount2-1]=true;
										    strcpy(BusSeat[e], "X");	
									    }
								    }
								    if(seatAvail[passCount2-1]!=true){
									   cout << "Seat is not available. Please enter again \n";
								    }		
							    }while(seatAvail[passCount2-1]!=true || strcmp(seatPass[passCount2-1], "X")==0);
								       cout << endl;
								       k=0;
        		                break;
        	           	    default : 
							   cout << " ENTER 'E' OR 'B' ONLY ";
							   passCount2--;
        	        }
        	        passCount2++;
                } 
                for(int z=1; z<=numPass; z++){
               	    cout << "\tPassenger " << z << endl;
               	    cout << "Titles : ";
               	    for(int i=1; i<title; i++ ){
                        cout << i << ". " << passtitle[i] << "\t";
                    }
                    cout << endl << "\t\tPreferred title : ";
                    cin >> enteredTitle[z];
                    while(enteredTitle[z]>=title || enteredTitle[z]<=0 || enteredTitle[z]==false || enteredTitle[z]==false && enteredTitle[z]==true){
                        cout << " Title entered is invalid, please enter again : ";
                        cin.clear();
                        cin.ignore(256,'\n');
                        cin >> enteredTitle[z];
                    }
                    for(j=1; j<title; j++){
                            if(j==enteredTitle[z]){
            	               enteredTitle[z] = j;
            	               passtitle[j] = passtitle[enteredTitle[z]];
            	               cout << "\t\t" << passtitle[enteredTitle[z]] << endl;
                            }
                    }
                    cin.sync();
                    //displaying the user's personal details from registeration function
                    if(flagUser[currentuser]==1){
                    	cout << "\t\tLast/Family name (as per passport or IC): " << passLName[currentuser] << endl;
                    	cout << "\t\tFirst name (as per passport or IC): " << passFName[currentuser] << endl;
                    	cout << "\t\tDate of birth (as per passport or IC) ex: ddmmyyyy : " << dob[currentuser][0] << "/" << dob[currentuser][1] << "/" << dob[currentuser][2] << endl;
                        if(dob[currentuser][2]>1923 && dob[currentuser][2]<=1953){
                            cout << "\tUse " << discountCode[3] << " discount code when you make a payment"<< endl;
                        }
						cout << "\t\tTravel Document\n===================\n";
						cout << "\t\tPassport Number : " << passnum[currentuser] << endl;  
					}
					else{
                    cout << "\t\tLast/Family name (as per passport or IC): ";
                    getline(cin, passLName2[z-1]);
                    cin.sync();
                    cout << "\t\tFirst name (as per passport or IC): ";
                    getline(cin, passFName2[z-1]);
                    cin.sync();
                    cout << "\t\tDay of birth (as per passport or IC): ";
                    cin >> dob2[z][0];
                    while(dob2[z][0]<1 || dob2[z][0]>31 || dob2[z][0]==false || dob2[z][0]==true && dob2[z][0]==false){
					cout << "Invalid day of birth. Please enter again : ";
					cin.clear();
    				cin.ignore(256,'\n');
					cin >> dob2[z][0];
				    }
				    cout << "\t\tMonth (mm): ";
				    cin >> dob2[z][1];
				    while(dob2[z][1]<1 || dob2[z][1]>12 || dob2[z][0]==false || dob2[z][0]==true && dob2[z][0]==false || dob2[z][0]==31 && (dob2[z][1]%2==0 && dob2[z][1]<=6 || dob2[z][1]==9 || dob2[z][1]==11) || dob2[z][1]==2 && dob2[z][0]>29){
					cout << "Invalid month of birth. Please enter again : ";
					cin.clear();
        			cin.ignore(256,'\n');
					cin >> dob2[z][1];
				    }
				    cout << "\t\tYear (yyyy): ";
				    cin >> dob2[z][2];
				    while(dob2[z][2]<1922 || dob2[z][2]>2023 || dob2[z][0]==false || dob2[z][0]==false && dob2[z][0]==true || dob2[z][0]==28 && dob2[z][1]==2 && dob2[z][2]%4==0){
					cout << "Invalid year of birth. Please enter again : ";
					cin.clear();
        			cin.ignore(256,'\n');
					cin >> dob2[z][2];
				    }
                    if(dob2[z][2]>1923 && dob2[z][2]<=1953){
                        cout << "\tUse " << discountCode[3] << " discount code when you make a payment" << endl;
                    }  
                    //for non malaysian passengers other than user registered
                    while(true){
                        cout << " Is Passenger " << z << " Malaysian or non Malaysian ? (Y if Malaysian / N if non Malaysian) : ";
                        cin >> citizen;
                        if( citizen =='N'|| citizen =='n'){
                           cout << " Enter passport number : ";
                           cin.ignore();
                           getline(cin, passportNum);
                           while(passportNum.length()<6 || passportNum.length()>12){
						         cout << "Invalid passport number. Please enter again : ";
						         cin.clear();
        				         cin.ignore(256,'\n');
						         getline(cin, passportNum);
					       }
                           break;
                        }
                        else if( citizen =='Y'|| citizen =='y'){
                        	break;
						}
                    }
                }
            }  
		
	payment(departYear, departMonth, departDay, returnYear, returnMonth, returnDay, departTime, returnTime, enteredTitle, arrival, cabin, numPass, seatPass, ecoPrice, busPrice, ecoPrice2, busPrice2, destination, flagUser, flightType,passCount2,passLName,passFName,passLName2,passFName2,foundReturn);
}
void payment(int *departYear, int *departMonth, int *departDay, int *returnYear, int *returnMonth, int *returnDay, int *departTime, int *returnTime, int *enteredTitle, int *arrival,char *cabin, int numPass, char seatPass[9][4], double ecoPrice, double busPrice, double busPrice2, double ecoPrice2, int *destination, int *flagUser,char flightType[cust][10],int passCount2,char passLName[cust][70],char passFName[cust][70],string passLName2[70],string passFName2[70],int *foundReturn){ /*ASTERISK FOR CALLING ARRAY VARIABLE*/

    string relay[4]={ "\n", " Parents", " Siblings", " Caretaker"};
    string disc,cardNum,cvv;
	int Class, passcount=1;
	double priceC1, priceC2, priceC3, busP1, busP2, busP3, totalPTax=0, ecoDiscP2, ecoDiscP3, busDiscP1, busDiscP2, busDiscP3, totalPtax=0.0, TOTALD=0.0,TOTAL;
	char conFName [15],conLName[15],conFon[12],conAdd[100],conEmail[50],PType, accept, lunch;
	int conAge,Month,Year,relationship;
	
	while(passcount<=numPass)	
	{ 
		switch(cabin[passcount-1])
	  {
	  	case'E': case'e':
	  			cout<<"1)Economy classic"<<"\nCabin baggage 7kg"<<"\nComplimentary snacks/meal & beverages"<<"\nNo check-in baggage"<<"\nNo child Discount"<<"\nNo free seat selection"<<"\nNo flexibility to board earlier on day of travel"<<"\nRebooking not available"<<"\nRefund not available"<<endl;
	  			cout<<"Normal price = RM "<< ecoPrice << " OR " << ecoPrice2 << endl;
	  			cout<<"\n2)Economy premium"<<"\nCabin baggage 7kg"<<"\nCheck-in baggage 20kg"<<"\nComplimentary snacks/meal & beverages"<<"\n10% child Discount"<<"\nRebooking:1x Free change fee(fare difference applies)"<<"\nRefund at a fee"<<"\nNo free seat selection"<<"\nNo flexibility to board earlier on day of travel"<<endl;
	  			cout<<"*for return ticket add on is added on both ticket"<<endl;
				cout<<"+RM45.50"<<endl;
	  			
	  			cout<<"\n3)Economy flex"<<"\nCabin baggage 7kg"<<"\nCheck-in baggage 35kg"<<"\nComplimentary snacks/meal & beverages"<<"\nLunch provided"<<"\n25% child Discount"<<"\nRebooking:Unlimited Free change fee(fare difference applies)"<<"\nFlexibility to board earlier on day of travel(subject to avaibility)";
				cout<<"\nRefund without fee" <<"\nPriority check in"<<"\nPriority Boarding"<<"\nPriority baggage"<<"\nBasic Travel Protection"<<endl;
	  			cout<<"*for return ticket add on is added on both ticket"<<endl;
				cout<<"+RM205.90"<<endl;
	  			
	  			cout<<"Choose Your Economy class type:";
	  			cin>>Class;
	  			if (Class==1){	
	  			
	  				if(arrival[currentuser]>9 && arrival[currentuser]<33){
        	            if(destination[currentuser] > 0 && destination[currentuser] < 10 ){
        	            	if(foundReturn[currentuser]==0){
        	            		priceC1 = ecoPrice2 + taxPrice;
								totalPTax+= priceC1;
							}	
							else if(foundReturn[currentuser]==1)
							{  priceC1 = (ecoPrice2 + taxPrice)*2;  
							   totalPTax+= priceC1; 
							}  	
					} 
						else if(destination[currentuser] > 9 && destination[currentuser] < 33 ){
							if(foundReturn[currentuser]==0){
								priceC1 = ecoPrice + taxPrice;
        	            		totalPTax+= priceC1; 	
							}
        	            	else if(foundReturn[currentuser]==1)
							{ priceC1 = (ecoPrice + taxPrice)*2;  
							   totalPTax+= priceC1; 
							} 
				        }
					}
					
					else if(arrival[currentuser]>0 && arrival[currentuser]<10){
        	            if(destination[currentuser] > 0 && destination[currentuser] < 10 ){
        	            	if(foundReturn[currentuser]==0){
        	            		priceC1 = ecoPrice + taxPrice;
	  				        	totalPTax+= priceC1;
        	            	}
	  				        else if(foundReturn[currentuser]==1)
							{ priceC1 = (ecoPrice + taxPrice)*2;  
							   totalPTax+= priceC1; 
							} 
	  				    }
						else if(destination[currentuser] > 9 && destination[currentuser] < 33 ){
	  				    	if(foundReturn[currentuser]==0){
	  				    		priceC1 = ecoPrice2 + taxPrice;
        	            		totalPTax+= priceC1; 	
	  				    	}
        	            	else if(foundReturn[currentuser]==1)
							 { priceC1 = (ecoPrice2 + taxPrice)*2;  
							   totalPTax+= priceC1; } 
				        }	
			        }
			    }
	  			else if (Class==2){	/*economy class 2 + 45.5*/
	  			
	  				if(arrival[currentuser]>9 && arrival[currentuser]<33){
        	            if(destination[currentuser] > 0 && destination[currentuser] < 10 ){
        	            	if(foundReturn[currentuser]==0){
        	            		priceC2 = ecoPrice2 + taxPrice + 45.50 ; 
	        	            	ecoDiscP2 = priceC2*0.9; 
								totalPTax+= priceC2;  	 	
        	            	}
							else if(foundReturn[currentuser]==1)
							 { priceC2 = (ecoPrice2 + taxPrice + 45.50)*2;
							   ecoDiscP2 = priceC2*0.9;  
							   totalPTax+= priceC2; } 
					} 
					else if(destination[currentuser] > 9 && destination[currentuser] < 33 ){
					  		if(foundReturn[currentuser]==0){
					  			priceC2 = ecoPrice + taxPrice + 45.50;
	        	            	ecoDiscP2 = priceC2*0.9; 
	        	            	totalPTax+= priceC2; 	
							}
							else if(foundReturn[currentuser]==1)
							 { priceC2 = (ecoPrice + taxPrice + 45.50)*2; 
							 ecoDiscP2 = priceC2*0.9; 
							   totalPTax+= priceC2; }  
				        }
					}
					else if(arrival[currentuser]>0 && arrival[currentuser]<10){
        	            if(destination[currentuser] > 0 && destination[currentuser] < 10 ){
        	            	if(foundReturn[currentuser]==0){
        	            		priceC2 = ecoPrice + taxPrice + 45.50;
		  				        ecoDiscP2 = priceC2*0.9; 
		  				        totalPTax+= priceC2; 	
        	            	}
							else if(foundReturn[currentuser]==1){ 
								priceC2 = (ecoPrice + taxPrice + 45.50)*2;  
								ecoDiscP2 = priceC2*0.9; 
								totalPTax+= priceC2; 
							}  
				        }else if(destination[currentuser] > 9 && destination[currentuser] < 33 ){
				        	if(foundReturn[currentuser]==0){
				        		priceC2 = ecoPrice2 + taxPrice + 45.50;
					        	ecoDiscP2 = priceC2*0.9; 
					        	totalPTax+= priceC2; 	
				        	} 
				        	else if(foundReturn[currentuser]==1)
							 { priceC2 = (ecoPrice2 + taxPrice + 45.50)*2; 
							 ecoDiscP2 = priceC2*0.9;  
							   totalPTax+= priceC2; } 
			            }
			    	}
			    	cout << "\tUse discount code " << discountCode[1] << " when checking out " << endl << endl;	
			    }
	  			else if(Class==3){	/*economy class 3 +205.9*/
	  			
	  				if(arrival[currentuser]>9 && arrival[currentuser]<33){
        	            if(destination[currentuser] > 0 && destination[currentuser] < 10 ){
        	            	if(foundReturn[currentuser]==0){
	        	            	priceC3 = ecoPrice2 + taxPrice + 205.90;
	        	            	ecoDiscP3 = priceC3*0.75; 
								totalPTax+= priceC3;  
							}
							else if(foundReturn[currentuser]==1)
							 { priceC3 = (ecoPrice2 + taxPrice + 205.90)*2; 
							 	ecoDiscP3 =priceC3*0.75; 
							   totalPTax+= priceC3; 
							}   	
					} 
					else if(destination[currentuser] > 9 && destination[currentuser] < 33 ){
					  		if(foundReturn[currentuser]==0){
	        	            	priceC3 = ecoPrice + taxPrice + 205.90;
	        	            	ecoDiscP3 = priceC3*0.75; 
	        	            	totalPTax+= priceC3; 
	        	            }
        	            	else if(foundReturn[currentuser]==1)
							 { priceC3 = (ecoPrice + taxPrice+ 205.90)*2;  
							 ecoDiscP3 = priceC3*0.75; 
							   totalPTax+= priceC3; } 
				        }
					}
					else if(arrival[currentuser]>0 && arrival[currentuser]<10){
        	            if(destination[currentuser] > 0 && destination[currentuser] < 10 ){
        	            	if(foundReturn[currentuser]==0){
		  				        priceC3 = ecoPrice + taxPrice + 205.90;
		  				        ecoDiscP3 = priceC3*0.75; 
		  				        totalPTax+= priceC3; 
		  				    }
	  				        else if(foundReturn[currentuser]==1)
							 { priceC3 = (ecoPrice + taxPrice + 205.90)*2;  
							 ecoDiscP3 = priceC3*0.75; 
							   totalPTax+= priceC3; 
							} 
	  				    }else if(destination[currentuser] > 9 && destination[currentuser] < 33 ){
	  				    	if(foundReturn[currentuser]==0){
							  	priceC3 = ecoPrice2 + taxPrice + 205.90;  
							 	ecoDiscP3 = priceC3*0.75; 
	        	            	totalPTax+= priceC3; 
	        	            }        	            	
        	            	else if(foundReturn[currentuser]==1)
							 { priceC3 = (ecoPrice2 + taxPrice + 205.90)*2;  
							 ecoDiscP3 = priceC3*0.75; 
							   totalPTax+= priceC3; } 
			            }
	  			    }
	  				cout<<"Lunch = a)Nasi lemak  b)Spagetti   c)Fish n Chip"<<endl;
	  				cin>>lunch;
	  				cout << "\tUse discount code " << discountCode[2] << " when checking out " << endl << endl;	
					}
	  		
	  			break;
		case'B': case'b':
	  			cout<<"1)Bussiness classic"<<"\nCabin baggage 7kg"<<"\nComplimentary snacks/meal & beverages"<<"\nLunch provided"<<"\n5% child Discount"<<"\nNo check-in baggage"<<"\nNo free seat selection"<<"\nNo flexibility to board earlier on day of travel"<<"\nRebooking not available"<<"\nRefund not available"<<endl;
	  			cout<<"Normal price = RM"<< busPrice << " OR " << busPrice2 <<endl;
	  			cout<<"\n2)Bussiness premium"<<"\nCabin baggage 7kg"<<"\nCheck-in baggage 20kg"<<"\nComplimentary snacks/meal & beverages"<<"\nLunch provided"<<"\n10% child Discount"<<"\nRebooking:1x Free change fee(fare difference applies)"<<"\nRefund at a fee"<<"\nUpgrade with Enrich Point"<<"\nNo free seat selection"<<"\nNo flexibility to board earlier on day of travel"<<endl;
	  			cout<<"*for return ticket add on is added on both ticket"<<endl;
				cout<<"+RM80.50"<<endl;
	  			cout<<"\n3)Business flex"<<"\nCabin baggage 7kg"<<"\nCheck-in baggage 35kg"<<"\nComplimentary snacks/meal & beverages"<<"\nLunch provided"<<"\n25% child Discount"<<"\nRebooking:Unlimited Free change fee(fare difference applies)"<<"\nFlexibility to board earlier on day of travel(subject to avaibility)";
				cout<<"\nRefund without fee"<<"\nPriority check in"<<"\nPriority Boarding"<<"\nPriority baggage"<<"\nBasic Travel Protection"<<endl;
	  			cout<<"*for return ticket add on is added on both ticket"<<endl;
				cout<<"+RM240.60"<<endl;
	  			
	  			cout<<"Choose Your Bussiness class :";
	  			cin>>Class;
	  			if (Class==1){
	  				if(arrival[currentuser]>9 && arrival[currentuser]<33){
        	            if(destination[currentuser] > 0 && destination[currentuser] < 10 ){
        	            	if(foundReturn[currentuser]==0){
	        	            	busP1 = busPrice2 + taxPrice;
	        	            	busDiscP1 = busP1*0.95;
								totalPTax+= busP1;   
							}
							else if(foundReturn[currentuser]==1)
							 { busP1 = (busPrice2 + taxPrice)*2;  
							 busDiscP1 = busP1*0.95;
							   totalPTax+= busP1; }	
					  } else if(destination[currentuser] > 9 && destination[currentuser] < 33 ){
					  		if(foundReturn[currentuser]==0){
	        	            	busP1 = busPrice + taxPrice;
	        	            	busDiscP1 =busP1*0.95;
	        	            	totalPTax+= busP1; 
	        	            }
        	            	else if(foundReturn[currentuser]==1)
							 { busP1 = (busPrice + taxPrice)*2;
							 busDiscP1 = busP1*0.95;  
							   totalPTax+= busP1; }	
				        }
					}
					else if(arrival[currentuser]>0 && arrival[currentuser]<10){
        	            if(destination[currentuser] > 0 && destination[currentuser] < 10 ){
        	            	if(foundReturn[currentuser]==0){
		  				        busP1 = busPrice + taxPrice;
		  				        busDiscP1 = busP1*0.95;
		  				        totalPTax+= busP1; 
		  				    }
	  				        else if(foundReturn[currentuser]==1)
							 { busP1 = (busPrice + taxPrice)*2; 
							 busDiscP1 = busP1*0.95; 
							   totalPTax+= busP1; }
	  				    }else if(destination[currentuser] > 9 && destination[currentuser] < 33 ){
	  				    	if(foundReturn[currentuser]==0){
	        	            	busP1 = busPrice2 + taxPrice ;
	        	            	busDiscP1 = busP1*0.95;
	        	            	totalPTax+= busP1; 
	        	            }
        	            	else if(foundReturn[currentuser]==1)
							 { busP1 = (busPrice2 + taxPrice)*2;  
							 busDiscP1 = busP1*0.95;
							   totalPTax+= busP1; }
			            	}
	  			    }
	  				cout<<"Lunch = a)Nasi lemak  b)Spagetti   c)Fish n Chip"<<endl;
	  				cin>>lunch;
	  				cout << "\tUse discount code " << discountCode[3] << " when checking out " << endl << endl;	
				}
	  			else if (Class==2)	/*bussiness class2 + 80.50*/
	  			{	
	  				if(arrival[currentuser]>9 && arrival[currentuser]<33){
        	            if(destination[currentuser] > 0 && destination[currentuser] < 10 ){
        	            	if(foundReturn[currentuser]==0){
	        	            	busP2 = busPrice2 + taxPrice + 80.50;  
	        	            	busDiscP2 = busP2*0.90;
								totalPTax+= busP2; 	
							}
							else if(foundReturn[currentuser]==1)
							 { busP2 = (busPrice2 + taxPrice + 80.50)*2;  
							 busDiscP2 = busP2*0.90;
							   totalPTax+= busP2; }
					} 
					else if(destination[currentuser] > 9 && destination[currentuser] < 33 ){
					  		if(foundReturn[currentuser]==0){
	        	            	busP2 = busPrice + taxPrice + 80.50;
	        	            	busDiscP2 = busP2*0.90;
	        	            	totalPTax+= busP2; 
	        	            }
        	            	else if(foundReturn[currentuser]==1)
							{ 
								busP2 = (busPrice + taxPrice + 80.50)*2;  
								busDiscP2 = busP2*0.90;
							   	totalPTax+= busP2; }
				        	}
					}
					else if(arrival[currentuser]>0 && arrival[currentuser]<10){
        	            if(destination[currentuser] > 0 && destination[currentuser] < 10 ){
        	            	if(foundReturn[currentuser]==0){
		  				        busP2 = busPrice + taxPrice + 80.50;
		  				        busDiscP2 = busP2*0.90;
		  				        totalPTax+= busP2; 
		  				    }
	  				        else if(foundReturn[currentuser]==1)
							 { busP2 = (busPrice + taxPrice + 80.50)*2;  
							 busDiscP2 = busP2*0.90;
							   totalPTax+= busP2; }
							   
	  				    }
						else if(destination[currentuser] > 9 && destination[currentuser] < 33 ){
	  				    	if(foundReturn[currentuser]==0){
	        	            	busP2 = busPrice2 + taxPrice + 80.50;
	        	            	busDiscP2 = busP2*0.90;
	        	            	totalPTax+= busP2; 
	        	            }
        	            	else if(foundReturn[currentuser]==1)
							 { 
								busP2 = (busPrice2 + taxPrice + 80.50)*2;  
								busDiscP2 = busP2*0.90;
								totalPTax+= busP2; 
							}
			            }
	  			    }
	  				cout<<"Lunch = a)Nasi lemak  b)Spagetti   c)Fish n Chip"<<endl;
	  				cin>>lunch;
	  				cout << "\tUse discount code " << discountCode[1] << " when checking out " << endl << endl;
				}
	  			else if(Class==3)	/*business class3 + 240.6*/
	  			{	
	  				if(arrival[currentuser]>9 && arrival[currentuser]<33){
        	            if(destination[currentuser] > 0 && destination[currentuser] < 10 ){
        	            	if(foundReturn[currentuser]==0){
        	            		busP3 = busPrice2 + taxPrice + 240.60; 
								busDiscP3 = busP3*0.75; 
								totalPTax+= busP3; 
							}	
							else if(foundReturn[currentuser]==1)
							 { busP3 = (busPrice2 + taxPrice +240.60)*2;  
							 busDiscP3 = busP3*0.75; 
							   totalPTax+= busP3; }
							   
					  } else if(destination[currentuser] > 9 && destination[currentuser] < 33 ){
					  		if(foundReturn[currentuser]==0){
					  			busP3 = busPrice + taxPrice + 240.60;
	        	            	busDiscP3 = busP3*0.75; 
	        	            	totalPTax+= busP3; 
							}
        	            	else if(foundReturn[currentuser]==1)
							{ busP3 = (busPrice + taxPrice + 240.60)*2;  
							 busDiscP3 = busP3*0.75; 
							   totalPTax+= busP3; 
							}
				        }
					}
					else if(arrival[currentuser]>0 && arrival[currentuser]<10){
        	            if(destination[currentuser] > 0 && destination[currentuser] < 10 ){
        	            	if(foundReturn[currentuser]==0){
        	            		busP3 = busPrice + taxPrice + 240.60;
		  				        busDiscP3 = busP3*0.75; 
		  				        totalPTax+= busP3;
							}
							else if(foundReturn[currentuser]==1)
							 { busP3 = (busPrice + taxPrice + 240.60)*2; 
							 busDiscP3 = busP3*0.75;  
							   totalPTax+= busP3; } 
	  				    }else if(destination[currentuser] > 9 && destination[currentuser] < 33 ){
	  				    	if(foundReturn[currentuser]==0){
	        	            	busP3 = busPrice2 + taxPrice + 240.60 ;
	        	            	busDiscP3 = busP3*0.75; 
	        	            	totalPTax+= busP3; 
	        	            }
        	            	else if(foundReturn[currentuser]==1)
							 { busP3 = (busPrice2 + taxPrice + 240.60)*2;  
							 busDiscP3 = busP3*0.75; 
							   totalPTax+= busP3; }
			            }
	  			    }
	  				cout<<"Lunch = a)Nasi lemak  b)Spagetti   c)Fish n Chip"<<endl;
	  				cin>>lunch;
	  				cout << "\tUse discount code " << discountCode[2] << " when checking out " << endl << endl;
				}
	  			break;          
   	        }
   	passcount++;
   }
	cout<<endl<<"EMERGENCY INFORMATION"<<endl;
	cin.ignore();
	cout<<"First Name :";
	cin.getline(conFName, 15);
	cin.sync();

	cout<<"Last Name :";
	cin.getline(conLName, 15);
		cin.sync();
		
	cout<<"Age :";
	cin>>conAge;
	while (conAge<=0 || conAge>=100 || conAge==false || conAge==false && conAge==true)
	{ cout<<"Guardian can't be more than 100,please enter again :";
	  cin.clear();
      cin.ignore(256,'\n');
	  cin >> conAge;}	
	
	cout<<"Number phone :";
	cin>>conFon;
	
	cin.ignore();
	cout<<"Email :";
	cin.getline(conEmail, 50);

	cout<<"Address :";
	cin.getline(conAdd,100);

    for(i=1; i<4; i++){
    	cout<< i << ". " << relay[i] << '\t';
    	
	}
	cout<<"Relationship :";
	cin>>relationship;
	while(relationship<1 || relationship>3)
	{
		cout<<"Invalid,Please enter again : ";
		cin>>relationship;
	}
    
    cout << "----------------PAYMENT-----------------"<<endl;
	cout<<"Payment by Visa or Master? (V/M) :";
	cin>>PType;
	if (PType != 'V' && PType != 'v' && PType != 'M' && PType != 'm') 
	{
		
			cout<<"Invalid,Please enter again :";
			cin>>PType;
	}
	
	cout<<"Enter card number 16 digit :";
	cin >> cardNum;
	while (cardNum.length() != 16)
	{
		cout<<"Invalid card number,Please enter again :";
		cin >> cardNum;
	}

	cout << "Enter month (mm) : ";
	cin >>Month;
	while(Month>12 || Month<1 || Month==false || Month==false && Month==true){
		cout << " Month is not valid, please enter again : ";
		cin >> Month;
	}
	cout << "Enter year (yyyy) : ";
	cin >>Year;
	while(Year<2023 || Year==false || Year==false && Year==true){
		cout << " Year is not valid, please enter again : ";
		cin >> Year;
	}
	cout<<"Enter CVV/CVV2:";
	cin >> cvv;
	while(cvv.length()!=3)
	{
		cout<<"Invalid CVV/CVV2,Please enter again :";
		cin.clear();
		cin.ignore(256, '\n');
		cin >> cvv;
	}
	cout << "Payment after tax (RM65.00 each ticket) : RM" << totalPTax << endl;

	passcount=1;
	while(passcount<=numPass){
            cout<<"Do you want to enter discount code? Y/N :";
            cin >> accept;
            if(  accept =='Y'|| accept =='y'){
            	cin.ignore();
                cout<<"Enter discount code :";
				getline(cin, disc);
				
				switch(cabin[passcount-1]) {
				
				case 'E' : case 'e' :
					if(disc==discountCode[1])
						{ TOTALD += ecoDiscP2;
						}
					else if(disc==discountCode[2])
						{ TOTALD += ecoDiscP3;
						}         
              		break;
                case 'B' : case 'b' :
					if(disc==discountCode[1])
						{ TOTALD += busDiscP2;
						}
					else if(disc==discountCode[2])
						{ TOTALD += busDiscP3;
						}         
					else if(disc==discountCode[3])
						{ TOTALD += busDiscP1;
						}	
               		break;
                }  
            }
   		passcount++;
	}
        /*receipt*/
       
        cout<<"Total discount : RM"<<TOTALD <<endl;
        cout<<"Total after discount : RM "<< totalPTax - TOTALD << endl;
    ticket(flightType, numPass,passLName,passFName,passLName2,passFName2,destination,arrival,departDay,departMonth,departYear,cabin,flagUser,departTime,passcount,Class,seatPass,returnYear,returnMonth,returnDay,returnTime,foundReturn);
}
void ticket(char flightType[cust][10],int numPass, char passLName[cust][70], char passFName[cust][70],string *passLName2, string *passFName2,int *destination, int *arrival,int *departDay, int *departMonth, int *departYear, char cabin[9],int *flagUser,int *departTime,int passcount, int Class,char seatPass[9][4],int *returnYear, int *returnMonth, int *returnDay,int *returnTime,int *foundReturn){
	
	int passCount3, passCount4, passCount5, passCount6;

	if(strcmpi( flightType[currentuser], "return" )==0 || strcmpi( flightType[currentuser], "one way" )==0){
		passCount3=1;
		while(passCount3<=numPass){
			cout<<"\nTHIS IS YOUR BOARDING PASS"<<endl;
			cout<<"_____________________________________________________________________________________\n";
			if (cabin[passCount3-1]=='E' || cabin[passCount3-1]=='e' )
				cout<<setw(50)<<"ECONOMY"<<endl;
			else 
			cout<<setw(50)<<"BUSINESS" << endl;
			
			
		    if (flagUser[currentuser]==1){
				cout<<setw(50)<<"NAME "<<passLName[currentuser]<<" "<<passFName[currentuser]<<endl;
			}else{
				cout<<setw(50)<<"NAME "<<passLName2[passCount3-1]<<" "<<passFName2[passCount3-1]<<endl;
			}
			
			cout<<setw(50)<<"DATE "<<departDay[currentuser]<<"/"<<departMonth[currentuser]<<"/"<<departYear[currentuser]<<endl;
			
		   for(i=1; i< arraySize; i++){
			  if( destination[currentuser] == i){
				cout<<setw(50)<<"FROM "<<airport[i]<<endl;
			  }
			  if( arrival[currentuser] == i){
			 	cout<<setw(50)<<"TO "<<airport[i]<<endl;
			  }
			}
		    if(arrival[currentuser]>0 && arrival[currentuser]<10){
        	    if(i>9 && i<33){						
                    for(j=0; j<t; j++){
                        if(j==departTime[currentuser]){
            	            departTime[currentuser] = j;
            	            time2[j] = time2[departTime[currentuser]];
            	            cout <<setw(50)<< time2[departTime[currentuser]] << endl;
            	            cout<<setw(50)<< airplane2[t];
                        }
                                
                    }
				}else if(i>0 && i<10){
				    for(j=0; j<t; j++){
                        if(j==departTime[currentuser]){
            	            departTime[currentuser] = j;
            	            time1[j] = time1[departTime[currentuser]];
            	            cout << setw(50)<<time1[departTime[currentuser]] << endl;
            	            cout<<setw(50)<< airplane1[t];
                        }
		     	    }
		        }
		    }
		    if(arrival[currentuser]>9 && arrival[currentuser]<33){
        	    if(i > 0 && i < 10 ){ 
        	       	for(j=0; j<t; j++){
                        if(j==departTime[currentuser]){
            	            departTime[currentuser] = j;
            	            time2[j] = time2[departTime[currentuser]];
            	            cout <<setw(50)<< time2[departTime[currentuser]] << endl;
            	            cout<< setw(50)<<airplane2[t];
                        }
                    }
                }else if(i>9 && i<33){
                   	for(j=0; j<t; j++){
                        if(j==departTime[currentuser]){
            	            departTime[currentuser] = j;
            	            time2[j] = time2[departTime[currentuser]];
            	            cout <<setw(50)<< time2[departTime[currentuser]] << endl;
            	            cout<< setw(50)<<airplane2[t];
                        }
                    }
                }
            } 
			cout<<setw(50)<<"SEAT "<<seatPass[passCount3-1] <<endl;
			cout<<"_____________________________________________________________________________________\n" << endl;
			passCount3++;
		}
	}  //while loop
	if(strcmpi( flightType[currentuser], "return" )==0)
	{
		passCount4=1;
		while(passCount4<=numPass){
			cout<<setw(50)<<"\nTHIS IS YOUR BOARDING PASS"<<endl;
			cout<<"_____________________________________________________________________________________\n" << endl;
			if (cabin[passCount4-1]=='E' || cabin[passCount4-1]=='e')
				cout<<setw(50)<<"\t\tECONOMY"<<endl;
			else 
			    cout<<setw(50)<<"\t\tBUSINESS"<<endl;
			
			if (flagUser[currentuser]==1){
				cout<<setw(50)<<"NAME "<<passLName[currentuser]<<" "<<passFName[currentuser]<<endl;
			}else {
				cout<<setw(50)<<"NAME "<<passLName2[passCount4-1]<<" "<<passFName2[passCount4-1]<<endl;
			}

			cout<<setw(50)<<"DATE "<<returnDay[currentuser] << "/" << returnMonth[currentuser] << "/" << returnYear[currentuser] << endl;
			
			for(i=1; i< arraySize; i++){
			  if( arrival[currentuser] == i){
				cout<<setw(50)<<"FROM "<<airport[i]<<endl;
			  }
			  if( destination[currentuser] == i){
			 	cout<<setw(50)<<"TO "<<airport[i]<<endl;
			  }
		    }
		    if(arrival[currentuser]>0 && arrival[currentuser]<10){
	            if(i>9 && i<33){
	                for(j=0; j<t; j++){
	                    if(j==returnTime[currentuser]){
		                   returnTime[currentuser] = j;
		                   time2[j] = time2[returnTime[currentuser]];
		                   cout << setw(50)<<time2[returnTime[currentuser]] << endl;
		                   cout<<setw(50)<< airplane2[t];
	                    }
	                    
	                }
		        }
				else if(i>0 && i<10){
		   	        for(j=0; j<t; j++){
	                    if(j==returnTime[currentuser]){
		                   returnTime[currentuser] = j;
		                   time1[j] = time1[returnTime[currentuser]];
		                   cout <<setw(50)<< time1[returnTime[currentuser]] << endl;
		                   cout<< setw(50)<<airplane1[t];
	                    }
	 	            }
	            }
		    }
		            if(arrival[currentuser]>9 && arrival[currentuser]<33){
        	            if(i > 0 && i < 10 ){ 
        	       	        for(j=0; j<t; j++){
                                if(j==returnTime[currentuser]){
            	                   returnTime[currentuser] = j;
            	                   time2[j] = time2[returnTime[currentuser]];
            	                   cout << setw(50)<<time2[returnTime[currentuser]] << endl;
            	                   cout<< setw(50)<<airplane2[t];
                                }
                            }
                        }else if(i>9 && i<33){
                   	        for(j=0; j<t; j++){
                                if(j==returnTime[currentuser]){
            	                   returnTime[currentuser] = j;
            	                   time2[j] = time2[returnTime[currentuser]];
            	                   cout << setw(50)<<time2[returnTime[currentuser]] << endl;
            	                   cout<< setw(50)<<airplane2[t];
                                }
                            }
                        }
                    }
                
                
			cout<<setw(50)<<"SEAT "<<seatPass[passCount4-1] << endl;
			cout<<"_____________________________________________________________________________________\n" << endl;
			passCount4++;	
		}
	}

	cout<<setw(50)<<"\nSECURITY REQUIREMENTS\n"<<"1.Ensure that your baggage is in your possession at all times\n"<<"2.You must be aware of the contents in your baggage\n";
	cout<<setw(50)<<"3.You need to be aware that the classified dangerous goods are not permitted in your baggage\n";
	cout<<setw(50)<<"IMPORTANT NOTICE\n"<<"1.Boarding gate closes 20 minutes before departure time\n"<<"2.Ensure that you have all the valid travel documents with you\n";
	cout<<setw(50)<<"3.For travel within Malaysia, ensure that you have bring along your valid Passport or Malaysia MyKad or birth certificate\n";

}