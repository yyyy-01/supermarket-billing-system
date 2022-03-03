#include <iostream>
#include <stack>
#include <vector>
#include <iomanip>
#include <queue>
#include <climits>//INT_MAX
#include <string> //stoi, stof
#include <stdlib.h> // for pause
#include "item.hpp"
#include <stdio.h>
#include <fstream>

using namespace std;
using itemHpp::Item;

vector<Item> item_record;
Item t;
//global variable//
int counter, p_name_counter;
int product_num, quantity, mDay, mMonth, mYear, eDay, eMonth, eYear, Pnum_counter;
float cost, price, margin;
string product_name, choice, edit_choice, confirmation;
int nowDay, nowMonth, nowYear, index;
string strQuantity;

int newProduct_num, newQuantity, newMDay, newMMonth, newMYear, newEDay, newEMonth, newEYear;
string newProduct_name;
float newPrice, newCost, newMargin;

void Writefile()
{
    ofstream writefile;

    writefile.open("Product_record_2.csv");
    writefile<<"Product Num, Product Name, Quantity, Manufacture date, Expiring Date, Cost, Margin, Price" <<endl;
    for (unsigned i=0; i<item_record.size();i++)
    {
    writefile<<item_record[i].getProduct_num()<<","
            <<item_record[i].getProduct_name()<<","
            <<item_record[i].getQuantity()<<","
            <<item_record[i].getMDay()<<"/"<<item_record[i].getMMonth()<<"/"<<item_record[i].getMYear()<<","
            <<item_record[i].getEDay()<<"/"<<item_record[i].getEMonth()<<"/"<<item_record[i].getEYear()<<","
            <<item_record[i].getCost()<<","
            <<item_record[i].getMargin()<<","
            <<item_record[i].getPrice()<<endl;
    }//end for loop
    writefile.close();

}

void Readfile()
{
    //Pnum_counter = 0;
    ifstream readfile;
    readfile.open("Product_record_2.csv");

    if (readfile.is_open()){
        readfile.ignore(INT_MAX,'\n');

    string s,d,m,y,name,c,p;
    while(readfile.peek()!=EOF)
    {
            getline(readfile, s, ',');
            t.upProduct_num(stoi(s));

            getline(readfile,name,',');
            t.upProduct_name(name);

            getline(readfile, s, ',');
            t.upQuantity(stoi(s));

            getline(readfile, d, '/');
            getline(readfile, m, '/');
            getline(readfile, y, ',');
            t.upMDay(stoi(d));
            t.upMMonth(stoi(m));
            t.upMYear(stoi(y));


            getline(readfile, d, '/');
            getline(readfile, m, '/');
            getline(readfile, y, ',');
            t.upEDay(stoi(d));
            t.upEMonth(stoi(m));
            t.upEYear(stoi(y));

            getline(readfile, c, ',');
            t.upCost(stof(c));

            getline(readfile, m, ',');
            t.upMargin(stof(m));

            getline(readfile, p, '\n');
            t.setPrice(stof(p));

            item_record.push_back(t);
            }//end while loop

        readfile.close();
        //cout<<"file successfully closed"<<endl;
    }
}

