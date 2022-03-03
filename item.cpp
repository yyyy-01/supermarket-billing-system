#include <iostream>
#include <sstream>
#include <queue>
#include <vector>
#include <ctime>
#include <stack>
#include <bits/stdc++.h>
#include "item.hpp"
#include <iomanip>
#include <fstream>
#include <bits/stdc++.h> //to use floor(long(n)-1): count the number of digits

using namespace std;
using namespace itemHpp;

//declaration of functions in class Item
Item::Item(){}

Item::Item(int product_num, string product_name, float margin, float price, int quantity, float cost,
     int mDay, int mMonth, int mYear, int eDay, int eMonth, int eYear)
             //initialization list
    : product_num(product_num), product_name(product_name), margin(margin), price(price), quantity(quantity), cost(cost),
    mDay(mDay), mMonth(mMonth), mYear(mYear), eDay(eDay), eMonth(eMonth), eYear(eYear)
    { };


void Item::fillproduct(vector<Item>& newitem)
{
    Item object(product_num, product_name, margin, price, quantity, cost, mDay, mMonth, mYear, eDay, eMonth, eYear);
    newitem.push_back(object);
}

int Item::getProduct_num()
{
    return product_num;
}

string Item::getProduct_name()
{
     for(unsigned int i = 0; i < product_name.length(); i++)
        {
            product_name[i] = toupper(product_name[i]);
        }
    return product_name;
}


float Item::getMargin()
{
    return margin;
}

int Item::getQuantity()
{
    return quantity;
}

float Item::getCost()
{
    return cost;
}

int Item::getMDay()
{
    return mDay;
}

int Item::getMMonth()
{
    return mMonth;
}

int Item::getMYear()
{
    return mYear;
}

int Item::getEDay()
{
    return eDay;
}

int Item::getEMonth()
{
    return eMonth;
}

int Item::getEYear()
{
    return eYear;
}

int Item::get_Pnum_counter()
{
    return Pnum_counter;
}

int Item::get_current_day()
{
    return nowDay;
}

int Item::get_current_month()
{
    return nowMonth;
}

int Item::get_current_year()
{
    return nowYear;
}

float Item::getPrice()
{
    return price;
}

void Item::upProduct_num(int product_num)
{
    this->product_num = product_num;
}

void Item::upProduct_name(string product_name)
{
    this->product_name = product_name;
}

void Item::upMargin(float margin)
{
    this->margin = margin;
}

void Item::upQuantity(int quantity)
{
    this->quantity = quantity;
}

void Item::upCost(float cost)
{
    this->cost = cost;
}

void Item::upMDay(int mDay)
{
    this->mDay = mDay;
}

void Item::upMMonth(int mMonth)
{
    this->mMonth = mMonth;
}

void Item::upMYear(int mYear)
{
    this->mYear = mYear;
}

void Item::upEDay(int eDay)
{
    this->eDay = eDay;
}

void Item::upEMonth(int eMonth)
{
    this->eMonth = eMonth;
}

void Item::upEYear(int eYear)
{
    this->eYear = eYear;
}

void Item::up_Pnum_counter(int counter)
{
    Pnum_counter = counter;
}

void Item::up_current_day(int nowDay)
{
    this->nowDay = nowDay;
}

void Item::up_current_month(int nowMonth)
{
    this->nowMonth = nowMonth;
}

void Item::up_current_year(int nowYear)
{
    this->nowYear = nowYear;
}

void Item::upPrice(float cost, float margin)
{
    price = (cost/(1-margin/100));
    setPrice(price);
}

void Item::setPrice(float price)
{
    this->price = price;
}

void Item::upNewMargin(float price, float cost)
{
    margin = ((price-cost)/price)*100;
    upMargin(margin);
}

/** ---------------------boolean checking--------------**/

void Item::current_time()
{
    // current date/time based on current system
    time_t now = time(0);

    tm* ltm = localtime(&now);
    // various components of tm structure
    nowYear = 1900 + ltm->tm_year; //tm_year means years since 1900
    nowMonth = 1 + ltm->tm_mon; //tm_mon means months since January
    nowDay = ltm->tm_mday; //tm_mday means day of the month

}


