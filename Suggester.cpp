#include <iostream>
#include <string> //file handeling
#include<fstream> // file handeling
#include<iomanip> //file handeling
#include <stdlib.h> //for clearing output
using namespace std;
using std::string;

class Hotels
{
public:
    string name;
    string address;
    float ratings;
    //RATES
    float NonACRate;// non - AC
    float regularACRate;//AC
    float wtbfst;// AC With Breakfast
    float bfstlunchdnr;//AC With Breakfast + Lunch + Dinner
    float premium;
    float deluxe;
    
public:
    Hotels(string xname, string xaddress, float xratings, float xNonACRate, float xregularACRate, float xwtbfst, float xbfstlunchdnr, float xpremium, float xdeluxe){
        name = xname;
        address = xaddress;
        ratings = xratings;
        NonACRate = xNonACRate;
        regularACRate = xregularACRate;
        wtbfst = xwtbfst;
        bfstlunchdnr = xbfstlunchdnr;  
        premium = xpremium;
        deluxe = xdeluxe;      
    }

    float showrooms(){
        label2:
        cout<<"\n\n\t\tThe types of rooms available are:\n"<<endl;
        if(NonACRate!=0){
            cout<<"\t\tNon AC Room - "<<NonACRate<< " Rs Per Night"<<"(Room Code: a)"<<endl;
        }
        if(regularACRate!=0){
            cout<<"\t\tAC Room - "<<regularACRate<< " Rs Per Night"<<"(Room Code: b)"<<endl;
        }
        if(wtbfst!=0){
            cout<<"\t\tAC Room (Breakfast included) - "<<wtbfst<< " Rs Per Night"<<"(Room Code: c)"<<endl;
        }
        if(bfstlunchdnr!=0){
            cout<<"\t\tAC Room (Breakfast + Lunch + Dinner included) - "<<bfstlunchdnr<< " Rs Per Night"<<"(Room Code: d)"<<endl;
        }
        if(premium!=0){
            cout<<"\t\tAC Premium Room- "<<premium<< " Rs Per Night"<<"(Room Code: e)"<<endl;
        }
        if(deluxe!=0){
            cout<<"\t\tAC Deluxe Room - "<<deluxe<< " Rs Per Night"<<"(Room Code: f)"<<endl;
        }
        char xroomcode;
        cout<<"\n\t\tEnter the Room Code of the desired room: ";
        cin>>xroomcode;
        system("CLS");
        if(xroomcode == 'a'){return NonACRate;}
        else if(xroomcode == 'b'){return regularACRate;}
        else if(xroomcode == 'c'){return wtbfst;}
        else if(xroomcode == 'd'){return bfstlunchdnr;}
        else if(xroomcode == 'e'){return premium;}
        else if(xroomcode == 'f'){return deluxe;}
        else{
            cout<<"\t\tEnter a valid roomcode"<<endl;
            goto label2;
            return 0;
        }
    }
    //spacing should be proper between every column.

    void tellammount(float rate){
        int nights,nrooms;
        float charge;
        cout<<"\n\n\t\tEnter the number of rooms you want: ";
        cin>>nrooms;
        cout<<"\n\t\tEnter the number of nights you want to stay: ";
        cin>>nights;
        charge = nights*rate*nrooms;
        cout<<"\n\t\tThe total cost for "<< nights<< " nights will be: "<<charge<<" Rs"<<endl;
        
    }
    
};

//CLASS FOR CUSTOMER

class Customer{
public:
    string name, gender, emailid;
    long int phonenum;

//METHOD TO GET CUSTOMER DEATAILS
void getDetails()
    {
        ofstream out("old-customers.txt", ios::app);
        {
            system("CLS");
        cout<<"\n\n\t\tEnter Your Name: ";
        cin>>name;
        cout<<"\t\tEnter Gender: ";
        cin>>gender;
        cout<<"\t\tEnter Email I-D: ";
        cin>>emailid;
        cout<<"\t\tEnter MobileNo: ";
        cin>>phonenum;
        }
        
        out<<"\nName: "<<name<<"\nGender: "<<gender<<"\n Email: "<<emailid<<"\nPhone Number: "<<phonenum<<"\n========================================";
        out.close();
        cout<<"\n\t\tSAVED \n\t\tNOTE: We saved your record for future purpose\n";
    }
 };