int main()
{
    int counter = 1;
    system("color F2");
    char main_choice;
    Readfile();
    main_menu:
    Writefile();
    system("cls");
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
    cout<<"-------------------------------------------------------------------------------------------------------------------------------------------------------------";
    cout<<"                                                              |WELCOME TO SUPERMARKET BILLING SYSTEM|                                                                                    "<<endl;
    cout<<"-------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"                                                                              1.Add                                                                              "<<endl;
    cout<<"                                                                              2.Delete                                                                              "<<endl;
    cout<<"                                                                              3.Sort                                                                              "<<endl;
    cout<<"                                                                              4.Display                                                                              "<<endl;
    cout<<"                                                                              5.Search                                                                              "<<endl;
    cout<<"                                                                              6.Edit                                                                              "<<endl;
    cout<<"                                                                              7.Expired item                                                                        "<<endl;
    cout<<"                                                                              8.Exit                                                                              "<<endl;
    endl(cout);
    cout<<"                                                         Please select option: "                                                                              ;
    cin>>main_choice;
    switch (main_choice)
{
case '1':
    product_num = t.getProduct_num() + counter;
    t.upProduct_num(product_num);

name:
    endl(cout);
    cout<<"                                                  Product number"<<setw(40)<<" :"<<t.getProduct_num()<<endl;
    try
    {
    cin.ignore();
    cout<<"                                                  Enter the name of product (*eg Apple pie 1)"<<setw(11)<<":";
    getline(cin,product_name);
    int p_name_counter = 0;
        for(unsigned int i = 0; i < product_name.length(); i++)
            {
                product_name[i] = toupper(product_name[i]);
            }
        if(t.check_exist_product_name(item_record, product_name))
            {
                cout<<"                                                         This product has been added before"<<endl;
                cout<<"                                             -----------------------------------------------------------                     "<<endl;
                system("pause");
                goto name;
            }
        else
            t.upProduct_name(product_name);
        if(!t.check_product_name(item_record, product_name))
        throw (100);
    }
    catch (int digit)
    {
        cin.ignore(INT_MAX, '\n');
        cout<<"                                                         Product name must include at least one alphabet"<<endl;
        cout<<"                                             ----------------------------------------------------------------                     "<<endl;
        system("pause");
        ///goto name;
        goto name;
        }


Margin:
  try{
       cout<<"                                                  Enter the margin of product (*eg 10)"<<setw(18)<<":";
    cin>>margin;

       if (cin.fail())
       {
         cin.clear();
       cin.ignore(INT_MAX, '\n');
        throw (margin);
       }
       else
        t.upMargin(margin);

    }

    catch (int margin)
    {
        cout<<"                                                         Only numbers are allowed"<<endl;
        cout<<"                                         -------------------------------------------------------"<<endl;
        system("pause");
        goto Margin;

    }

Quantity:

       cout<<"                                                  Enter the quantity of product (*eg 60)"<<setw(16)<<":";
        cin>>strQuantity;
       try
        {
        for(int i = 0; i<strQuantity.size();i++)
        {
            if(!isdigit(strQuantity[i]))
            {
                throw(strQuantity);
            }
        }
        quantity = stoi(strQuantity);
            t.upQuantity(quantity);
    }

    catch (string strQuantity)
    {
        cout<<"                                                         Only numbers are allowed"<<endl;
        cout<<"                                             -----------------------------------------------------------                     "<<endl;
        system("pause");
        goto Quantity;
    }

    cost:
    cout<<"                                                  Enter the cost of single unit of "<<product_name <<" (*eg 1.3)"<<setw(11-product_name.size())<<":";
    cin>>cost;
   try
   {
       if (cin.fail())
       {
         cin.clear();
       cin.ignore(INT_MAX, '\n');
        throw (cost);
       }

    else
        t.upCost(cost);
    }
    catch (float cost)
    {
        cout<<"                                                         Only numbers are allowed"<<endl;
        cout<<"                                             -----------------------------------------------------------                     "<<endl;
        system("cls");
        goto cost;
    }

        t.upPrice(cost,margin);
        cout<<"                                                 ---------------------------------------------------------------"<<endl;
        cout<<"                                                                                          Selling Price :RM"<<fixed<<setprecision(2)<<t.getPrice()<<endl;
        endl(cout);
    price:
        cout<<"                                                         Do you wish to change the selling price?."<<endl;
        cout<<"                                                         Enter (Y) to CHANGE/ (N) to PROCEED."<<endl;
        cout<<"                                                         --> ";
        //cin.ignore();
        cin>>confirmation;
        if(confirmation=="y"||confirmation=="Y")
        {
            cout<<"                                                  Enter the Selling Price (*eg 6.5)"<<setw(16)<<":RM";
            cin>>price;
            t.setPrice(price);
            t.upNewMargin(price,cost);///add to ADT
            cout<<"                                                  New Margin of "<<product_name <<" will be"<<setw(11-product_name.size())<<":"<<fixed<<setprecision(2)<<t.getMargin();
            endl(cout);

        }
        else if(confirmation=="n"||confirmation=="N")
        {
            goto Date;
        }
        else
        {
           cout<<"                                                         ***Enter Y or N only!***"<<endl;
            cout<<"                                             -----------------------------------------------------------                     "<<endl;
           system("pause");
           goto price;
        }

    Date:
        try
        {
        cout<<"                                                 ---------------------------------------------------------------                                                         "<<endl;
       t.current_time();
       cout<<"                                                  Enter the manufactured date of the product (*Date BEFORE today--"<<t.get_current_day()<<"/"<<t.get_current_month()<<"/"<<t.get_current_year()<<") :"<<endl;
       cout<<"                                                  Day (DD): ";
       cin>>mDay;
       if (cin.fail())
       {
        cin.clear();
       cin.ignore(INT_MAX, '\n');
        throw (1);
       }

       cout<<"                                                  Month (MM): ";
       cin>>mMonth;
       if (cin.fail())
       {
        cin.clear();
       cin.ignore(INT_MAX, '\n');
        throw (1);
       }

       cout<<"                                                  Year (YYYY): ";
       cin>>mYear;
       if (cin.fail())
       {
        cin.clear();
       cin.ignore(INT_MAX, '\n');
        throw (1);
       }

       if (!t.check_manufacture_date(mDay,mMonth,mYear))
       {
           if(mMonth==2&&mYear<=t.get_current_year())
           {
                cout<<"                                                         Invalid date"<<endl;
                cout<<"                                                         There is no "<<mDay<<" in February!"<<endl;
                if(mYear>t.get_current_year())
                {
                    cout<<"                                                         Invalid date"<<endl;
                }
           }
        else if(mMonth!=2)
        {
            cout<<"                                                         Invalid date"<<endl;
            cout<<"                                                 Please enter date before today, Date of the day :";
            cout<<t.get_current_day()<<" /"<<t.get_current_month()<<" /"<<t.get_current_year();
            cout<<" and date after year 2010"<<endl;
        }

       goto Date;
       }

       else
       {
           t.upMDay(mDay);
           t.upMMonth(mMonth);
           t.upMYear(mYear);
       }

       }//end try
       catch(int digit)
       {
           cout<<"                                                         Only digits are allow"<<endl;
           cout<<"                                             -----------------------------------------------------------                     "<<endl;

           system("pause");
           goto Date;
       }


    eDate:
       cout<<"                                                  Enter the expired date of the product (*Date AFTER today--"<<t.get_current_day()<<"/"<<t.get_current_month()<<"/"<<t.get_current_year()<<") :"<<endl;
       cout<<"                                                  Day (DD): ";
       cin>>eDay;
       cout<<"                                                  Month (MM): ";
       cin>>eMonth;
       cout<<"                                                  Year (YYYY): ";
       cin>>eYear;
       if(!t.check_expired_date(eDay,eMonth,eYear))
       {
           cout<<"                                                         Invalid date"<<endl;
           cout<<"                                                 Please enter date after today, Date of the day :";
           cout<<t.get_current_day()<<" /"<<t.get_current_month()<<" /"<<t.get_current_year()<<endl;
           cout<<"                                                         --------------------------------------------------------                                                         "<<endl;

           goto eDate;
       }
              else
       {
           t.upEDay(eDay);
           t.upEMonth(eMonth);
           t.upEYear(eYear);
       }

    confirmation_menu:
       cout<<"                                                         Confirm to add this item into system? (Y/N): ";
       cin>>confirmation;
       if(confirmation == "Y" || confirmation == "y")
       {
           t.fillproduct(item_record);
           cout<<"                                                            --------------------------"<<endl;
           cout<<"                                                           |........Item added........|"<<endl;
           cout<<"                                                            --------------------------"<<endl;
           cout<<"                                                                 Back to main menu"<<endl;
           cin.ignore();
           system("pause");
           system("cls");
           goto main_menu;
       }
       else if(confirmation == "N" || confirmation == "n")
       {
           cout<<"                                                         No item added to the system, back to main menu"<<endl;
           Pnum_counter--;
           cin.ignore();
           t.up_Pnum_counter(Pnum_counter);
           system("pause");
           system("cls");
           goto main_menu;
       }
       else
       {
           cout<<"                                                         ***Enter Y or N only!***"<<endl;
            cout<<"                                             -----------------------------------------------------------                     "<<endl;
           system("pause");
           goto confirmation_menu;
       }

    break;

case '2':
    char del_confirmation;
    t.display_all(item_record);
    cout<<"                                                         Enter the product number: ";
    cin.ignore();
    cin>>product_num;
    if(cin.fail())
    {
        cin.clear();
       cin.ignore(INT_MAX, '\n');
        cout<<"                                                         Wrong input, only numbers are allowed"<<endl;
        system("pause");
        goto main_menu;
    }
    cout<<"                                                         Are you sure to delete "<<product_num<<" ? (Y/N)";
    cin>>del_confirmation;
    if (del_confirmation == 'y' ||del_confirmation == 'Y')
    {
        t.delete_product(item_record,product_num);
    }
    else
    {
        cout<<"                                                         Wrong input"<<endl;
        cout<<"                                                         ***Enter Y or N only!***"<<endl;
            cout<<"                                             -----------------------------------------------------------                     "<<endl;
    }
    system("pause");
    system("cls");
    goto main_menu;
    break;

case '3':
    int sort_selection;
    cout<<"                                                         1. Sort by Price "<<endl;
    cout<<"                                                         2. Sort by Name "<<endl;
    cout<<"                                                         Please Select Option: ";
    cin>>sort_selection;
    try
    {
        if(sort_selection == 1)
        {
            vector<Item> anotherVec;//when display sorted vector, display anotherVec
            //all the sorted action are performed on anotherVec
               for(int i=0; i<item_record.size(); i++)
                {//copy ori vector to another vector
                    anotherVec.push_back(item_record[i]);
                }
            t.quicksort(anotherVec,0,item_record.size()-1);
            t.display_all(anotherVec);
            system("pause");
            system("cls");
            goto main_menu;
        }
        else if(sort_selection == 2)
        {
            vector<Item> anotherVec;//when display sorted vector, display anotherVec
            //all the sorted action are performed on anotherVec
               for(int i=0; i<item_record.size(); i++)
                {//copy ori vector to another vector
                    anotherVec.push_back(item_record[i]);
                }
            t.sortbyName(anotherVec,item_record.size());
            t.display_all(anotherVec);
            system("pause");
            system("cls");
            goto main_menu;
        }
        else if(cin.fail()||sort_selection != 1||sort_selection!=2)
        {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            throw(sort_selection);
        }

    }
    catch(int sort_selection)
    {
        cout<<"                                                         Wrong input"<<endl;
        system("pause");
        system("cls");
        goto main_menu;
    }


    break;

case '4':
    t.displayNum(item_record);
    cout << endl;
    t.display_all(item_record);
    cout << endl;
    system("pause");
    system("cls");
    goto main_menu;
    break;

case '5':
    char ch;
    search_menu:
    char search_choice;
    cout<<"                                                         1. Search by product number "<<endl;
    cout<<"                                                         2. Search by name"<<endl;
    cout<<"                                                         3. Search by starting alphabet"<<endl <<endl;
    cout<<"                                                         Please select option:"                                                                              ;
    cin>>search_choice;
    switch (search_choice)
    {
    case '1':
        cout<<"                                                         Enter product number : ";
        cin>>product_num;
        t.searchbyPnum(item_record, product_num);
        system("pause");
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        goto main_menu;
        break;
    case '2':
        cout<<"                                                         Enter product name : ";
        cin>>product_name;
        t.searchbyName(item_record, product_name);
        system("pause");
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        goto main_menu;
        break;
    case '3':
        cout<<"                                                         Enter product name : ";
        cin>>ch;
        t.searchbyAlpha(item_record, ch);
        system("pause");
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        goto main_menu;
        break;
    default:
        cout<<"                                                         Wrong input"<<endl;
        system("pause");
        goto search_menu;
        break;
    }
    break;

case '6' :
    edit:
        cout<<"\n                                                         Enter Product No. to edit."<<endl;
        cout<<"                                                         --> ";
        cin>>product_num;
        cin.ignore();

        while(cin.fail())
        {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout<<"                                                         Invalid Product No!"<<endl;
            cout<<"                                                         Enter any key to reenter Product No."<<endl;
            cout<<"                                                         Enter 0 to go back to main menu"<<endl;
            cout<<"                                                         --> ";
            getline(cin,choice);

            if(choice == "0")
            {
                goto main_menu;
            }
            else
            {
                goto edit;
            }
        }

        choose_edit:
            if(t.check_product_num(item_record, product_num))
            {
                endl(cout);
                cout<<"                                                                        1. Edit Product Name"<<endl;
                cout<<"                                                                        2. Edit Quantity "<<endl;
                cout<<"                                                                        3. Edit Cost "<<endl;
                cout<<"                                                                        4. Edit Margin"<<endl;///newly added
                cout<<"                                                                        5. Edit Price"<<endl;///newly added
                cout<<"                                                                        6. Edit Manufacture Date"<<endl;
                cout<<"                                                                        7. Edit Expire Date"<<endl<<endl;
                cout<<"                                                         Please select option: ";
                getline(cin, edit_choice);
                cin.ignore();

                        if(edit_choice == "1")
                        {
                        reenter_product_name:
                            cout<<"                                                         Enter new Product Name: ";
                            getline(cin, newProduct_name);

                        confirm_product_name:
                            cout<<"                                                         Confirm change the Product Name to "<<newProduct_name<<"?"<<endl;
                            cout<<"                                                         Enter (Y) to confirm/ (N) to reenter Product Name"<<endl;
                            cout<<"                                                         --> ";
                            getline(cin, confirmation);

                            for(unsigned int i = 0; i < newProduct_name.length(); i++)
                            {
                                newProduct_name[i] = toupper(newProduct_name[i]);
                            }

                            if(confirmation == "Y" || confirmation == "y")
                            {
                                if(t.check_exist_product_name(item_record, newProduct_name))
                                {
                                    cout<<"                                                         Product Name is existed."<<endl;
                                    cout<<"                                             -----------------------------------------------------------                                                         "<<endl;
                                    system("pause");
                                    goto reenter_product_name;
                                }
                                else
                                {
                                    item_record[index].upProduct_name(newProduct_name);
                                    cout<<"\n\n                                                                   ------------------------"<<endl;
                                    cout<<"                                                                   |........Success!........|"<<endl;
                                    cout<<"                                                                   ------------------------"<<endl;
                                    system("pause");
                                    goto main_menu;
                                }
                            }
                            else if(confirmation == "N" || confirmation == "n")
                            {
                                goto reenter_product_name;
                            }
                            else
                            {
                                cout<<"                                                         ***Enter Y or N only!***"<<endl;
                                cout<<"                                             -----------------------------------------------------------                                                         "<<endl;
                                system("pause");
                                goto confirm_product_name;
                            }
                        }
                        else if(edit_choice == "2")
                        {
                        reenter_quantity:
                            cout<<"                                                         Enter new Product Quantity: ";
                            cin>>newQuantity;
                            cin.ignore();

                            while(cin.fail())
                            {
                                cin.clear();
                                cin.ignore(INT_MAX, '\n');
                                cout<<"                                                         Invalid Quantity!"<<endl;
                                cout<<"                                                         ***Enter number only!***"<<endl;
                                cout<<"                                             -----------------------------------------------------------                                                         "<<endl;
                             system("pause");
                                goto reenter_quantity;
                            }

                        confirm_quantity:
                            cout<<"                                                         Change the Product Quantity to "<<newQuantity<<"?"<<endl;
                            cout<<"                                                         Enter (Y) to confirm/ (N) to reenter Product Quantity"<<endl;
                            cout<<"                                                         --> ";
                            getline(cin, confirmation);

                            if(newQuantity < 0)
                            {
                                cout<<"                                                         Invalid Product Quantity!"<<endl;
                                cout<<"                                             -----------------------------------------------------------                                                         "<<endl;
                                system("pause");
                                goto reenter_quantity;
                            }
                            else
                            {
                                if(confirmation == "Y" || confirmation == "y")
                                {
                                    item_record[index].upQuantity(newQuantity);
                                    cout<<"\n\n                                                                   ------------------------"<<endl;
                                    cout<<"                                                                   |........Success!........|"<<endl;
                                    cout<<"                                                                   ------------------------"<<endl;
                                    system("pause");
                                    goto main_menu;
                                }
                                else if(confirmation == "N" || confirmation == "n")
                                {
                                    goto reenter_quantity;
                                }
                                else
                                {
                                    cout<<"                                                         ***Enter Y or N only!***"<<endl;
                                    cout<<"                                             -----------------------------------------------------------                                                         "<<endl;
                                    system("pause");
                                    goto confirm_quantity;
                                }
                            }
                        }
                        else if(edit_choice == "3")
                        {
                        reenter_cost:
                            cout<<"                                                         Enter new Cost Per Unit: ";
                            cin>>newCost;
                            cin.ignore();

                            while(cin.fail())
                            {
                                cin.clear();
                                cin.ignore(INT_MAX, '\n');
                                cout<<"                                                         Invalid Cost Per Unit!"<<endl;
                                cout<<"                                                         ***Enter Y or N only!***"<<endl;
                                cout<<"                                             -----------------------------------------------------------                                                         "<<endl;
                                system("pause");
                                goto reenter_cost;
                            }

                        confirm_cost:
                            cout<<"                                                         Change the Product Cost to RM "<<newCost<<"?"<<endl;
                            cout<<"                                                         Enter (Y) to confirm/ (N) to reenter Cost Per Unit"<<endl;
                            cout<<"                                                         --> ";
                            getline(cin, confirmation);

                            if(newCost > 0 && newCost != item_record[index].getCost())
                            {
                                if(confirmation == "Y" || confirmation == "y")
                                {
                                    item_record[index].upCost(newCost);
                                    item_record[index].upPrice(newCost,item_record[index].getMargin());
                                    cout<<"\n\n                                                                   ------------------------"<<endl;
                                    cout<<"                                                                   |........Success!........|"<<endl;
                                    cout<<"                                                                   ------------------------"<<endl;
                                    system("pause");
                                    goto main_menu;
                                }
                                else if(confirmation == "N" || confirmation == "n")
                                {
                                    goto reenter_cost;
                                }
                                else
                                {
                                    cout<<"                                                         ***Enter Y or N only!***"<<endl;
                                    cout<<"                                             -----------------------------------------------------------                                                         "<<endl;
                                    system("pause");
                                    goto confirm_cost;
                                }
                            }
                            else
                            {
                                cout<<"                                                         Invalid Product Cost or it is same cost as previous!"<<endl;
                                cout<<"                                             --------------------------------------------------------------------------                                         "<<endl;
                                system("pause");
                                goto reenter_cost;
                            }

                        }
                        else if(edit_choice == "4")
                        {
                        reenter_margin:
                            cout<<"                                                         Enter new Margin Per Unit: ";
                            cin>>newMargin;
                            cin.ignore();

                            while(cin.fail())
                            {
                                cin.clear();
                                cin.ignore(INT_MAX, '\n');
                                cout<<"                                                         Invalid Margin Per Unit!"<<endl;
                                cout<<"                                                         ***Enter Y or N only!***"<<endl;
                                cout<<"                                             -----------------------------------------------------------                                                         "<<endl;
                                system("pause");
                                goto reenter_margin;
                            }

                        confirm_margin:
                            cout<<"                                                         Change the Product Margin to "<<newMargin<<"% ?"<<endl;
                            cout<<"                                                         Enter (Y) to confirm/ (N) to reenter Cost Per Unit"<<endl;
                            cout<<"                                                         --> ";
                            getline(cin, confirmation);

                            if(newMargin > 0 && newMargin != item_record[index].getMargin())
                            {
                                if(confirmation == "Y" || confirmation == "y")
                                {
                                    item_record[index].upMargin(newMargin);
                                    item_record[index].upPrice(item_record[index].getCost(),newMargin);
                                    cout<<"\n\n                                                                   ------------------------"<<endl;
                                    cout<<"                                                                   |........Success!........|"<<endl;
                                    cout<<"                                                                   ------------------------"<<endl;
                                    system("pause");
                                    goto main_menu;

                                }
                                else if(confirmation == "N" || confirmation == "n")
                                {
                                    goto reenter_margin;
                                }
                                else
                                {
                                    cout<<"                                                         ***Enter Y or N only!***"<<endl;
                                    cout<<"                                             -----------------------------------------------------------                                                         "<<endl;
                                    system("pause");
                                    goto confirm_margin;
                                }
                            }
                            else
                            {
                                cout<<"                                                         Invalid Product Margin or it is same cost as previous!"<<endl;
                                cout<<"                                             --------------------------------------------------------------------------                                         "<<endl;
                                system("pause");
                                goto reenter_margin;
                            }
                        }
                        else if(edit_choice == "5")
                        {
                        reenter_price:
                            cout<<"                                                         Enter new Price Per Unit: ";
                            cin>>newPrice;
                            cin.ignore();

                            while(cin.fail())
                            {
                                cin.clear();
                                cin.ignore(INT_MAX, '\n');
                                cout<<"                                                         Invalid Price Per Unit!"<<endl;
                                cout<<"                                                         ***Enter Y or N only!***"<<endl;
                                cout<<"                                             -----------------------------------------------------------                                                         "<<endl;
                                system("pause");
                                goto reenter_margin;
                            }

                        confirm_price:
                            cout<<"                                                         Change the Product Price to RM "<<newPrice<<"?"<<endl;
                            cout<<"                                                         Enter (Y) to confirm/ (N) to reenter Cost Per Unit"<<endl;
                            cout<<"                                                         --> ";
                            getline(cin, confirmation);

                            if(newPrice > 0 && newPrice != item_record[index].getPrice())
                            {
                                if(confirmation == "Y" || confirmation == "y")
                                {
                                    item_record[index].setPrice(newPrice);
                                    item_record[index].upNewMargin(newPrice, item_record[index].getCost());
                                    cout<<"\n\n                                                                   ------------------------"<<endl;
                                    cout<<"                                                                   |........Success!........|"<<endl;
                                    cout<<"                                                                   ------------------------"<<endl;
                                    system("pause");
                                    goto main_menu;

                                }
                                else if(confirmation == "N" || confirmation == "n")
                                {
                                    goto reenter_price;
                                }
                                else
                                {
                                    cout<<"                                                         ***Enter Y or N only!***"<<endl;
                                    cout<<"                                             -----------------------------------------------------------                                                         "<<endl;
                                    system("pause");
                                    goto confirm_price;
                                }
                            }
                            else
                            {
                                cout<<"                                                         Invalid Product Cost or it is same cost as previous!"<<endl;
                                cout<<"                                             --------------------------------------------------------------------------                                         "<<endl;
                                system("pause");
                                goto reenter_price;
                            }
                        }
                        else if(edit_choice == "6")
                        {
                        reenter_manufacture_date:
                            cout<<"                                                         Enter new Manufacture Date--> "<<endl;
                            cout<<"                                                                               (DD) : ";
                            cin>>newMDay;

                            while(cin.fail())
                            {
                                cin.clear();
                                cin.ignore(INT_MAX, '\n');
                                cout<<"                                                         Invalid Date!"<<endl;
                                cout<<"                                                         ***Enter Y or N only!***"<<endl;
                                cout<<"                                             -----------------------------------------------------------                                                         "<<endl;
                                system("pause");
                                goto reenter_manufacture_date;
                            }

                            cout<<"                                                                               (MM) : ";
                            cin>>newMMonth;

                            while(cin.fail())
                            {
                                cin.clear();
                                cin.ignore(INT_MAX, '\n');
                                cout<<"                                                         Invalid Date!"<<endl;
                                cout<<"                                                         ***Enter Y or N only!***"<<endl;
                                cout<<"                                             -----------------------------------------------------------                                                         "<<endl;
                                system("pause");
                                goto reenter_manufacture_date;
                            }

                            cout<<"                                                                             (YYYY) : ";
                            cin>>newMYear;
                            cin.ignore();

                            while(cin.fail())
                            {
                                cin.clear();
                                cin.ignore(INT_MAX, '\n');
                                cout<<"                                                         Invalid Date!"<<endl;
                                cout<<"                                                         ***Enter Y or N only!***"<<endl;
                                cout<<"                                             -----------------------------------------------------------                                                         "<<endl;
                                system("pause");
                                goto reenter_manufacture_date;
                            }

                        confirm_manufacture_date:
                            cout<<"                                                         Confirm change the Product Manufacture Date to "<<newMDay;
                            cout<<"/"<<newMMonth<<"/"<<newMYear<<"?"<<endl<<endl;
                            cout<<"                                                         Enter (Y) to confirm/ (N) to reenter Manufacture Date."<<endl;
                            cout<<"                                                         --> ";
                            getline(cin, confirmation);

                            if(t.check_manufacture_date(newMDay, newMMonth, newMYear))
                            {
                                if(newMDay == item_record[index].getMDay() && newMMonth == item_record[index].getMMonth() && newMYear == item_record[index].getMYear())
                                {
                                    cout<<"                                                         The Manufacture Date is same as previous!"<<endl;
                                    system("pause");
                                    goto reenter_manufacture_date;
                                }
                                else
                                {
                                    if(confirmation == "Y" || confirmation == "y")
                                    {
                                        item_record[index].upMDay(newMDay);
                                        item_record[index].upMMonth(newMMonth);
                                        item_record[index].upMYear(newMYear);
                                        cout<<"\n\n                                                                   ------------------------"<<endl;
                                        cout<<"                                                                   |........Success!........|"<<endl;
                                        cout<<"                                                                   ------------------------"<<endl;
                                        system("pause");
                                        goto main_menu;
                                    }
                                    else if(confirmation == "N" || confirmation == "n")
                                    {
                                        goto reenter_manufacture_date;
                                    }
                                    else
                                    {
                                        cout<<"                                                         ***Enter Y or N only!***"<<endl;
                                        cout<<"                                             -----------------------------------------------------------                                                         "<<endl;
                                        system("pause");
                                        goto confirm_manufacture_date;
                                    }
                                }
                            }
                            else
                            {
                                cout<<"                                                         Invalid Manufacture Date! Please enter a date before today."<<endl;
                                cout<<"                                             --------------------------------------------------------------------------                                         "<<endl;
                                system("pause");
                                goto reenter_manufacture_date;
                            }
                        }
                        else if(edit_choice == "7")
                        {
                        reenter_expired_date:
                            cout<<"                                                         Enter new Expired Date--> "<<endl;
                            cout<<"                                                                          (DD) : ";
                            cin>>newEDay;

                            while(cin.fail())
                            {
                                cin.clear();
                                cin.ignore(INT_MAX, '\n');
                                cout<<"                                                         Invalid Date!"<<endl;
                                cout<<"                                                         ***Enter Y or N only!***"<<endl;
                                cout<<"                                             -----------------------------------------------------------                                                         "<<endl;
                                system("pause");
                                goto reenter_expired_date;
                            }

                            cout<<"                                                                          (MM) : ";
                            cin>>newEMonth;

                            while(cin.fail())
                            {
                                cin.clear();
                                cin.ignore(INT_MAX, '\n');
                                cout<<"                                                         Invalid Date!"<<endl;
                                cout<<"                                                         ***Enter Y or N only!***"<<endl;
                                cout<<"                                             -----------------------------------------------------------                                                         "<<endl;
                                system("pause");
                                goto reenter_expired_date;
                            }

                            cout<<"                                                                        (YYYY) : ";
                            cin>>newEYear;
                            cin.ignore();

                            while(cin.fail())
                            {
                                cin.clear();
                                cin.ignore(INT_MAX, '\n');
                                cout<<"                                                         Invalid Date!"<<endl;
                                cout<<"                                                         ***Enter Y or N only!***"<<endl;
                                cout<<"                                             -----------------------------------------------------------                                                         "<<endl;
                                system("pause");
                                goto reenter_expired_date;
                            }

                        confirm_expired_date:
                            cout<<"                                                         Confirm change the Product Expired Date to "<<newEDay;
                            cout<<"/"<<newEMonth<<"/"<<newEYear<<"?"<<endl<<endl;
                            cout<<"                                                         Enter (Y) to confirm/ (N) to reenter Expired Date"<<endl;
                            cout<<"                                                         --> ";
                            getline(cin, confirmation);

                            if(t.check_expired_date(newEDay, newEMonth, newEYear))
                            {
                                if(newEDay == item_record[index].getEDay() && newEMonth == item_record[index].getEMonth() && newEYear == item_record[index].getEYear())
                                {
                                    cout<<"                                                         The Expired Date is same as previous!"<<endl;
                                    system("pause");
                                    goto reenter_expired_date;
                                }
                                else
                                {
                                    if(confirmation == "Y" || confirmation == "y")
                                    {
                                        item_record[index].upEDay(newEDay);
                                        item_record[index].upEMonth(newEMonth);
                                        item_record[index].upEYear(newEYear);
                                        cout<<"\n\n                                                                   ------------------------"<<endl;
                                        cout<<"                                                                   |........Success!........|"<<endl;
                                        cout<<"                                                                   ------------------------"<<endl;
                                        goto main_menu;
                                    }
                                    else if(confirmation == "N" || confirmation == "n")
                                    {
                                        goto reenter_expired_date;
                                    }
                                    else
                                    {
                                        cout<<"                                                         ***Enter Y or N only!***"<<endl;
                                        cout<<"                                             -----------------------------------------------------------                                                         "<<endl;
                                        system("pause");
                                        goto confirm_expired_date;
                                    }
                                }
                            }
                            else
                            {
                                cout<<"                                                         Invalid Expired Date! Please enter a date after today."<<endl;
                                cout<<"                                             --------------------------------------------------------------------------                                         "<<endl;
                                system("pause");
                                goto reenter_expired_date;
                            }
                        }
                        else
                        {
                            cout<<"                                                         Invalid input!"<<endl;
                            goto choose_edit;
                        }

            }//end if
            else
            {
                cout<<"                                                         Invalid Product No!"<<endl;
                cout<<"                                                         Enter any key to reenter Product No."<<endl;
                cout<<"                                                         Enter 0 to go back to main menu"<<endl;
                cout<<"                                                         --> ";
                getline(cin, choice);

                if(choice == "0")
                {
                    goto main_menu;
                }
                else
                {
                    goto edit;
                }

            }
             break;
case '7':
    t.expired_product(item_record);
    system("pause");
    goto main_menu;
    break;
case '8':
    Writefile();
    return 0;
    break;

default:
    char choice;
    cout<<"                                                         Wrong input"<<endl;
    cout<<"                                                         Do you wish to go back main menu? (y/n)"<<endl;
    cin>>choice;
    if(choice=='y'||choice=='Y')
    {
    goto main_menu;
    }
    else if(choice=='n'||choice=='N')
    {
    return 0;
    }
    else
    {
    return 0;
    }
    break;


}
Writefile();
return 0;

}
