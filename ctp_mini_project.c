//HOTEL MANAGEMENT SYSTEM

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
// function to find days between two given dates
 
// A date has day 'd', month 'm' and year 'y'
typedef struct {
    int d, m, y;
}Date;
 
// storing number of days in every month
const int monthDays[12]
    = { 31, 28, 31, 30, 31, 30,
       31, 31, 30, 31, 30, 31 };
 
// This function counts number of leap years before the given date
int countLeapYears(Date d)
{
    int years = d.y;
 
    // if the current year needs to be considered for the count of leap years
    if (d.m <= 2)
        years--;
 
    // condition of a leap year
    return years / 4
           - years / 100
           + years / 400;
}
 
// returns number of days between two given dates
int getDifference(Date dt1, Date dt2)
{
    // COUNT TOTAL NUMBER OF DAYS
    // BEFORE FIRST DATE 'dt1'
 
    // initialize count using years and day
    long int n1 = dt1.y * 365 + dt1.d;
 
    // Add days for months in given date
    for (int i = 0; i < dt1.m - 1; i++)
        n1 += monthDays[i];
 
    // Since every leap year is of 366 days,
    // Add a day for every leap year
    n1 += countLeapYears(dt1);
 
    // SIMILARLY, COUNT TOTAL NUMBER OF
    // DAYS BEFORE 'dt2'
 
    long int n2 = dt2.y * 365 + dt2.d;
    for (int i = 0; i < dt2.m - 1; i++)
        n2 += monthDays[i];
    n2 += countLeapYears(dt2);
 
    // return difference between two counts
    return (n2 - n1);
}

typedef struct
{
    char name[50];
    char age[3];
    char gender;
    char aadhar_number[20];
    char mobile_number[20];
    char roomno[3];

} details;


// finds length of array
int length(char arr[])
{
    int l;
    for (int i = 1;; i++)
    {
        if (arr[i] == '\0')
        {
            l = i;
            break;
        }
    }
    return l;
}

