#include "progress.h"

auto print_pair = [](const auto& pair) {
    std::cout << std::endl << pair.first << " " << pair.second << '\n';
};

auto print_first = [](const auto& pair) {
    std::cout << std::endl << pair.first << '\n';
};

void progress::backup_pair() {
    std::ofstream  backup_ofstream{};
    std::string backup = "frequency.dat";
    backup_ofstream.open(backup);
    for (auto& umap : mItems) {
        backup_ofstream << umap.first << " " << umap.second << std::endl;
    }
    backup_ofstream.close();
};

void progress::check_inventory() {
    std::ifstream Input_File_ifstream{};
    
    std::string key;
    int val = 1;
    std::string file = "CS210_Project_Three_Input_File.txt";
    
    try {
        Input_File_ifstream.open(file);
        
        
        while (!Input_File_ifstream.eof()) {
            Input_File_ifstream >> key;
            if (matchKey(key)) {
                val = mItems[key];
                val = val + 1;
                mItems.insert_or_assign(key, val);
            }
            else {
                val = 1;
                mItems.insert_or_assign(key, val);
            }

        }
        Input_File_ifstream.close();
    }
    catch (std::exception msg) {
        std::cout << msg.what();
    }
}
void progress::lookup() {
    std::string query;
    std::cout << "lookup : ";
    std::cin >> query;
    if (matchKey(query)) {
        std::cout << std::endl << "Found " << mItems[query] << " ";
        std::cout << query << std::endl;
    }
    else {
        std::cout << "No matches found for " << query << std::endl;
    }
};

void progress::printList() {
    system("cls");
    for (const auto& pair : mItems) {
        print_pair(pair);
    };

    
}

void progress::printChart() {
    system("cls");
    for (auto& pair : mItems) {
        print_first(pair);
        level(pair.second);
        resetConsole();
    };
};

void progress::level(int& r_span) {
    if (r_span <= 5) {
        understocked(r_span);
    }
    else {
        overstocked(r_span);
    }
};

void progress::overstocked(int& r_span)
{


    mhConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    std::cout << " ";
    for (int i = 1; i < r_span; i++)
    {
       
        SetConsoleTextAttribute(mhConsole, mGREEN);
        std::cout << " ";
    }
    std::cout << r_span;
}

void progress::understocked(int& r_span)
{

    mhConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int i = 0; i < r_span; i++)
    {
        // windows api to set the terminal emulator color
        SetConsoleTextAttribute(mhConsole,mRED);
        std::cout << " ";
    }
    std::cout << r_span;
}

void progress::resetConsole() {
    SetConsoleTextAttribute(mhConsole, def);
}

//! displays the various console Text attributes we can apply to our STD_OUTPUT_HANDLE
void progress::test(){
    int i;
    mhConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    

    for (i = 1; i < 255; i++) {
        SetConsoleTextAttribute(mhConsole, i);
        std::cout << i << "TESTING TESTING TESTING                " << std::endl;
    }
   
}
//! returns true if our string is an existing key in our container
    /*!
      \sa matchKey()
      \param r_str the first argument.
    */
bool progress::matchKey(std::string r_str) {
    bool b = false;
    for (auto umap : mItems) {
        if (umap.first.compare(r_str) == 0) {
            b = true;
        }
    }
    return b;
}
