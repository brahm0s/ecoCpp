#ifndef HOUSEHOLD_H
#define HOUSEHOLD_H

#include<vector>
#include<random>
#include<iostream>

using namespace std;

class House {
private:
    int working_labour;
    int wage;
    int house_id;
    int wealth;
    int  utility;
    float saving;
    

public:
  House()  {random_device rd;
mt19937 gen(rd());

uniform_int_distribution<> dis_houseid(20000,30000);
uniform_int_distribution<> dis_wage(120,7000);

house_id = dis_houseid(gen);

wage = dis_wage(gen);

wealth = (house_id/1000)* wage;
utility = 0;
saving = 0;


    }

    void work(){
        working_labour = (rand()% 100)+ 10;
        int income = working_labour*wage;
        saving = 0.2 * income;
        }

    void consume(){
        int consumption = (rand() % 100)+1;
        wealth -= consumption; 
    }

    void update(){
        work();
        consume();
    }

    void print_info(){
        cout << "House_" << house_id << endl;
        cout << "wage:" << wage << endl;
        cout << "Wealth:"<< wealth<<endl;
        cout << "saving:" << saving << endl;
    }
 


};


#endif