bool Item::check_manufacture_date(int mDay, int mMonth, int mYear)
{
    current_time();

    if(mYear == nowYear && mYear>2010)
    {
        if(mMonth == 2 && mMonth < nowMonth)
        {
            if((mYear%400==0) || (mYear%4==0 && mYear%100!=0))
            {
                if(mDay <= 29 && mDay > 0)
                {
                    return true;
                }

                return false;
            }
            else
            {
                if(mDay <= 28 && mDay > 0)
                {
                    return true;
                }

            return false;
            }
        }
        else if(mMonth == nowMonth)
        {
            if(mDay < nowDay && mDay > 0)
            {
                return true;
            }
            return false;
        }
        else if(mMonth < nowMonth)
        {
            if(mMonth == 1 || mMonth == 3 || mMonth== 5 || mMonth == 7 ||
               mMonth == 8 || mMonth == 10 || mMonth ==12)
            {
                if(mDay > 0 && mDay <= 31)
                {
                    return true;
                }

                return false;
            }
            else if(mMonth == 4 || mMonth == 6 || mMonth == 9 || mMonth == 11)
            {
                if(mDay > 0 && mDay <= 30)
                {
                    return true;
                }

                return false;
            }

            return false;
        }

        return false;
    }
    else if(mYear < nowYear && mYear>2010)
    {
        if(mMonth == 2)
        {
            if((mYear%400==0) || (mYear%4==0 && mYear%100!=0))
            {
                if(mDay <= 29 && mDay > 0)
                {
                    return true;
                }

                return false;
            }
            else
            {
                if(mDay <= 28 && mDay > 0)
                {
                    return true;
                }

                return false;
            }
        }
        else if(mMonth == 1 || mMonth == 3 || mMonth == 5 || mMonth == 7 ||
                 mMonth == 8 || mMonth == 10 || mMonth == 12)
        {
            if(mDay > 0 && mDay <= 31)
            {
                return true;
            }

            return false;
        }
        else if(mMonth == 4 || mMonth == 6 || mMonth == 9 || mMonth == 11)
        {
            if(mDay > 0 && mDay <= 30)
            {
                return true;
            }

            return false;
        }

        return false;
    }

    return false;
}

bool Item::check_expired_date(int eDay, int eMonth, int eYear)
{
    current_time();

    if(eYear == nowYear && eYear>2010 && eYear <= 2050)
    {
        if(eMonth == 2 && eMonth < nowMonth)
        {
            if((eYear%400==0) || (eYear%4==0 && eYear%100!=0))
            {
                if(eDay <= 29 && eDay > 0)
                {
                    return true;
                }

                return false;
            }
            else
            {
                if(eDay <= 28 && eDay > 0)
                {
                    return true;
                }

            return false;
            }
        }
        else if(eMonth == nowMonth)
        {
            if(eDay > nowDay && eDay > 0)
            {
                return true;
            }
            return false;
        }
        else if(eMonth > nowMonth)
        {
            if(eMonth == 1 || eMonth == 3 || eMonth== 5 || eMonth == 7 ||
               eMonth == 8 || eMonth == 10 || eMonth ==12)
            {
                if(eDay > 0 && eDay <= 31)
                {
                    return true;
                }

                return false;
            }
            else if(eMonth == 4 || eMonth == 6 || eMonth == 9 || eMonth == 11)
            {
                if(eDay > 0 && eDay <= 30)
                {
                    return true;
                }

                return false;
            }

            return false;
        }

        return false;
    }
    else if(eYear > nowYear && eYear>2010 && eYear <= 2050)
    {
        if(eMonth == 2)
        {
            if((eYear%400==0) || (eYear%4==0 && eYear%100!=0))
            {
                if(eDay <= 29 && eDay > 0)
                {
                    return true;
                }

                return false;
            }
            else
            {
                if(eDay <= 28 && eDay > 0)
                {
                    return true;
                }

                return false;
            }
        }
        else if(eMonth == 1 || eMonth == 3 || eMonth == 5 || eMonth == 7 ||
                 eMonth == 8 || eMonth == 10 || eMonth == 12)
        {
            if(eDay > 0 && eDay <= 31)
            {
                return true;
            }

            return false;
        }
        else if(eMonth == 4 || eMonth == 6 || eMonth == 9 || eMonth == 11)
        {
            if(eDay > 0 && eDay <= 30)
            {
                return true;
            }

            return false;
        }

        return false;
    }

    return false;
}

