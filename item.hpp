#ifndef ITEM_HPP_INCLUDED
#define ITEM_HPP_INCLUDED
#include <vector>

using namespace std;
namespace itemHpp
{

class Item
{
private:
    int product_num = 1000, quantity, mDay, mMonth, mYear, eDay, eMonth, eYear, Pnum_counter;
    int nowDay, nowMonth, nowYear, index, p_name_counter;
    string product_name;
    float cost, price, margin;


public:
    Item();
    Item(int product_num, string product_name, float margin,
           float price, int quantity, float cost, int mDay,
           int mMonth, int mYear, int eDay, int eMonth, int eYear);

    void add();
    void display_all(vector <Item>& newItem);
    int search_item(string name);
    float item_price(float cost);

    int getProduct_num();
    string getProduct_name();
    float getMargin();
    int getQuantity();
    float getCost();
    int getMDay();
    int getMMonth();
    int getMYear();
    int getEDay();
    int getEMonth();
    int getEYear();
    int get_index_product(vector <Item> newItem_record, int product_num);
    int get_Pnum_counter();
    int get_current_day();
    int get_current_month();
    int get_current_year();
    float getPrice();

    void upProduct_num(int product_num);
    void upProduct_name(string product_name);
    void upMargin(float margin);
    void upQuantity(int quantity);
    void upCost(float cost);
    void upMDay(int mDay);
    void upMMonth(int mMonth);
    void upMYear(int mYear);
    void upEDay(int eDay);
    void upEMonth(int eMonth);
    void upEYear(int eYear);
    void up_Pnum_counter(int counter);
    void up_current_day(int nowDay);
    void up_current_month(int nowMonth);
    void up_current_year(int nowYear);
    void upPrice(float cost, float margin);
    void setPrice(float price);
    void upNewMargin(float price, float cost);
    void fillproduct(vector<Item>& newitem);

    void current_time();
    bool check_manufacture_date(int mDay, int mMonth, int mYear);
    bool check_expired_date(int eDay, int eMonth, int eYear);
    bool check_product_num(vector <Item> newItem_record, int product_num);
    bool check_exist_product_num(vector <Item> newItem_record, int newProduct_num);
    bool check_exist_product_name(vector <Item> newItem_record, string newProduct_name);
    bool check_product_name (vector <Item> newItem_record, string& input);

    void searchbyAlpha(vector <Item> newItem, char& ch);
    void searchbyName(vector <Item> newItem, string name);
    void searchbyPnum(vector <Item> newItem, int& num);
    void binarySearch(vector <Item> arr, unsigned l, unsigned r, int num, bool& found, unsigned& i);
    void displaysearch(stack<Item> s);

    void delete_product(vector <Item>& newItem, int index);
    void expired_product(vector<Item>& newItem);
    void delete_expired_product(vector<Item>& newItem, queue <Item> newQueue);
    void displayNum(vector<Item> newItem);

    void sortbyName(vector<Item>& newItem, int size);
    void quicksort(vector<Item>& newItem, int first, int last);
    void partition(vector<Item>& v1,int first, int last, int& pivotIndex);
//    void swap(Item&x, Item&y);

}; //end class

}//end namespace



#endif // ITEM_HPP_INCLUDED