void main()
{
    int exit = 1;
    while (exit)
    {   
        // deletes the bill file if the room is empty now 
        for (int z=1;z<41;z++)
        {   

            FILE *check;
            char roomdetails[30];
            char roombill[30];
            itoa(z,roombill,10);
            itoa(z,roomdetails,10);
            strcat(roombill,"bill.txt");
            // checks if customer details file exist
            if ((check = fopen(strcat(roomdetails,".txt"), "r")) == NULL)
            {   
                remove(roombill);
            } 
            

        }
        // array declared to store check in and check out date and time, used in calculating bill
        int checkindateandtime[4];
        int checkoutdateandtime[4];
        details customer;
        // restaurant items and price
        char starters[3][30] = {"Cheese cigar", "Spring rolls", "Honey chilli potato"};
        int startersprice[3] = {180, 150, 130};
        int startersfrequency[3] = {};
        char breakfast[3][30] = {"Milk and Corn flakes", "Bread Butter", "Omelet"};
        int breakfastprice[3] = {100, 70, 100};
        int breakfastfrequency[3] = {};
        char maincourse[4][30] = {"Masala dosa", "Shahi paneer", "Mix veg", "Rajma"};
        int maincourseprice[4] = {100, 150, 120, 150};
        int maincoursefrequency[4] = {};
        char tandoor[3][30] = {"Missi roti", "Butter naan", "Garlic naan"};
        int tandoorprice[3] = {20, 30, 40};
        int tandoorfrequency[3] = {};
        char dessert[3][30] = {"Butterscotch ice-cream", "Chocolava cake", "Falooda Kulfi"};
        int dessertprice[3] = {50, 70, 60};
        int dessertfrequency[3] = {};
        char beverages[5][30] = {"Tea", "Packaged Water", "Coffee", "Soft-drink", "Diet-coke"};
        int beveragesprice[5] = {30, 20, 35, 25, 30};
        int beveragesfrequency[5] = {};
        int roomrestaurantbill[40] = {};
        int flag = 0;
        char newpassword[11];
        char password[11], password_character;
        int i;
        // login authentication
        printf("\nEnter the password (maximum 10 characters) : ");
        i = 0;
        while (1)
        {   
            // inputs password char by char
            password_character = getch();
            // checks end of password, 13 ascii value is for carriage return 
            if (password_character == 13)
            {
                password[i] = '\0';
                break;
            }
            password[i++] = password_character;
            //prints * for password
            printf("*");
            // restricts input to maximum length i.e. 10 characters
            if (i == 10)
            {
                password[i] = '\0';
                break;
            }
        }
        FILE *pass;
        // opens file named password.txt for reading
        pass = fopen("password.txt", "r");
        char checkpass[11];
        // extracts string from file and stores in checkpass array
        fgets(checkpass, 11, pass);
        fclose(pass);
        // checks if the password in file is same as inputed by the user
        for (int i = 0; i < length(password); i++)
        {
            if (checkpass[i] != password[i])
            {
                flag = 1;
                printf("\nWrong Password, Try Again");
                break;
            }
        }
        // exits the program
        if (flag == 1)
            break;
    
    // facilities available in the program
    options:
        printf("\n\n\n1. Enter customer details");
        printf("\n2. View customer details");
        printf("\n3. View the available rooms");
        printf("\n4. Order from the restaurant");
        printf("\n5. Check out");
        printf("\n6. Change password");
        printf("\n7. Exit");
        printf("\n\nPlease enter the choice number : ");
        // inputs choice number and diverts the flow to the respective case
        int choicenumber;
        scanf("%d", &choicenumber);
        switch (choicenumber)
        {
        // Room Allotment
        case 1:
            printf("\nEnter the details...\n\n\n");
            FILE *roomdata;
            for (int i = 1; i < 41; i++)
            {   
                char roomnumber[30];
                // stores the value of integer as string in the given array
                itoa(i, roomnumber, 10);
                // appends .txt to the string 
                strcat(roomnumber, ".txt");

                // Allots the room if the room is empty 
                // for eg. if 1.txt exists, then room no.1 is occupied
                if ((roomdata = fopen(roomnumber, "r+")) == NULL)
                {
                    printf("\nAlloting Room number %d ", i);
                    // creates file for storing customer details 
                    roomdata = fopen(roomnumber, "w+");
                    // code for storing check-in date and time
                    time_t t;
                    time(&t);
                    // writes the time and room number in file
                    fprintf(roomdata,"Check-in Time: %s\n", ctime(&t));
                    fprintf(roomdata, "\nRoom Number %d\n", i);
                    // inputs details and stores it in the file
                    int number_of_guests;
                    printf("\nNo of Guests: ");
                    scanf("%d", &number_of_guests);
                    while (number_of_guests > 0)
                    {
                        printf("Name: ");
                        scanf(" %[^\n]", &customer.name);
                        printf("Age: ");
                        scanf(" %[^\n]", &customer.age);
                        printf("Gender: ");
                        scanf(" %[^\n]", &customer.gender);
                        printf("Aadhaar Number: ");
                        scanf(" %[^\n]", &customer.aadhar_number);
                        printf("Mobile Number: ");
                        scanf(" %[^\n]", &customer.mobile_number);

                        fprintf(roomdata, "\nName %s\n", customer.name);
                        fprintf(roomdata, "Age %s\n", customer.age);
                        fprintf(roomdata, "Gender %c\n", customer.gender);
                        fprintf(roomdata, "Aadhaar No. %s\n", customer.aadhar_number);
                        fprintf(roomdata, "Mobile No. %s\n", customer.mobile_number);

                        number_of_guests--;
                    }
                    fclose(roomdata);
                    break;
                }
            }
            //revert back to facilities
            goto options;
            break;

        // View details of room
        case 2:
        viewoptions:
            printf("\n1. View ");
            printf("\n2. Go back ");
            printf("\nEnter your choice: ");
            int choicenumber;
            scanf("%d", &choicenumber);
            switch (choicenumber)
            {
            
            case 1:
                printf("\nDetails of which room? ");
                char roomnumber[30];
                // stores the value of integer as string in the given array
                itoa(i, roomnumber, 10);
                scanf("%s", roomnumber);
                char buffer[1000];
                // opens file for reading
                FILE *roomdata;
                roomdata = fopen(strcat(roomnumber, ".txt"), "r+");
                // fetches data from the file 
                fread(buffer, sizeof(buffer), 1, roomdata);
                printf("%s", buffer);
                fclose(roomdata);
                // if file doesn't exist, then room is empty
                if ((roomdata = fopen(roomnumber, "r+")) == NULL)
                    printf("\nThis room is empty ");
                fclose(roomdata);
                goto options;
                break;

            case 2:
                goto options;
                break;

            //if input other than 1 or 2, revert back to previous options
            default:
                printf("\n\nInvalid input!");
                goto viewoptions;
                break;
            }

            goto options;
            break;
        
        // View rooms available
        case 3:
            printf("\nRooms Available: ");
            for (int i = 1; i < 41; i++)
            {
                FILE *roomdata;
                char roomnumber[30];
                // stores the value of integer as string in the given array
                itoa(i, roomnumber, 10);
                // appends .txt to the string 
                strcat(roomnumber, ".txt");

                // if file doesn't exist, then room is empty
                if ((roomdata = fopen(roomnumber, "r+")) == NULL)
                    printf("%d ", i);
                fclose(roomdata);
            }
            goto options;
            break;

        // generates bill
        case 4:
            printf("\nPlease enter the room number: ");
            int m;
            scanf("%d",&m);
            char roomnumber[30];
            // stores the value of integer as string in the given array
            // stores roomnumber as string in roomnumber array
            itoa(m, roomnumber, 10);
            char roomnumberforbill[30];
            // copied roomnumber string to roomnumberforbill for further usage
            for (int l=0;l<30;l++)
            roomnumberforbill[l]=roomnumber[l];
            // appends .txt to the room number string 
            strcat(roomnumber, ".txt");
            // checks if room is empty or occupied
            if ((roomdata = fopen(roomnumber, "r+")) == NULL)
            {   
                // if empty
                printf("\nThis room is empty ");
                fclose(roomdata);
                // revert back to facilites
                goto options;
            }
            else
            {   
                // checks if ordering for the first time
                // eg. for room number 1, it checks if 1bill.txt exist or not
                strcat(roomnumberforbill, "bill.txt");
                FILE *file_;
                if ((file_ = fopen(roomnumberforbill, "r+")) == NULL)
                {   
                    // if file doesn't, it creates a new file 
                    file_ = fopen(roomnumberforbill, "a+");
                    fprintf(file_,"Restaurant Bill: ");
                    fclose(file_);
                }
            }
            // restaurant options
            menuoptions:
                printf("\n\n\n1. Starters");
                printf("\n2. Break-fast");
                printf("\n3. Maincourse");
                printf("\n4. Tandoor");
                printf("\n5. Dessert");
                printf("\n6. Beverages");
                printf("\n7. Exit");
                printf("\n\nPlease enter the choice number: ");
                // inputs choice number
                int menuchoicenumber;
                scanf("%d", &menuchoicenumber);
                switch (menuchoicenumber)
                {   
                    // starters
                    case 1:
                        startersoptions:
                            printf("\n");
                            // printing starters options 
                            // loop runs till k less than starters array length
                            for (int k = 0; k < (sizeof(starters) / sizeof(starters[0])); k++)
                            printf("\n%d. %s %d", k + 1, starters + k, startersprice[k]);
                            printf("\n\n To go back, Enter any number except the options");
                            int starterschoicenumber;
                            int quantity;
                            printf("\n\nPlease enter the choice number: ");
                            scanf("%d", &starterschoicenumber);
                            // if choice any other than choice number then reverts back to restaurant menu
                            if (starterschoicenumber<1 || starterschoicenumber>(sizeof(starters) / sizeof(starters[0])))
                            {
                                goto menuoptions;
                                break;
                            }
                            printf("\nEnter the quantity: ");
                            scanf("%d", &quantity);
                            // changes frequency of item ordered
                            startersfrequency[starterschoicenumber-1]+=quantity;
                            // updates restaurant bill
                            roomrestaurantbill[m-1]+=(startersprice[starterschoicenumber-1]*quantity);
                            goto menuoptions;
                            break;
                    // breakfast
                    case 2:
                        breakfastoptions:
                            printf("\n");
                            // printing breakfast options 
                            // loop runs till k less than breakfast array length
                            for (int k = 0; k < (sizeof(breakfast) / sizeof(breakfast[0])); k++)
                            printf("\n%d. %s %d", k + 1, breakfast + k, breakfastprice[k]);
                            printf("\n To go back, Enter any number except the options");
                            int breakfastchoicenumber;
                            printf("\n\nPlease enter the choice number: ");
                            scanf("%d", &breakfastchoicenumber);
                            // if choice any other than choice number then reverts back to restaurant menu
                            if (breakfastchoicenumber < 1 || breakfastchoicenumber > (sizeof(breakfast) / sizeof(breakfast[0])))
                            {
                                goto menuoptions;
                                break;
                            }
                            printf("\nEnter the quantity: ");
                            scanf("%d", &quantity);
                            // changes frequency of item ordered
                            breakfastfrequency[breakfastchoicenumber - 1] += quantity;
                            // updates restaurant bill
                            roomrestaurantbill[m - 1] += (breakfastprice[breakfastchoicenumber - 1] * quantity);
                            goto menuoptions;
                            break;
                    // maincourse
                    case 3:
                        maincourseoptions:
                            printf("\n");
                            // printing maincourse options 
                            // loop runs till k less than maincourse array length
                            for (int k = 0; k < (sizeof(maincourse) / sizeof(maincourse[0])); k++)
                            printf("\n%d. %s %d", k + 1, maincourse + k, maincourseprice[k]);
                            printf("\n To go back, Enter any number except the options");
                            int maincoursechoicenumber;
                            printf("\n\nPlease enter the choice number: ");
                            scanf("%d", &maincoursechoicenumber);
                            // if choice any other than choice number then reverts back to restaurant menu
                            if (maincoursechoicenumber < 1 || maincoursechoicenumber > (sizeof(maincourse) / sizeof(maincourse[0])))
                            {
                                goto menuoptions;
                                break;
                            }
                            printf("\nEnter the quantity: ");
                            scanf("%d", &quantity);
                            // changes frequency of item ordered
                            maincoursefrequency[maincoursechoicenumber - 1] += quantity;
                            // updates restaurant bill
                            roomrestaurantbill[m - 1] += (maincourseprice[maincoursechoicenumber - 1] * quantity);
                            goto menuoptions;
                            break;
                    // tandoor
                    case 4:
                        tandooroptions:
                            printf("\n");
                            // printing tandoor options 
                            // loop runs till k less than tandoor array length
                            for (int k = 0; k < (sizeof(tandoor) / sizeof(tandoor[0])); k++)
                            printf("\n%d. %s %d", k + 1, tandoor + k, tandoorprice[k]);
                            printf("\n To go back, Enter any number except the options");
                            int tandoorchoicenumber;
                            printf("\n\nPlease enter the choice number: ");
                            scanf("%d", &tandoorchoicenumber);
                            // if choice any other than choice number then reverts back to restaurant menu
                            if (tandoorchoicenumber < 1 || tandoorchoicenumber > (sizeof(tandoor) / sizeof(tandoor[0])))
                            {
                                goto menuoptions;
                                break;
                            }
                            printf("\nEnter the quantity: ");
                            scanf("%d", &quantity);
                            // changes frequency of item ordered
                            tandoorfrequency[tandoorchoicenumber - 1] += quantity;
                            // updates restaurant bill
                            roomrestaurantbill[m - 1] += (tandoorprice[tandoorchoicenumber - 1] * quantity);
                            goto menuoptions;
                            break;
                    // dessert
                    case 5:
                        dessertoptions:
                            printf("\n");
                            // printing dessert options 
                            // loop runs till k less than dessert array length
                            for (int k = 0; k < (sizeof(dessert) / sizeof(dessert[0])); k++)
                            printf("\n%d. %s %d", k + 1, dessert + k, dessertprice[k]);
                            printf("\n To go back, Enter any number except the options");
                            int dessertchoicenumber;
                            printf("\n\nPlease enter the choice number: ");
                            scanf("%d", &dessertchoicenumber);
                            // if choice any other than choice number then reverts back to restaurant menu
                            if (dessertchoicenumber < 1 || dessertchoicenumber > (sizeof(dessert) / sizeof(dessert[0])))
                            {
                                goto menuoptions;
                                break;
                            }
                            printf("\nEnter the quantity: ");
                            scanf("%d", &quantity);
                            // changes frequency of item ordered
                            dessertfrequency[dessertchoicenumber - 1] += quantity;
                            // updates restaurant bill
                            roomrestaurantbill[m - 1] += (dessertprice[dessertchoicenumber - 1] * quantity);
                            goto menuoptions;
                            break;
                    // beverages
                    case 6:
                        beveragesoptions:
                            printf("\n");
                            // printing beverages options 
                            // loop runs till k less than beverages array length
                            for (int k = 0; k < (sizeof(beverages) / sizeof(beverages[0])); k++)
                            printf("\n%d. %s %d", k + 1, beverages + k, beveragesprice[k]);
                            printf("\n To go back, Enter any number except the options");
                            int beverageschoicenumber;
                            printf("\n\nPlease enter the choice number: ");
                            scanf("%d", &beverageschoicenumber);
                            // if choice any other than choice number then reverts back to restaurant menu
                            if (beverageschoicenumber < 1 || beverageschoicenumber > (sizeof(beverages) / sizeof(beverages[0])))
                            {
                                goto menuoptions;
                                break;
                            }
                            printf("\nEnter the quantity: ");
                            scanf("%d", &quantity);
                            // changes frequency of item ordered
                            beveragesfrequency[beverageschoicenumber - 1] += quantity;
                            // updates restaurant bill
                            roomrestaurantbill[m - 1] += (beveragesprice[beverageschoicenumber - 1] * quantity);
                            goto menuoptions;
                            break;
                    // adding restaurant bill to main bill
                    case 7:
                        // if noting ordered, revert back to options
                        if (roomrestaurantbill[m-1]==0)
                        {   
                            goto options;
                            break;
                        }
                        printf("\nRoom Bill Updated.");
                        FILE *file_;
                        // opens file for appending details about the order to bill file
                        file_ = fopen(roomnumberforbill, "a+");
                        // order time
                        time_t t;
                        time(&t);
                        fprintf(file_,"\nTime: %s\n", ctime(&t));
                        for (int k = 0; k < (sizeof(starters) / sizeof(starters[0])); k++)
                        {
                            if (startersfrequency[k]!=0)
                            {
                                fprintf(file_,"\nItem:%s     Quantity:%d      Amount:%d",starters[k],startersfrequency[k],startersfrequency[k]*startersprice[k]);
                            }
                            // after appending, frequency set to 0
                            startersfrequency[k]=0;
                        }
                        for (int k = 0; k < (sizeof(breakfast) / sizeof(breakfast[0])); k++)
                        {
                            if (breakfastfrequency[k]!=0)
                            {
                                fprintf(file_,"\nItem:%s     Quantity:%d      Amount:%d",breakfast[k],breakfastfrequency[k],breakfastfrequency[k]*breakfastprice[k]);
                            }
                            breakfastfrequency[k]=0;
                        }
                        for (int k = 0; k < (sizeof(maincourse) / sizeof(maincourse[0])); k++)
                        {
                            if (maincoursefrequency[k]!=0)
                            {
                                fprintf(file_,"\nItem:%s     Quantity:%d      Amount:%d",maincourse[k],maincoursefrequency[k],maincoursefrequency[k]*maincourseprice[k]);
                            }
                            maincoursefrequency[k]=0;
                        }
                        for (int k = 0; k < (sizeof(tandoor) / sizeof(tandoor[0])); k++)
                        {
                            if (tandoorfrequency[k]!=0)
                            {
                                fprintf(file_,"\nItem:%s     Quantity:%d      Amount:%d",tandoor[k],tandoorfrequency[k],tandoorfrequency[k]*tandoorprice[k]);
                            }
                            tandoorfrequency[k]=0;
                        }
                        for (int k = 0; k < (sizeof(dessert) / sizeof(dessert[0])); k++)
                        {
                            if (dessertfrequency[k]!=0)
                            {
                                fprintf(file_,"\nItem:%s     Quantity:%d      Amount:%d",dessert[k],dessertfrequency[k],dessertfrequency[k]*dessertprice[k]);
                            }
                            dessertfrequency[k]=0;
                        }
                        for (int k = 0; k < (sizeof(beverages) / sizeof(beverages[0])); k++)
                        {
                            if (beveragesfrequency[k]!=0)
                            {
                                fprintf(file_,"\nItem:%s     Quantity:%d      Amount:%d",beverages[k],beveragesfrequency[k],beveragesfrequency[k]*beveragesprice[k]);
                            }
                            beveragesfrequency[k]=0;
                        }
                        FILE *temp;
                        char tempbill[30];
                        char billamountinstring[30];
                        itoa(m, tempbill, 10);
                        strcat(tempbill,"tempbill.txt");

                        if ((temp = fopen(tempbill, "r+")) != NULL)
                        {   
                            // updates restaurant bill
                            int billamountininteger;
                            fgets(billamountinstring,30,temp);
                            billamountininteger=atoi(billamountinstring);
                            roomrestaurantbill[m-1]+=billamountininteger;
                            fclose(temp);

                        }
                        // stores restaurant bill in file
                        temp = fopen(tempbill, "w+");
                        fprintf(temp,"%d",roomrestaurantbill[m-1]);
                        roomrestaurantbill[m-1]=0;

                        fclose(temp);
                        fclose(file_);
                        goto options;
                        break;

                    default:
                        printf("\n\nInvalid input!");
                        goto menuoptions;
                        break;
                }
        
        case 5:
            printf("\nPlease enter the room number: ");
            int n;
            scanf("%d",&n);
            // stores the value of integer as string in the given array
            itoa(n, roomnumber, 10);
            // appends .txt to the room number string
            strcat(roomnumber,".txt");
            // checks if room empty
            if ((roomdata = fopen(roomnumber, "r+")) == NULL)
            {
                printf("\nThis room is empty: ");
            }
            else
            {   
                // if room is occupied
                char checkindateandtimestring[40];
                // fetches first line as string from file and stores in checkindateandtimestring string
                fgets (checkindateandtimestring,40,roomdata);
                // passing string word by word
                // note that 4th word stores data about month, 5th word about day, 7th word about year
                // note than 7th word stores data about time as hh:mm:ss
                char *token = strtok(checkindateandtimestring, " ");
                for (int p=0;p<7;p++)
                {   
                    if (p==4) checkindateandtime[0]=atoi(token);
                    if (p==6) checkindateandtime[2]=atoi(token);
                    if (p==3)
                    {
                        if (token=="Jan") checkindateandtime[1]=1;
                        else if(token="Feb") checkindateandtime[1]=2;
                        else if(token="Mar") checkindateandtime[1]=3;
                        else if(token="Apr") checkindateandtime[1]=4;
                        else if(token="May") checkindateandtime[1]=5;
                        else if(token="Jun") checkindateandtime[1]=6;
                        else if(token="Jul") checkindateandtime[1]=7;
                        else if(token="Aug") checkindateandtime[1]=8;
                        else if(token="Sep") checkindateandtime[1]=9;
                        else if(token="Oct") checkindateandtime[1]=10;
                        else if(token="Nov") checkindateandtime[1]=11;
                        else checkindateandtime[1]=12;
                    }
                    if (p==5)
                    {   
                        // storing only hh part of time 
                        checkindateandtime[3]=atoi(token);
                    }
                    token = strtok(NULL, " ");
                }
                // fetching check-out time
                time_t t;
                time(&t);  
                // temporarily storing check-out time in a file
                FILE *checkout;
                checkout=fopen("checkout.txt","w+");
                fprintf(checkout,"Check-out Time: %s\n", ctime(&t));
                fclose(checkout);
                char checkoutdateandtimestring[41];
                // opening check-out time file and fetching the same details as in check-in 
                checkout=fopen("checkout.txt","r+");
                fgets(checkoutdateandtimestring,41,checkout);
                fclose(checkout);
                char *token1 = strtok(checkoutdateandtimestring, " ");
                for (int p=0;p<7;p++)
                {
                    if (p==4) checkoutdateandtime[0]=atoi(token1);
                    if (p==6) checkoutdateandtime[2]=atoi(token1);
                    if (p==3)
                    {
                        if (token1=="Jan") checkoutdateandtime[1]=1;
                        else if(token1="Feb") checkoutdateandtime[1]=2;
                        else if(token1="Mar") checkoutdateandtime[1]=3;
                        else if(token1="Apr") checkoutdateandtime[1]=4;
                        else if(token1="May") checkoutdateandtime[1]=5;
                        else if(token1="Jun") checkoutdateandtime[1]=6;
                        else if(token1="Jul") checkoutdateandtime[1]=7;
                        else if(token1="Aug") checkoutdateandtime[1]=8;
                        else if(token1="Sep") checkoutdateandtime[1]=9;
                        else if(token1="Oct") checkoutdateandtime[1]=10;
                        else if(token1="Nov") checkoutdateandtime[1]=11;
                        else checkoutdateandtime[1]=12;
                    }
                    if (p==5)
                    {   
                        checkoutdateandtime[3]=atoi(token1);
                    }
                    token1 = strtok(NULL, " ");
                }
                Date dt1 = { checkindateandtime[0], checkindateandtime[1], checkindateandtime[2] };
                Date dt2 = { checkoutdateandtime[0], checkoutdateandtime[1], checkoutdateandtime[2] };
                // finding number of days between the check-in and check-out date
                int daysstayed=getDifference(dt1, dt2);
                // condition for a day counts in hotel from 12 pm to next day 12 pm
                if (!(checkindateandtime[3]>12 && checkoutdateandtime[3]<12)) daysstayed+=1;
                // extracting amount uptill now from the file and, updating and appending in the main bill file
                FILE *temp1;
                FILE *temp2;
                char billfile[30];
                char tempbillfile[30];
                itoa(n,billfile,10);
                itoa(n,tempbillfile,10);
                strcat(tempbillfile,"tempbill.txt");
                strcat(billfile,"bill.txt");
                temp1=fopen(billfile,"a+");
                temp2=fopen(tempbillfile,"r");
                char bill[10];
                char tempbill[10];
                fgets (tempbill,10,temp2);
                fclose(temp2);
                // format to append data in main bill file
                if ((temp2=fopen(tempbillfile,"r"))!=NULL)
                {
                    fprintf(temp1,"\nSUBTOTAL: %d\n",atoi(tempbill));
                    fprintf(temp1,"\nCGST: %.2f",0.09*atoi(tempbill));
                    fprintf(temp1,"\nSGST: %.2f",0.09*atoi(tempbill));
                }
                fclose(temp2);
                // deleting file temporarily storing bill amount
                remove(tempbillfile);
                fprintf(temp1,"\n\nROOM BILL: ");
                fprintf(temp1,"\n\nDays stayed: %d",daysstayed);
                fprintf(temp1,"\nROOM CHARGE: %d",daysstayed*1000);
                fprintf(temp1,"\n\nGRAND TOTAL: %.2f",daysstayed*1000+0.09*atoi(tempbill)+atoi(tempbill)+0.09*atoi(tempbill));
                fclose(temp1);
                // deleting checkout.txt file
                remove("checkout.txt");
                printf("\nBill Updated.");
            }     
            fclose(roomdata);
            // deleting file containing details about customer
            // remove(roomnumber); 
            printf("\nYou can now delete the details file after you have saved it in your records.");
            goto options;
            break;
        // Change password
        case 6:
            while (1)
            {   
                // enter password
                printf("\nEnter the new password: ");
                i = 0;
                while (1)
                {   
                    // gets input character by character
                    password_character = getch();
                    // end the string by inserting null character if input is Enter key
                    if (password_character == 13)
                    {
                        newpassword[i] = '\0';
                        break;
                    }
                    newpassword[i++] = password_character;
                    printf("*");
                    // restricts input to length of 10 characters
                    if (i == 10)
                    {
                        newpassword[i] = '\0';
                        break;
                    }
                }
                // re-enter password 
                char repassword[11], repassword_character;
                int j;
                printf("\nRe-Enter the password : ");
                j = 0;
                while (1)
                {   
                    // gets input character by character
                    repassword_character = getch();
                    // end the string by inserting null character if input is Enter key
                    if (repassword_character == 13)
                    {
                        repassword[j] = '\0';
                        break;
                    }
                    repassword[j++] = repassword_character;
                    printf("*");
                    // restricts input to length of 10 characters
                    if (j == 10)
                    {
                        repassword[j] = '\0';
                        break;
                    }
                }
                // checks if both passwords equal
                flag = 0;
                for (int i = 0; i < length(newpassword); i++)
                {
                    if (newpassword[i] != repassword[i])
                    {
                        flag = 1;
                        break;
                    }
                }
                // if passwords match 
                if (flag == 0)
                {
                    break;
                }
                // if passwords doesn't match
                else
                {
                    printf("\nPassword didn't match, Try Again!\n\n\n");
                passoptions:
                    printf("\n1. Try again? ");
                    printf("\n2. Go to previous options");
                    printf("\nEnter your choice number please ");
                    scanf("%d", &choicenumber);
                    switch (choicenumber)
                    {
                    case 1:
                        break;
                    case 2:
                        goto options;
                        break;
                    default:
                        printf("\n\nInvalid input!");
                        goto passoptions;
                        break;
                    }
                }
            }
            // open password.txt for writing
            pass = fopen("password.txt", "w");
            // overwrites previous password with new password
            fputs(newpassword, pass);
            fclose(pass);
            goto options;
            break;
        // exits program
        case 7:
            exit = 0;
            break;

        // revert back to facilities
        default:
            printf("\n\nInvalid input!");
            goto options;
            break;
        }
    }
}
