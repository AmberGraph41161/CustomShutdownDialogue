#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits>
#include <string>
#include <cstdlib>
#include <Functions.h>

std::string LineSkipRead(int line, int skip);
std::string spacecreator(int x);
std::string getcomment();
int getchoice();
void StartLogo();
void pauseclear();
void SCG();
void prompt();
void chooseprompt();
void checkfiles();
void CaseExecuter(int x);
void changecomment();
void editdirectory();
void resetsavedata();



void pauseclear(){
    system("pause");
    system("cls");
}

void SCG()
{
    system("color 2");
}

void checkfiles()
{
    std::cout << "Checking files..." << std::endl;
    std::fstream STARTLOGOtxt("StartLogo.txt", std::fstream::in);
    std::fstream CSDSAVEDATAtxt("CSDsavedata.txt", std::fstream::in);
    ///STARTLOGOtxt
    if(STARTLOGOtxt.fail())
    {
        std::cerr << "Error opening \"StartLogo.txt\"" << std::endl;
        std::cerr << "Terminating program..." << std::endl;
        exit(1);
    } else {
        std::cout << "Success opening \"StartLogo.txt\"" << std::endl;
        STARTLOGOtxt.close();
    }
    ///CSDSAVEDATAtxt
    if(CSDSAVEDATAtxt.fail())
    {
        std::cerr << "Error opening \"CSDsavedata.txt\"" << std::endl;
        std::cerr << "Terminating program..." << std::endl;
        exit(1);
    } else {
        std::cout << "Success opening \"CSDsavedata.txt\"" << std::endl;
        CSDSAVEDATAtxt.close();
    }
    std::cout << "All files checked" << std::endl;
    pauseclear();
}

void prompt()
{
    ///Open file
    std::string outstring;
    std::string commentoutstring;
    std::fstream SaveDataOut("CSDsavedata.txt", std::fstream::in);
    if(SaveDataOut.fail())
    {
        std::cerr << "Error Opening \"CSDsavedata.txt\"" << std::endl;
        std::cerr << "Terminating Program..." << std::endl;
        exit(1);
    }
    ///Open file^^^


    ///comment get
    SaveDataOut.clear();
    SaveDataOut.seekg(0, std::ios_base::beg);
    std::getline(SaveDataOut, commentoutstring);
    ///comment get^^^

    ///Load savedata
    std::cout << "Loaded from saved data" << "\n\n";
    std::cout << "---------------------------------------------" << "\n\n";
    std::cout << "\"Comment\" = " << commentoutstring << "\n\n";
    while(!SaveDataOut.eof()){
        std::getline(SaveDataOut, outstring);
        std::cout << outstring << std::endl;
    }
    std::cout << "~Enter \"6\" to change comment" << std::endl;
    std::cout << "~Enter \"7\" to edit directory" << std::endl;
    std::cout << "~Enter \"8\" to reset saved data to detault" << std::endl;
    std::cout << "~Enter \"9\" to terminate shutdown" << std::endl;
    std::cout << "~Enter \"0\" to terminate program" << "\n\n";
    std::cout << "---------------------------------------------" << std::endl;
    ///Load savedata^^^


    SaveDataOut.clear();
    SaveDataOut.close();
}

///USERINPUT AND INPUT CHECKER
void CaseExecuter(int x)
{
    std::string systemstring;
    int y = x + 1;
    systemstring = LineSkipRead(y, 2);
    systemstring += " \"" + getcomment() + "\"";
    system(systemstring.c_str());
    system("cls");
    prompt();
}
void chooseprompt()
{

    int userchoice;
    userchoice = getchoice();
    switch(userchoice)
    {
        case 1:
            CaseExecuter(1);
            break;
        case 2:
            CaseExecuter(2);
            break;
        case 3:
            CaseExecuter(3);
            break;
        case 4:
            CaseExecuter(4);
            break;
        case 5:
            CaseExecuter(5);
            break;
        case 6:
            changecomment();
            break;
        case 7:
            editdirectory();
            break;
        case 8:
            resetsavedata();
            break;
        case 9:
            std::cout << "Terminating shutdown processes..." << std::endl;
            system("shutdown -a");
            pauseclear();
            prompt();
            break;
        case 0:
            std::cout << "Terminating program..." << std::endl;
            pauseclear();
            exit(1);
            break;
        default:
            std::cerr << "An unknown error has occurred..." << std::endl;
            std::cerr << "Terminating program..." << std::endl;
            pauseclear();
            exit(1);
            break;
    }
}