////////////////////////// U got it!!! VishwaCTF{LbjtQY_449yfcD}
int main()
{
    //STORING DATA
    Hotels h1 = Hotels("Area 37 Club", "Kondhwa", 4.2, 4512, 0, 0, 0, 0, 0);
    Hotels h2 = Hotels("Hotel Utsak Deluxe", "Kondhwa", 3.7, 2417, 2110, 0, 0, 0, 0);
    Hotels h3 = Hotels("Townhouse OAK Classic Grande", "Kondhwa", 3.8, 1817, 2099, 2216, 3603, 0, 0);
    Hotels h4 = Hotels("FabHotel Nandanvan", "Kondhwa", 4.4, 2000, 0, 2160, 0, 0, 0);
    Hotels h5 = Hotels("Novotel Pune", "Viman Nagar", 4.1, 0, 5000, 0, 0, 7600, 10600);
    Hotels h6 = Hotels("Hotel Parc Estique", "Viman Nagar", 4.0, 2000, 0, 2160, 0, 0, 0);
    Hotels h7 = Hotels("Lemon Tree Hotel", "Viman Nagar", 4.1, 1944, 4099, 4524, 0, 0, 0);
    Hotels h8 = Hotels("Magnus Square", "Viman Nagar", 3.7, 1099, 1550, 0, 0, 0, 0);
    Hotels h9 = Hotels("E Square", "Shivaji Nagar", 4.1, 0, 3240, 0, 0, 3995, 4750);
    Hotels h10 = Hotels("JW Marriot", "Shivaji Nagar", 4.4, 0, 10000, 11000, 12500, 0, 0);
    Hotels h11 = Hotels("Centurion INN", "Shivaji Nagar", 3.4, 0, 1777, 1841, 2310, 0, 0);
    Hotels h12 = Hotels("Hotel Parichay", "Shivaji Nagar", 4.0, 1930, 2434, 0, 0, 0, 0);
    Hotels h13 = Hotels("Hotel Ashish Plaza", "Shivaji Nagar", 3.5, 0, 1868, 0, 0, 0, 0);
    Hotels h14 = Hotels("Hotel Supreme Heritage", "Kalyani Nagar", 3.8, 0, 1735, 1972, 2957, 0, 0);
    Hotels h15 = Hotels("Hyatt Pune", "Kalyani Nagar", 4.2, 0, 5750, 0, 0, 6750, 10250);
    Hotels h16 = Hotels("Hotel Sangram", "Kalyani Nagar", 3.5, 1259, 2013, 2223, 0, 0, 0);
    Hotels h17 = Hotels("St. Lauran", "Koregaon Park", 3.8, 0, 3037, 3394, 4037, 0, 0);
    Hotels h18 = Hotels("O Hotel Pune", "Koregaon Park", 4.1, 0, 3240, 0, 0, 3995, 4750);
    Hotels h19 = Hotels("Kapila Buisness Hotel", "Koregaon Park", 3.9, 0, 2608, 3031, 0, 0, 0);
    Hotels chosenhotel = Hotels("0", "0", 0, 0, 0, 0, 0, 0, 0);

    //START

    int option;
    int cnumber;
    int o1;
    char o2;
    int o3;
    label:
        system("CLS");
    cout<<"\n\n\t\t=======WELCOME TO HAPPY HOTELS===========\n";
    cout<<"\t\tEnter the area you want to find a hotel in"<<endl;
    cout<<"\t\t1. Kondhwa"<<endl;
    cout<<"\t\t2. Viman Nagar"<<endl;
    cout<<"\t\t3. Shivaji Nagar"<<endl;
    cout<<"\t\t4. Kalyani Nagar"<<endl;
    cout<<"\t\t5. Koregaon Park"<<endl;
    cout<<"\t\tEnter your choice: ";
    cin>>option;
    system("CLS");
    label3:
    cout<<"\t\t========================================================";
    switch (option)
    {
    case 1:            //KONDHWA
        
        float yrate;
        cout<<"\n\n\t\tSelect Hotel in Kondwa"<<endl;
        cout<<"\t\t1. "<<h1.name<<"   ["<<h1.ratings<<"/5 star rating]"<<endl;
        cout<<"\t\t2. "<<h2.name<<"   ["<<h2.ratings<<"/5 star rating]"<<endl;
        cout<<"\t\t3. "<<h3.name<<"   ["<<h3.ratings<<"/5 star rating]"<<endl;
        cout<<"\t\t4. "<<h4.name<<"   ["<<h4.ratings<<"/5 star rating]"<<endl;
        cout<<"\t\t Enter your choice: ";
        cin>>o1;
        system("CLS");
        if(o1 ==1)  {yrate = h1.showrooms();
                    h1.tellammount(yrate);}
        else if(o1 ==2){yrate = h2.showrooms();
                    h2.tellammount(yrate);}
        else if(o1 ==3){yrate = h3.showrooms();
                    h3.tellammount(yrate);}
        else if(o1 ==4){yrate = h4.showrooms();
                    h4.tellammount(yrate);}
        else {cout<<"Invalid Option";
                goto label3;
                }            
        break;

    case 2:            //VIMAN NAGAR
        
        cout<<"\n\n\t\tSelect a Hotel in Viman Nagar"<<endl;
        cout<<"\t\t1. "<<h5.name<<"   ["<<h5.ratings<<"/5 star rating]"<<endl;
        cout<<"\t\t2. "<<h6.name<<"   ["<<h6.ratings<<"/5 star rating]"<<endl;
        cout<<"\t\t3. "<<h7.name<<"   ["<<h7.ratings<<"/5 star rating]"<<endl;
        cout<<"\t\t4. "<<h8.name<<"   ["<<h8.ratings<<"/5 star rating]"<<endl;
        cout<<"\t\t Enter your choice: ";
        cin>>o1;
        system("CLS");
        if(o1 ==1)  {yrate = h5.showrooms();
                    h5.tellammount(yrate);}
        else if(o1 ==2){yrate = h6.showrooms();
                    h6.tellammount(yrate);}
        else if(o1 ==3){yrate = h7.showrooms();
                    h7.tellammount(yrate);}
        else if(o1 ==4){yrate = h8.showrooms();
                    h8.tellammount(yrate);}
        else {cout<<"Invalid Option";
                goto label3;
                }
        break;

    case 3:             //SHIVAJI NAGAR
        
        cout<<"\n\n\t\tSelect a Hotel in Shivaji Nagar"<<endl;
        cout<<"\t\t1. "<<h9.name<<"   ["<<h9.ratings<<"/5 star rating]"<<endl;
        cout<<"\t\t2. "<<h10.name<<"   ["<<h10.ratings<<"/5 star rating]"<<endl;
        cout<<"\t\t3. "<<h11.name<<"   ["<<h11.ratings<<"/5 star rating]"<<endl;
        cout<<"\t\t4. "<<h12.name<<"   ["<<h12.ratings<<"/5 star rating]"<<endl;
        cout<<"\t\t5. "<<h13.name<<"   ["<<h13.ratings<<"/5 star rating]"<<endl;
        cout<<"\t\t Enter your choice: ";
        cin>>o1;
        system("CLS");

        if(o1 ==1)  {yrate = h5.showrooms();
                        h5.tellammount(yrate);}
        else if(o1 ==2){yrate = h10.showrooms();
                        h10.tellammount(yrate);}
        else if(o1 ==3){yrate = h11.showrooms();
                        h11.tellammount(yrate);}
        else if(o1 ==4){yrate = h12.showrooms();
                        h12.tellammount(yrate);}
        else if(o1 ==5){yrate = h13.showrooms();
                        h13.tellammount(yrate);}
        else {cout<<"Invalid Option";
                goto label3;
                }
        break;
        case 4:           //KALYANI NAGAR
        
        cout<<"\n\n\t\tSelect a Hotel in Kalyani Nagar"<<endl;
        cout<<"\t\t1. "<<h14.name<<"   ["<<h14.ratings<<"/5 star rating]"<<endl;
        cout<<"\t\t2. "<<h15.name<<"   ["<<h15.ratings<<"/5 star rating]"<<endl;
        cout<<"\t\t3. "<<h16.name<<"   ["<<h16.ratings<<"/5 star rating]"<<endl;
        cout<<"\t\t Enter your choice: ";
        cin>>o1;
        system("CLS");
        if(o1 ==1)  {yrate = h14.showrooms();
                        h14.tellammount(yrate);}
        else if(o1 ==2){yrate = h15.showrooms();
                        h15.tellammount(yrate);}
        else if(o1 ==3){yrate = h16.showrooms();
                        h16.tellammount(yrate);}
        else {cout<<"Invalid Option";
                goto label3;
                }

        break;

        case 5:             //KOREGAON PARK
        
        cout<<"\n\n\t\tSelect a Hotel in Koregaon Park"<<endl;
        cout<<"\t\t1. "<<h17.name<<"   ["<<h17.ratings<<"/5 star rating]"<<endl;
        cout<<"\t\t2. "<<h18.name<<"   ["<<h18.ratings<<"/5 star rating]"<<endl;
        cout<<"\t\t3. "<<h19.name<<"   ["<<h19.ratings<<"/5 star rating]"<<endl;
        cout<<"\t\t Enter your choice: ";
        cin>>o1;
        system("CLS");
        if(o1 ==1)  {yrate = h17.showrooms();
                        h17.tellammount(yrate);}
        else if(o1 ==2){yrate = h18.showrooms();
                        h18.tellammount(yrate);}
        else if(o1 ==3){yrate = h19.showrooms();
                        h19.tellammount(yrate);}
        else {cout<<"Invalid Option";
                goto label3;
                }
        break;

    default:
        cout<<"No such Option Available"<<endl;
        goto label;
        break;}
    
    //SWITCH CASE ENDS

    //BOOKING

    cout<<"\n\n\t\tDo you want to carry on the booking? (Y/N)"<<endl;
    cout<<"\n\t\t>>> ";
    cin>>o2;
    if(o2 == 'Y'){
        Customer c[20];
        c[cnumber].getDetails();
        system("CLS");
        cout<<"\n\n\t\tBooking Succesfull!!\n\t\tThank you for using our program !!!"<<endl;
        cnumber++;
    }
    else if(o2 == 'N'){
        system("CLS");
        cout<<"\n\n\t\tThank You for using our Program";
    }

        cout<<"\n\t\t Enter 1 to go to main menu";
        cout<<"\n\t\t Enter 2 to exit the program";
        cout<<"\n\t\t>> ";
        cin>>o3;
        if(o3==1){goto label;}
        else if (o3==2){cout<<"\t\tProgram exited Succesfully";}
        else{cout<<"Invalid Input";}
    
    return 0;
}
