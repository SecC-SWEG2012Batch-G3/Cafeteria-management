#include<iostream>
#include<string.h>
#include <cstdlib>
#include<vector>
#include<bits/stdc++.h>//for find() and sort() functions
using namespace std;
struct a{char soft_drinks;
        char malt;
        char hot_drinks;};
    struct menu{
        vector <float> price {6.95,5.75,7.25,8.95,4.95};
        vector <string> foods {"Doro", "xibs", "kitfo", "gomen kitfo", "kikil"};
        a drinks;}foodMenu;
void choose();
void addItems();
void showMenu();
void showUserOption();
void deleteItemOption();
void deleteOneItem();
void modifyItem();
void searchItem();
void sortItems();
int main(){
    showMenu();
    showUserOption();
 return 0;
}
void showUserOption(){
int userOption;
  cout<<"What do you want to do? \nPress:"
      <<"\n1: To add items to the menu\n2: "<<
        "To order items\n3: To delete item(s) \n4: "<<
        "To modify/edit item(s) \n5: "<<
        "To search for item(s)\n6: To sort item(s)\n7: To exit\n";
  cin>>userOption;
  switch(userOption){
  case 1:
    addItems();
    break;
  case 2:
    choose();
    break;
  case 3:
    deleteItemOption();
    break;
  case 4:
    modifyItem();
  case 5:
    searchItem();
  case 6:
    sortItems();
  case 7:
    exit(1);
    break;
  default:
    cout<<"Invalid choice!";
    break;
      }
}
void showMenu(){
     cout<<endl;
     cout<<endl;
     cout<<"         :::::::::::::::::::MENU:::::::::::::::::::\n";
     for(int i=0;i<foodMenu.foods.size();i++){
     cout<<"\n       Item "<< i << " "<<foodMenu.foods[i]	<<"             "<<foodMenu.price[i]<<" <===\n"<<endl;
}
}
void addItems(){
    ADDITEMS:
    string foodItem;
    float itemPrice;
    cout<<endl;
    cout<<"         :::::::::::::::::::ADD ITEMS:::::::::::::::::::\n";
    cout<<"Please Enter the name of the food item you want to insert:\n";
    cin>>foodItem;
    cout<<"Please enter the price for the food item: "<<foodItem<< "\n";
    cin>>itemPrice;
    foodMenu.foods.push_back(foodItem);
    foodMenu.price.push_back(itemPrice);
    cout<<"Successfully added one item to the menu!\n";
    char choice;
    cout<<"Do you want to add another item? y/n \n";
    cin>>choice;
    if(choice =='Y' || choice =='y'){
        goto ADDITEMS;
    }
    else if(choice == 'N' || choice == 'n'){
        cout<<"Thank you, your items have been added.";
        system("CLS");
        showMenu();
        showUserOption();

    }
    else {
        cout<<"Invalid choice!";
}
}
void deleteItemOption(){
    int deleteOption;
    cout<<endl;
    cout<<"         :::::::::::::::::::DELETE ITEM(S):::::::::::::::::::\n";
    cout<<"Press: \n1: To delete one item\n2: To delete the entire items\n";
    cin>>deleteOption;
    switch(deleteOption){
case 1:
    deleteOneItem();

case 2:
    foodMenu.foods.clear();
    foodMenu.price.clear();
    system("CLS");
    showMenu();
    showUserOption();
    }
}
void deleteOneItem(){
    DELETEITEM:
    int index;
    char choice;
    system("CLS");
    showMenu();
    cout<<"Enter the index of the item you want to delete:\n";
    cin>>index;
    auto elementToRemove = foodMenu.foods.begin() + index;
    auto priceToRemove = foodMenu.price.begin() + index;
    foodMenu.foods.erase(elementToRemove);
    foodMenu.price.erase(priceToRemove);
    cout<<"Successfully deleted one item!\n";
    cout<<"Do you want to delete another item? y/n\n";
    cin>>choice;
    if(choice =='Y' || choice =='y'){
        system("CLS");
        showMenu();
        goto DELETEITEM;
    }
    else if(choice == 'N' || choice == 'n'){
        cout<<"Thank you, the item(s) have been deleted.";
        system("CLS");
        showMenu();
        showUserOption();
    }
    else {
        cout<<"Invalid choice!";
}
}
void modifyItem(){
    MODIFYITEMS:
    char choice;
    int index;
    string foodItem;
    float price;
    cout<<endl;
    cout<<"         :::::::::::::::::::MODIFY ITEM(S):::::::::::::::::::\n";

    cout<<"Please enter the index of the menu you want to edit:\n";
    cin>>index;
    cout<<"Please enter the new food name:\n";
    cin>>foodItem;
    cout<<"Please enter the price for the food: "<<foodItem<< ": \n";
    cin>>price;
    foodMenu.foods.at(index) = foodItem;
    foodMenu.price.at(index) = price;
    cout<<"Successfully modified one item. Do you want to modify other items? y/n \n";
    cin>>choice;
    if(choice =='Y' || choice =='y'){
        system("CLS");
        showMenu();
        goto MODIFYITEMS;
    }
    else if(choice == 'N' || choice == 'n'){
        cout<<"Thank you, the item(s) have been modified.";
        system("CLS");
        showMenu();
        showUserOption();
    }
    else {
        cout<<"Invalid choice!";
    }
}
void searchItem(){
    string searchFood;
    int indexOfFood;
    SEARCHFORITEM:
    cout<<endl;
    cout<<"         :::::::::::::::::::SEARCH FOR ITEM(S):::::::::::::::::::\n";
    cout<<"Enter the food you want to search for: \n";
    cin>>searchFood;
    auto index = find(foodMenu.foods.begin(), foodMenu.foods.end(), searchFood);
    if(index != foodMenu.foods.end()){
        char choice;
        indexOfFood = index - foodMenu.foods.begin();
        cout<<"Element found at index: "<<indexOfFood<< " with price: "<< foodMenu.price.at(indexOfFood)<<endl;//add the food item into the output
        cout<<"Do you want to search for another item? y/n\n";
        cin>>choice;

        if(choice =='Y' || choice =='y'){
            system("CLS");
            showMenu();
            goto SEARCHFORITEM;
                }
        else if(choice == 'N' || choice == 'n'){
        cout<<"Thank you!";
        system("CLS");
        showMenu();
        showUserOption();
                }
        else {
            cout<<"Invalid choice!";
            }
    }
    else
    {
        cout<<"Element not found!\n";
        system("CLS");
        showMenu();
        showUserOption();

    }


}
void sortItems()
{
    int option;
    cout<<endl;
    cout<<"         :::::::::::::::::::SORT ITEM(S):::::::::::::::::::\n";
    cout<<"Press: \n\t1: To sort in ascending order\n\t2: To sort in descending order\n";
    cin>>option;
    if(option == 1)
    {
    sort(foodMenu.foods.begin(), foodMenu.foods.end());
    cout<<"Food menu successfully sorted in ascending order!";
    showMenu();
    showUserOption();

    }
    else if(option == 2)
    {
    sort(foodMenu.foods.begin(), foodMenu.foods.end(), greater<string>());
    cout<<"Food menu successfully sorted in descending order!";
    showMenu();
    showUserOption();
    }
    else
        cout<<"Invalid option!";
}
void choose(){
   menu food;
   int order;
   int foodAmount;
   float amountOfSales;
   vector <string> listOfOrderedFood {};
   vector <float> listOfOrderedPrice {};
   vector <float> totalPrice {};
   vector <int> amountOfFood {};
   FOODCHOICE:
    char choice;
    cout<<"\nFrom The List Of Food Items, What Would You Like?:\n";
    cin>>order;
    cout<<"\nHow Many "<< foodMenu.foods[order] <<" would You Like To Order:\n";
    cin>>foodAmount;
    amountOfSales = foodAmount * foodMenu.price[order];
    amountOfFood.push_back(foodAmount);
    listOfOrderedPrice.push_back(foodMenu.price[order]);
    listOfOrderedFood.push_back(foodMenu.foods[order]);
    totalPrice.push_back(amountOfSales);
    cout<<"Do you want another order? y/n\n";
    cin>>choice;
    switch(choice){
    case 'y':
    case 'Y':
        goto FOODCHOICE;
        break;

    case 'N':
    case 'n':
        cout<<"Thanks for visiting!\n";
        system("CLS");
        break;
    default:
        cout<<"Invalid choice\n";
        break;
    }

cout<<"You Have Ordered:\n\n";
cout<<"===========================================================\n";
cout<<left<<setw(15)<<"ITEM"<<right<<setw(11)<<"QUANTITY"<<right<<setw(15)<<"UNIT PRICE"<<right<<setw(20)<<"AMOUNT OF SALE\n";
cout<<"===========================================================";
for(int i=0;i<listOfOrderedFood.size();i++){
cout<<"\n" << listOfOrderedFood.at(i) << ":\t"<<setw(6)<<left<< amountOfFood.at(i) <<setw(16)<<right<< listOfOrderedPrice.at(i)  <<setw(20) <<right<< totalPrice.at(i)<<endl;
}
showMenu();
showUserOption();
}