bool Item::check_product_num(vector <Item> newnewItem, int product_num)
{
    for(unsigned int i = 0; i < newnewItem.size(); i++)
    {
        if(product_num == newnewItem[i].getProduct_num())
        {
            index = i;
            return index, true;
        }
    }

    return false;
}

bool Item::check_exist_product_num(vector <Item> newnewItem, int newProduct_num)
{
    for(unsigned int i = 0; i < newnewItem.size(); i++)
    {
        if(newProduct_num == newnewItem[i].getProduct_num())
        {
            return true;
        }
    }return false;
}

bool Item::check_exist_product_name(vector <Item> newnewItem, string newProduct_name)
{
    for(unsigned int i = 0; i < newnewItem.size(); i++)
    {
        if(newProduct_name == newnewItem[i].getProduct_name())
        {
            return true;
        }
    }
    return false;
}

bool Item::check_product_name (vector <Item> newnewItem, string& input)
{
    unsigned int digitCounter = 0;
    for(unsigned int i = 0 ; i <input.size(); i++)
    {
        if(isdigit(input[i]) || isspace(input[i]))
        {
            digitCounter++;
        }
    }
     if (digitCounter != input.size())
     {
         return true;
     }
     else
        //if full, return false
        return false;
}

int Item::get_index_product(vector <Item> newItem, int product_num)
{
    for(unsigned int i = 0; i < newItem.size(); i++)
    {
        if(product_num == newItem[i].getProduct_num())
        {
            index = i;
            return index;
        }
    }
}


//5.search
void Item::binarySearch(vector <Item> arr, unsigned l, unsigned r, int num, bool& found, unsigned& i){
    if (num<arr[l].getProduct_num()){
        return;
    }
    if (r >= l) {
        unsigned mid = l + (r - l) / 2;

        if (arr[mid].getProduct_num() == num){
            found=true;
            i = mid;
        }else if (arr[mid].getProduct_num() > num){
            binarySearch(arr, l, mid - 1, num, found, i);
        }else if (arr[mid].getProduct_num() < num){
            binarySearch(arr, mid + 1, r, num, found, i);
        }
    }else{
        found=false;
    }
    return;
}

void Item::searchbyPnum(vector<Item> newItem,int& num){
    //binary search
    bool found=false;
    unsigned l=0;
    unsigned r = newItem.size() - 1;
    unsigned i;

    binarySearch(newItem, l, r, num, found, i);

    if(!found){
        cout<<"                                                                      Not found"<<endl;
    }else{
        stack <Item> result;
        result.push(newItem[i]);
        displaysearch(result);
    }
}

void Item::searchbyName(vector <Item> newItem, string name){
    for(unsigned i = 0; i < name.length(); i++)
    {
        name[i] = toupper(name[i]);
    };

	stack <Item> result;

    for (unsigned i = 0; i < newItem.size(); ++i)
	{
//		if (newItem[i].getProduct_name() == name) {
//			result.push(newItem[i]);
//		}

        size_t found = newItem[i].getProduct_name().find(name);
        if (found != string::npos)
            result.push(newItem[i]);
	}



	if (result.empty()){
        cout<<"                                                                   Product not found! "<<endl;
	}else{
        displaysearch(result);
	}
}

void Item::searchbyAlpha(vector <Item> newItem, char &ch){
    ch = toupper(ch);
    stack <Item> result;

    for (unsigned i = 0; i < newItem.size(); ++i)
	{
		if (newItem[i].getProduct_name()[0] == ch) {
			result.push(newItem[i]);
		}
	}

	if (result.empty()){
        cout<<"                                                                  Product not found! "<<endl;
	}else{
        displaysearch(result);
	}
}

