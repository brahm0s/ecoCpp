#include "household.h"
#include "firm.h"
#include<vector>
#include<iostream>


int main(){
        const int NUM_HOUSE = 8;
        vector<House> houses(NUM_HOUSE);

        for(auto& h: houses ){
            h.print_info();
        }
        const int NUM_FIRMS = 5;

    // Create a vector of firms.
    vector<Firm> firms(NUM_FIRMS);

    // Create a text file.
    ofstream output_file("output.csv");
            output_file << "FirmID,output" << endl;

    // Write the output of the code to the text file.
    for (int day = 0; day < 100; day++){
        for (auto& firm : firms) {
            firm.update();
            firm.production();
            firm.write_to_csv(output_file);
            
        }
    }

    // Close the text file.
    output_file.close();
    return 0;




    }