int getchoice()
{
    int x;

    std::cout << ">";
    std::cin >> std::setw(1) >> x;
    while(std::cin.good() == false)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input, please try again..." << std::endl;
        pauseclear();
        prompt();
        std::cout << ">";
        std::cin >> std::setw(1) >> x;
    }
    while(x > 9)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input, please try again..." << std::endl;
        pauseclear();
        prompt();
        std::cout << ">";
        std::cin >> std::setw(1) >> x;
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return x;
}
///USERINPUT AND INPUT CHECKER ^^^^^^^^^

std::string LineSkipRead(int line, int skip)
{
    std::string outstring;
    std::fstream readlineskip("CSDsavedata.txt", std::fstream::in);
    if(readlineskip.fail())
    {
        std::cerr << "Error Opening \"CSDsavedata.txt\"" << std::endl;
        std::cerr << "Terminating Program..." << std::endl;
        exit(1);
    }
    readlineskip.clear();
    for(int x = 1; x <= line - 1; x++){
        std::getline(readlineskip, outstring);
    }
    readlineskip.ignore(skip);
    std::getline(readlineskip, outstring);


    return outstring;
}


void changecomment()
{
    int commentinlength;
    int spacelength;
    std::string commentin;
    std::fstream commentchanger("CSDsavedata.txt");
    if(commentchanger.fail())
    {
        std::cerr << "Error Opening \"CSDsavedata.txt\"" << std::endl;
        std::cerr << "Terminating Program..." << std::endl;
        exit(1);
    }
    ///"The maximum length of the comment is 512 characters." Going to set at 34 chars as each line is 34
    std::cout << "Comment has a maximum of 34 characters" << std::endl;
    std::cout << "Exceeding this limit will result in a blank comment" << std::endl;
    std::cout << "New comment: ";
    std::cin >> std::setw(34) >> commentin;

    commentchanger.seekg(0, std::ios::beg);
    commentinlength = commentin.length();
    spacelength = 34 - 1 - commentinlength;
    commentchanger << commentin << spacecreator(spacelength);

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    commentchanger.close();

    pauseclear();
    prompt();
}

std::string spacecreator(int x)
{
    std::string outstring;
    for(int y = 0; y <= x; y++)
    {
        outstring += " ";
    }
    return outstring;
}

std::string getcomment()
{
    std::string outstring;
    std::fstream commentget("CSDsavedata.txt", std::fstream::in);
    if(commentget.fail())
    {
        std::cerr << "Error Opening \"CSDsavedata.txt\"" << std::endl;
        std::cerr << "Terminating Program..." << std::endl;
        exit(1);
    }
    commentget.seekg(0, std::ios::beg);
    std::getline(commentget, outstring);
    commentget.seekg(0, std::ios::beg);

    commentget.close();
    return outstring;
}