void Item::displaysearch(stack<Item> s){
    cout<<"                                                         "<<s.size()<<" result(s) found."<<endl<<endl;

    while(!s.empty()){
    cout<<"                                               Product number               : "<<s.top().getProduct_num()<<endl;
    cout<<"                                               Name                         : "<<s.top().getProduct_name()<<endl;
    cout<<"                                               Quantity                     : "<<s.top().getQuantity()<<endl;
    cout<<"                                               Manufacture date (DD/MM/YYYY): "<<s.top().getMDay()<<"/"
                                                                                                    <<s.top().getMMonth()<<"/"
                                                                                                    <<s.top().getMYear()<<endl;
    cout<<"                                               Expired date (DD/MM/YYYY)    : "<<s.top().getEDay()<<"/"
                                                                                                    <<s.top().getEMonth()<<"/"
                                                                                                    <<s.top().getEYear()<<endl;
    cout<<"                                               Cost (per unit)              : RM "<<s.top().getCost()<<endl;
    cout<<"                                               Price (tax 6%)               : RM "<<fixed<<setprecision(2)<<s.top().getPrice()<<endl;
    cout<<"                                               Margin (%)                   : "<<s.top().getMargin()<<"%"<<endl;
    cout<< endl;
    s.pop();
    }
}
/* input = product number to be deleted" */
void Item::delete_product(vector <Item>& newItem, int input)
{
    if(check_product_num(newItem,input))
    {
        int index = get_index_product(newItem, input);
        newItem.erase(newItem.begin()+ index);
        cout<<"                                                                  Product deleted "<<endl;
    }
    else
    {
        endl(cout);
        cout<<"                                                           Wrong input, "<<input<<" does not exist"<<endl;
    }
}

void Item::expired_product(vector<Item>& newItem)
{
    queue<Item> expired_item;
    current_time();
    for(int i =0; i<newItem.size();i++)
    {
        if(newItem[i].getEYear() < nowYear)
        {//check year is smaller than this year
            expired_item.push(newItem[i]);
        }
        else if(newItem[i].getEYear() == nowYear)
        {//if item year is same with this year
            if(newItem[i].getEMonth() < nowMonth)
            {
                expired_item.push(newItem[i]);
            }
            else if(newItem[i].getEMonth() == nowMonth)
            {//if expired month is the same with this month, but expired a few days
                if(newItem[i].getEDay() < nowDay)
                {
                    expired_item.push(newItem[i]);
                }
            }
        }

    }
    if(expired_item.empty())
    {
        cout<<"                                                                  No expired product"<<endl;
    }

    if(!expired_item.empty())
        delete_expired_product(newItem,expired_item);
}

void Item::delete_expired_product(vector<Item>& newItem, queue<Item> newQueue)
{
    char confirmation;

    for(int i=0;i<=newQueue.size()+1;i++)
    {
        cout<<"                                                                  Expired Product : "<< newQueue.front().getProduct_name()<<endl;
       cout<<"                                                                  Do you wish to delete this product (Y/N)?";
       cin>>confirmation;
       if(confirmation=='Y'||confirmation=='y')
       {
           for(int j = 0; j<newItem.size();j++)
           {
               if (newQueue.front().getProduct_name() == newItem[j].getProduct_name())
               {
                    delete_product(newItem,newItem[j].getProduct_num());
               }
           }
           newQueue.pop();
       }
       else if(confirmation=='N'||confirmation=='n')
       {
           newQueue.pop();
       }
       else
       {
           cout<<"                                                                  Invalid input"<<endl;
           system("pause");
       }
    }

}
void Item::displayNum(vector<Item> newItem)
{
    for(unsigned int i = 0 ; i <newItem.size() ; i++)
    cout<<"                                                         Display product num entered:" << newItem[i].getProduct_num()<<endl;
}

