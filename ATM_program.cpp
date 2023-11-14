#include <iostream>
/*
this is a ATM program in C++ where you can view your balance, withdraw and deposit 
is my first program and I know is some bugs, but I want to fix it in the future
*/
double retragere(double sum);
double depunere(double sum);
double balanta = 0;

int main() {

    /// here we declar 3 variables 
    int help;
    std::string alege;
    bool run = true;

    std::string name;
    std::cout <<"Buna ziua, care este numele dvs.? \n";
    std::cin >> name;
    std::cout <<"Bun venit " << name << ". Cu ce va putem ajuta?\n";

    /// we use the variable "run" to use this app for more times without reopen it
    while (run) {
        /// in this do while loop we have 3 options when the user dont type 1-3 or type text
        do {
            std::cout <<"1.Vizualizare balanta\n";
            std::cout <<"2.Depunere\n";
            std::cout <<"3.Retragere\n";
            std::cin >> help;
        } while (help > 3 || help <= 0);
        /// here are the 3 options 
        switch (help) {
        case 1:
            /// in option 1, the program give for the user balance of the bank account
            std::cout <<"Contul dvs. are balanta " << balanta <<"$\n";
            std::cout << "Doresti sa continui?\n";
            std::cin >> alege;
            /// this make the program to run when the user say "yes". If not, the program quit
            if (alege == "da") {
                continue;
            }
            else {
                run = false;
                break;
            }
        case 2:
            /// in option 2, we can deposit money in the bank account
            depunere(balanta);
            std::cout << "Doresti sa continui?\n";
            std::cin >> alege;
            if (alege == "da") {
                continue;
            }
            else {
                run = false;
                break;
            }
        case 3:
            /// in option 3, we can withdraw money 
            retragere(balanta);
            std::cout << "Doresti sa continui?\n";
            std::cin >> alege;
            if (alege == "da") {
                continue;
            }
            else {
                run = false;
                break;
            }
        }
    }
    return 0;
}

double retragere(double sum) {
    /*
    this function is for withdraw
    here is the check if the balance is big enough or not
    */
    double retrag;
    std::cout << "Ce suma vreti sa retrageti? \n";
    std::cin >> retrag;

    if (sum < retrag) {
        std::cout << "Fonduri insuficiente!\n";
    }
    else if (sum >= retrag) {
        sum -= retrag;
        balanta = sum;
        std::cout << "Balanta dumneavoastra acum este: " << sum << "$\n";
    }
    else {
        std::cout << "Introduceti numere! \n";
    }
    return 0;
}

double depunere(double sum) {
    /*
    this function is for deposit
    here is the check if the deposit is not 0 or smaller
    */
    double depun;
    std::cout << "Ce suma doriti sa depuneti? \n";
    std::cin >> depun;
    
    if (depun < 0) {
        std::cout << "Nu putem adauga suma aceasta";
    }
    else {
        sum += depun;
        balanta = sum;
        std::cout << "Depunere incheiata. Balanta ta este acum: " << sum << "$\n";
    }

    return 0;
}

