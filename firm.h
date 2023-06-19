
#ifndef FIRM_H
#define FIRM_H

#include <iostream>
#include <random>
#include <vector>
#include <fstream>

using namespace std;

class Firm {
public:
    int firm_id;
    double alpha;
    double beta;
    int labour;
    int capital;

    Firm() {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> random_firm_id_generator(2000000, 9000000);
        firm_id = random_firm_id_generator(gen);
        capital = (firm_id / 100000)+ 30;
        labour = (firm_id % 1000)+25;
        // Calculate alpha and beta.
        alpha = (firm_id % 10) / 10.0f;
        beta = 1 - alpha;
    }

    int get_firmID() const {
        return firm_id;
    }

    // Remove the `elasticities()` function.

    double production() {
        // Calculate the output.
        double output = pow(labour, alpha) * pow(capital, beta);
        // Print the output.
        /*cout << "K: " << capital << " L: " << labour << endl;
        cout << "output: " << output << endl;*/
        return output;
    }

    void print_info() {
        // Print the firm information.
        cout << "Firm_" << firm_id << endl;
        cout << "Alpha: " << alpha << endl;
        cout << "Beta: " << beta << endl;
        cout << "Capital: " << capital << endl;
        cout << "Labour: " << labour << endl;
    }

    void update() {
        labour += (rand() % 50) - 27;
        capital += (rand() % 20) - 7;
    }

    void write_to_csv(std::ofstream& csv_file) {
        csv_file << firm_id << "," <<std::to_string(production()) << endl;
    }
};

#endif