//Display Function
void Item :: display_all(vector <Item>& newItem)
{
    int size = newItem.size();
    cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "   " << "|  Product No  |" << "    " << "|  Product Name  |" << "    "<<"|Manufactured Date  |" <<"    "<<"|  Expired Date  |" << "    "<<"|  Margin  |" << "     " << "|  Quantity  | ";
    cout << "   " <<"|  Cost(RM)  |" <<"   "<< "|  Price(RM) |" << endl;
    cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    for(int i = 0; i < size; i++)
    {
        cout << "   |     " << newItem[i].getProduct_num() << setw(6)<<"|"<<setw(5)<<"|"<< newItem[i].getProduct_name()<<setw(17-(newItem[i].getProduct_name()).size()) <<"|";//<< setw(5) << "|"<< setw(7)<<newItem[i].getQuantity();
//        cout << setw(6) << "|" <<setw(6)<<"|" << fixed << setprecision(2)<<"   "<< newItem[i].getPrice()<<setw(2)<<"|";
        cout << setw(5) << "|" << setw(5) << newItem[i].getMDay()  << "/" << setw(2) << newItem[i].getMMonth() << "/"  << setw(2) << newItem[i].getMYear()<< setw(7) << "|" ;
        cout << setw(5) << "|" << setw(5) << newItem[i].getEDay()  << "/" << setw(2) << newItem[i].getEMonth() << "/"  << setw(2) << newItem[i].getEYear()<< setw(4) << "|" ;
        cout << setw(5) << "|" << setw(7) << fixed << setprecision(2) << newItem[i].getMargin() <<setw(4) << "|" << setw(6) << "|"<< setw(7)<<newItem[i].getQuantity() << setw(6) << "|";
        cout << setw(5) << "|" << setw(8) << newItem[i].getCost() << setw(5) << "|";
        cout  << setw(4)<<"|" << fixed << setprecision(2)<<"   "<< newItem[i].getPrice();
        cout << endl;
    }return;
}

///*------------------------Sort-------------------*

void merge(vector<Item>& newItem, int first, int mid, int last ){
   int tempSize = last-first+1;
    Item temp[tempSize];//temp array
    int leftSize=mid-first+1;
    int rightSize = last - mid;
    int leftCounter=0;//left array counter
    int rightCounter=0;//right array counter
    int i=0;//temp array counter

    while (leftCounter<leftSize && rightCounter<rightSize){
        if(newItem[first+leftCounter].getProduct_name()<newItem[mid+1+rightCounter].getProduct_name()){
            temp[i]=newItem[first+leftCounter];
            leftCounter++;
            i++;
        }else{
            temp[i]=newItem[mid+1+rightCounter];
            rightCounter++;
            i++;
        }
    }
    while (leftCounter<leftSize){ //if left have unsorted while right is all sorted
        temp[i]=newItem[first+leftCounter];
        leftCounter++;
        i++;
    }
    while (rightCounter<rightSize){ //if right have unsorted while left is all sorted
        temp[i]=newItem[mid+1+rightCounter];
        rightCounter++;
        i++;
    }

    //copy temp Array to theArray
    for (int i=0; i<tempSize; i++){
        newItem[first+i]=temp[i];
    }

}

void mergeSort(vector<Item>& newItem, int first, int last){
    if(first<last){
        int mid = (first+last)/2 ;
        mergeSort(newItem, first, mid);//split left
        mergeSort(newItem, mid+1, last);//split right

        merge(newItem, first, mid, last);
    }
}

void Item::sortbyName(vector<Item>& newItem, int size){
    mergeSort(newItem, 0,size-1);
}

void Item::quicksort(vector<Item>& newItem, int first, int last)
{

    int pivotIndex;
    if(first<last)
    {
        partition(newItem,first,last,pivotIndex);
        quicksort(newItem,first,pivotIndex-1);
        quicksort(newItem,pivotIndex+1,last);

    }
}

void Item::partition(vector<Item>&v1,int first, int last, int& pivotIndex)
{
    int pivot = v1[first].getPrice();
    int s1 = first;
    int s2 = first+1;

    while(s2<=last)
    {
        if((v1[s2].getPrice()*100 )< pivot*100)
        {
            swap(v1[s2],v1[s1+1]);
            s1++;
        }//end if
        s2++;
    }//end while

    swap(v1[first],v1[s1]);
    pivotIndex = s1;

}

void swap(Item&x, Item&y)
{
    Item temp = x;
    x = y;
    y = temp;
}