void editdirectory()
{
    std::string suffix;
    std::string suffixout;
    std::string lineasstring;
    int line;
    int type;
    int time;
    int timeout;
    int reason1 = 00;
    int reason2 = 00;

    std::string outstring;
    std::fstream EDIT("CSDsavedata.txt");
    if(EDIT.fail())
    {
        std::cerr << "Error Opening \"CSDsavedata.txt\"" << std::endl;
        std::cerr << "Terminating Program..." << std::endl;
    }

    ///LINE
    std::cout << "Edit line: ";
    std::cin >> std::setw(1) >> line;
    while(std::cin.good() == false || line >= 6 || line == 0)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        system("cls");
        prompt();
        std::cout << "Invalid input, please try again..." << std::endl;
        std::cout << "Edit line: ";
        std::cin >> std::setw(1) >> line;
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    ///TYPE
    std::cout << "1 -s" << std::endl;
    std::cout << "2 -r" << std::endl;
    std::cout << "3 -i" << std::endl;
    std::cout << "Type: ";
    std::cin >> std::setw(1) >> type;
    while(std::cin.good() == false || type >= 4 || type == 0)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        system("cls");
        prompt();
        std::cout << "Invalid input, please try again..." << std::endl;
        pauseclear();
        prompt();
        std::cout << "Edit line: " << line << std::endl;
        std::cout << "1 -s (self)" << std::endl;
        std::cout << "2 -r (restart)" << std::endl;
        std::cout << "3 -i (remote shutdown)" << std::endl;
        std::cout << "Type: ";
        std::cin >> std::setw(1) >> type;
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if(type != 3)
    {
        ///user input for time
        std::cout << "Entered time is limited to 3 digits" << std::endl;
        std::cout << "Enter time: ";
        std::cin >> std::setw(3) >> time;
        while(std::cin.good() == false || time > 999)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            system("cls");
            prompt();
            std::cout << "Invalid input, please try again..." << std::endl;
            pauseclear();
            prompt();
            std::cout << "Edit line: " << line << std::endl;
            std::cout << "1 -s (self)" << std::endl;
            std::cout << "2 -r (restart)" << std::endl;
            std::cout << "3 -i (remote shutdown)" << std::endl;
            std::cout << "Type: " << type << std::endl;
            std::cout << "Entered time is limited to 3 digits" << std::endl;
            std::cout << "Enter time: ";
            std::cin >> std::setw(3) >> time;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }


    switch(type)
    {
        case 1:
            ///s
            ///MAKE SURE TIME INT IS SET WITH 0 SUFIXES
            if(time > 99)
            {
                suffix = std::to_string(time);
                suffixout = suffix;
            } else if(time > 9 && time < 100)
            {
                suffix = std::to_string(time);
                suffixout = "0" + suffix;
            } else if(time >= 0 && time < 10)
            {
                suffix = std::to_string(time);
                suffixout = "00" + suffix;
            }
            ///GET TO LINE AND WRITE
            ///note to self: DO NOT FORGET THAT AN "ENTER" IS "\N" THEREFORE 2 CHARACTERS LONG
            EDIT.seekg((34 * (line)), std::ios::beg);
            EDIT.seekg(line * 2, std::ios::cur);
            lineasstring = std::to_string(line);
            EDIT << lineasstring + " shutdown -s -t " + suffixout + " -d p:00:00 -c";
            EDIT.seekg(0, std::ios::beg);
            EDIT.close();
            pauseclear();
            prompt();
            break;
        case 2:
            ///r
            ///MAKE SURE TIME INT IS SET WITH 0 SUFIXES
            if(time > 99)
            {
                suffix = std::to_string(time);
                suffixout = suffix;
            } else if(time > 9 && time < 100)
            {
                suffix = std::to_string(time);
                suffixout = "0" + suffix;
            } else if(time >= 0 && time < 10)
            {
                suffix = std::to_string(time);
                suffixout = "00" + suffix;
            }
            ///GET TO LINE AND WRITE
            ///note to self: DO NOT FORGET THAT AN "ENTER" IS "\N" THEREFORE 2 CHARACTERS LONG
            EDIT.seekg((34 * (line)), std::ios::beg);
            EDIT.seekg(line * 2, std::ios::cur);
            lineasstring = std::to_string(line);
            EDIT << lineasstring + " shutdown -r -t " + suffixout + " -d p:00:00 -c";
            EDIT.seekg(0, std::ios::beg);
            EDIT.close();
            pauseclear();
            prompt();
            break;
        case 3:
            ///i
            ///GET TO LINE AND WRITE
            ///note to self: DO NOT FORGET THAT AN "ENTER" IS "\N" THEREFORE 2 CHARACTERS LONG
            EDIT.seekg((34 * (line)), std::ios::beg);
            EDIT.seekg(line * 2, std::ios::cur);
            lineasstring = std::to_string(line);
            EDIT << lineasstring + " shutdown -i" << "                     ";
            EDIT.seekg(0, std::ios::beg);
            EDIT.close();
            pauseclear();
            prompt();
            break;
        default:
            std::cerr << "An unknown error has occurred..." << std::endl;
            std::cerr << "Terminating program..." << std::endl;
            pauseclear();
            exit(1);
            break;
    }
}

void resetsavedata()
{
    std::string outstring;
    std::fstream resetdataread("CSDsavedataDEFAULT.txt", std::fstream::in);
    std::fstream resetdatawrite("CSDsavedata.txt", std::fstream::out);
    if(resetdataread.fail())
    {
        std::cerr << "Error Opening \"CSDsavedataDEFAULT.txt\"" << std::endl;
        std::cerr << "Terminating Program..." << std::endl;
        exit(1);
    }
    if(resetdatawrite.fail())
    {
        std::cerr << "Error Opening \"CSDsavedata.txt\"" << std::endl;
        std::cerr << "Terminating Program..." << std::endl;
        exit(1);
    }
    resetdataread.seekg(0, std::ios::beg);
    resetdatawrite.seekg(0, std::ios::beg);
    while(!resetdataread.eof())
    {
        std::getline(resetdataread, outstring);
        outstring += "\n";
        resetdatawrite << outstring;
    }
    resetdataread.close();
    resetdatawrite.close();
    pauseclear();
    prompt();
}

void StartLogo(){
    std::string outstring;
    std::fstream StartLogoOut("StartLogo.txt", std::fstream::in);

    if(StartLogoOut.fail()){
        std::cerr << "Error Opening \"StartLogo.txt\"" << std::endl;
        std::cerr << "Terminating Program..." << std::endl;
        exit(1);
    }
    while(!StartLogoOut.eof()){
        std::getline(StartLogoOut, outstring);
        std::cout << outstring << std::endl;
    }
    StartLogoOut.close();
}
