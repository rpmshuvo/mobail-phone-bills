#include<iostream>
#include<fstream>
#include <vector>
#include <ctime>
#include <sstream>
#include <iomanip>
#include<cstdlib>
#include <numeric>
#include <cmath>
#include <stdlib.h>
#include <dos.h>
#include <conio.h>
#include <windows.h>
#include <algorithm>
#include <cctype>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define tostr( x ) dynamic_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

using namespace std;
class call{   //call class
    private:
        double amount; //amount variable
        string number; //number variable

        int ps; // rate per second
    public:

        void caller(double a,string n){ //call er function to assign variable value
            amount=a;
            number=n;
            }
        void setps(int a){ //setter por ps
            ps=a;
            }
        int getps(){ //getter for ps
            return ps;
            }
        void setnumber(string n){ //setter
        number=n;}
        string getnumber(){ //getter
            return number;
            }
        int getamount(string fn){ //getter for amount
            string cca=fn+"_cb.txt";
                     int a=amfile(cca);
            }

        void setamount(string b,int a){ //setter for amount
            amwr(b,a);
            }
        bool is_digits(const std::string &str)
{   if(str.size() >=6  && str.size()<=11)
    return str.find_first_not_of("0123456789") == std::string::npos;
    else
        return false;
}
        void makecall(string fn){ //makes call
                    /*int aa=getamount(fn);
                    cout<<aa;
                   if(/*getamount(fn)aa>=0false)
                   { */
                        string s;

                        cout<<"Input Number to Call"<<endl;
                        cin>>s;
                        if(is_digits(s)==1){
                        setnumber(s);

                        string cc=fn+"_cn.txt";
                        writefile(cc,tostr(s));

                        callcost(gettd(fn,tostr(s)),fn);
                        cout<<endl;}
                        else{
                    cout<<"Invalid Input"<<endl;
                    makecall(fn);
                  }
                        /*cout<<"Press 1 to Make another Call or 2 to Proceed"<<endl;

                        int c;
                        cin>>c;

                        if(c==1)
                            {
                            makecall(fn);}
                        else{
                            bm();}*/

                        //    p3.bm();
                  }

                  /* else{
                        cout<<"Balance 0 ,Input Balance"<<endl;
                        int b11;
                        cin>>b11;
                        amwr(fn,b11);
                        makecall(fn);
                        }*/


           //  }

             double td(string fn,string cn) //timw calculation
                        {
                            time_t currentTime;
                            struct tm *localTime;

                            time( &currentTime );                   // Get the current time
                            localTime = localtime( &currentTime );  // Convert the current time to the local time

                            const int Day    = localTime->tm_mday;
                            const int Month  = localTime->tm_mon + 1;
                            const int Year   = localTime->tm_year + 1900;
                            const int Hour   = localTime->tm_hour;
                            const  int Min    = localTime->tm_min;
                            const int Sec    = localTime->tm_sec;
                            cout << "Call Started on " << Hour << ":" << Min << ":" << Sec<<" ";

                            srand(time(0));
                            int r = rand() % (60 - 10) + 2;
                            double a=(double)r;
                            string tht=tostr(cn)+" "+tostr(Day)+"/"+tostr(Month)+"/"+tostr(Year)+" "+tostr(Hour)+":"+tostr(Min)+":"+tostr(Sec)+
                            " # "+ tostr(a) ;
                            cout <<Day << "/" << Month << "/" << Year << endl;

                            string ct=fn+"_ct.txt";

                            writefile(ct,tht);
                            cout <<fixed;
                            cout<<setprecision(1)<<"Call Duration :"<<a<<"M"<<endl;
                            string cd=fn+"_cd.txt";
                            writefile(cd,tostr(a));
                            return a;
                            }
        int gettd(string fn,string cn){ //getter
                return td(fn,cn);
                }


        void setcost(){
                cout<<"Input Call Cost for per Second :"; //setter
                    int a;
                    cin>>a;
                    setps(a);

                }
        void callcost(double b,string fn){ //callcost
                double a,c;
                //a=getps();
                a=3;


                c=a*b;
                cout<<"Total Cost Of your call :"<<c<<" Taka. To  the number :"<<getnumber()<<endl;
                setamount(fn,(getamount(fn)-c));
                }
                  void writefile (string fn,string tx) {
     ofstream myfile(fn.c_str(), ofstream::out | ofstream::app);


 //myfile.open(fn.c_str());
  myfile <<tx<<"\n";
    }
    void amwr(string fn,int tx){     //calling amount
            string a=fn+"_am.txt";
            ofstream myfile(a.c_str(), ofstream::out);
            myfile << tx;
     }

    int amfile(string fn)
        {   string b=fn+"_am.txt";
        int cc;
            ifstream r(b.c_str());
        int in_ints[1];
        r.read((char*)&in_ints, sizeof(in_ints));
        for( int i = 0; i <1; i++) {
            cc= in_ints[i];
        }
        return cc;}
void readfile(string fn)//reads file
        {
            string line;
            ifstream myfile (fn.c_str());
            if (myfile.is_open())
            {
            while ( getline (myfile,line) )
            {
              cout << line << '\n';
            }
            myfile.close();
          }
            else cout << "Unable to open file";
      }
void mostcalled(string fn){ //detects most called number
    ifstream in(fn.c_str());

    if(!in){
        cerr << "Could not open file.txt.";

    }

    string str, str2, strn, tab[10000], tab2[10000];
    int i, k, j, n, l, tabl;
    char c = 179;
    vector<int> tabs;
    vector<string> stringi;

    while(getline(in, str2)){
        str += str2;
        str += ' ';
    }
    k = 0;
    for(i = 0; i < str.length(); i++){
        if(str[i] != ' ' && str[i] != '.' && str[i] != '\t' && str[i] != ','
           && str[i] != ';' && str[i] != ':' && str[i] != '}' && str[i] != '{'){
            tab[k] += tolower(str[i]);
        }else{
            k++;
        }
        if(str[i] == '.' || str[i] == '\t' || str[i] == ',' || str[i] == ';'
        || str[i] == ':' || str[i] == '}' || str[i] == '{') {
            k--;
        }
    }
    tabl = k;

    k = 0;
    for(i = 0; i < tabl; i++){
        for(j = 0; j < tabl; j++){
            if(tab[i] == tab[j]){
                k++;
            }
        }
        tabs.push_back(k);
        k = 0;
    }
    for(i = 0; i < tabl; i++){
        for(j = 0; j < tabl-1; j++){
            if(tab[j] < tab[j+1]){
                n = tabs.at(j);
                tabs.at(j) = tabs.at(j+1);
                tabs.at(j+1) = n;
                strn = tab[j];
                tab[j] = tab[j+1];
                tab[j+1] = strn;
            }
        }
    }
    for(i = 0; i < tabl; i++){
        for(j = 0; j < tabl-1; j++){
            if(tabs.at(j) < tabs.at(j+1)){
                n = tabs.at(j);
                tabs.at(j) = tabs.at(j+1);
                tabs.at(j+1) = n;
                strn = tab[j];
                tab[j] = tab[j+1];
                tab[j+1] = strn;
            }
        }
    }
    tab2[0] = tab[0];
    for(i = 0; i < tabl; i++){
        if(tab[i] != tab[i+1]){
            tab2[i] = tab[i+1];
        }
    }
    k = 1;
    l++;
    for(i = 0; i < tabl; i++){
        if(!tab2[i].empty()){
            l++;
        }
    }

    for(i = 0; i < 1; i++){
        if(!tab2[i].empty() && k <= 20 ){
            cout<< "Number"<<tab2[i]<< "  Times :" <<
            tabs.at(i+1)<<endl;
        }
    }

}
void cdavg(string fn){
int totalNumbers = 0;
    float sum = 0, avg = 0, n;

    stringstream ss;


    ifstream inputFile(fn.c_str());

    try {if (inputFile) {
        while (inputFile) {
            getline(inputFile, fn);
            ss.clear(); ss.str(fn);
            while (ss >> n) {
                ++totalNumbers;
                sum += n;
            }
        }
        inputFile.close();

        avg = sum / totalNumbers;
        cout << "number of numbers is " << totalNumbers << endl;
        //cout << "the sum of the numbers is " << sum << endl;
        cout << "the average of the numbers is " << avg << endl;
    }}
     catch (std::ifstream::failure e) {
    std::cerr << "Exception opening/reading/closing file\n";
  }

}

void callhistory(int sn){ //saves call history
   string a=tostr(sn)+"_ct";
   readfileline(a);

}
void readfileline(string fn){ //reads file line by line
    ifstream in(fn.c_str());

  if(!in) {
    cout << "Cannot open input file.\n";

  }

  char str[255];

  while(in) {
    in.getline(str, 255);  // delim defaults to '\n'
    if(in) cout << str << endl;
  }

  in.close();


}

   };
class mes1 { //abstact class
public:
  virtual void sendme() = 0;
};
class mclass :public mes1{ //derived class
    public:
void sendme(){ //reads meassage input
    cout<<"Type Your Message Below"<<endl;
char input[160];
cin.getline(input,sizeof(input));
}
};

class phone{ //phone class
private :
    string pnumber;

public :
    phone(string n){
    pnumber=n;}

    string getname(){
        return pnumber;}
    void setname(string a){
        pnumber=a;
    }
    };
class person{ //person class


private :
    string pname;

public:

    int validate(char *buf)
{
    int i;
    for(i=0; i< strlen(buf); ++i)
        if(!isalpha(buf[i]))     // missing index
            return 0;
        return 1;
}
    vector<string> regn; //saves registerd phone numbers
    void setpname(string a){
    pname =a;}
    string getname(){
    return pname;}
    void simreg(){

        char a[50];
    cout<<"Please Input your name to Register :"<<endl;
    cin>>a;
    if(validate(a)==1)
        in(a);
    else{
        cout<<"invalid Input"<<endl<<"Input again"<<endl ;
    simreg();
    }

    }







    void writefile (string fn,string tx) { //write files
   ofstream myfile(fn.c_str(), ofstream::out | ofstream::app);
  myfile << tx;
    }
    void writeint (string fn,int tx) { //write numbers
   ofstream myfile(fn.c_str(), ofstream::out);
  myfile << tx;
    }

  void readfile(string fn) { //reads file
    string line;
    ifstream myfile (fn.c_str());
    if (myfile.is_open())
    {
    while ( getline (myfile,line) )
    {
      cout << line << '\n';
    }
    myfile.close();
  }
    else cout << "Unable to open file";
}
void bm(){ //back to menu
    cout<<"press < m > to go to menu"<<endl;
    char mm;
    cin>>mm;
    if(mm=='m'){
            load();
        menu();
    }
    else{
        cout<<"Invalid Input"<<endl;
        cout<<"Try again"<<endl;
        bm();

    }
    }
bool is_digits(const std::string &str)
{   if(str.size() >=6  && str.size()<=11)
    return str.find_first_not_of("0123456789") == std::string::npos;
    else
        return false;
}
void in(string a){ //number input to register
    int n,p;
    int d;
    string c;
    cout<<"Input Number to Register to your Name"<<endl;
    cin>>c;
    if(is_digits(c)==1){

    regn.push_back(c);}
    else{
        cout<<"Invalid Input"<<endl;
        Sleep(300);
        in(a);
    }
    cout<<"Press 1 to Register another number to 2 to quit"<<endl;
    cin>>d;
    if(d==1)
        in(a);
    else
    {

            for(int b=0;b<regn.size();++b){
                cout<<"Your Registered Number of Sim "<<b+1<<" : "<<regn[b]<<endl;

            }
            //system("cls");
            bm();
            system("cls");

    }


    setpname(a);
    writefile("regn.txt",a);}
    void caller(){ //call dialer



       cout<<"Select Sim to CaLL "<<endl;
       string su;
       su="_am.txt";
       for(int b=0;b<regn.size();++b){
            int c=b+1;
                cout<<"Press "<<c<<"for sim "<<c<<endl;

                writeint(tostr(c)+su,0);
            }
         int s;
         cin>>s;
         if(s>=1&& s<=regn.size()){
        cout<<"Your selected sim number is "<<s<<endl;
        string ts=tostr(s);
       call c1;


       c1.makecall(ts);}
       else {
        cout<<"Invalid Input"<<endl;
        caller();
       }

    }
  /*  void callhistory(int sn){
   string a=tostr(sn)+"_ct";
   readfileline(a);

}*/
void hall(){ //history all
   ifstream file("1_ct.txt");
    string str;
    while (getline(file, str))
    {
        cout<<str<<endl;
    }


}
void mostcalled(){ //most call file save
    string fn="1_cn.txt";
    ifstream in(fn.c_str());

    if(!in){
        cerr << "Could not open file.txt.";

    }

    string str, str2, strn, tab[10000], tab2[10000];
    int i, k, j, n, l, tabl;
    char c = 179;
    vector<int> tabs;
    vector<string> stringi;

    while(getline(in, str2)){
        str += str2;
        str += ' ';
    }
    k = 0;
    for(i = 0; i < str.length(); i++){
        if(str[i] != ' ' && str[i] != '.' && str[i] != '\t' && str[i] != ','
           && str[i] != ';' && str[i] != ':' && str[i] != '}' && str[i] != '{'){
            tab[k] += tolower(str[i]);
        }else{
            k++;
        }
        if(str[i] == '.' || str[i] == '\t' || str[i] == ',' || str[i] == ';'
        || str[i] == ':' || str[i] == '}' || str[i] == '{') {
            k--;
        }
    }
    tabl = k;

    k = 0;
    for(i = 0; i < tabl; i++){
        for(j = 0; j < tabl; j++){
            if(tab[i] == tab[j]){
                k++;
            }
        }
        tabs.push_back(k);
        k = 0;
    }
    for(i = 0; i < tabl; i++){
        for(j = 0; j < tabl-1; j++){
            if(tab[j] < tab[j+1]){
                n = tabs.at(j);
                tabs.at(j) = tabs.at(j+1);
                tabs.at(j+1) = n;
                strn = tab[j];
                tab[j] = tab[j+1];
                tab[j+1] = strn;
            }
        }
    }
    for(i = 0; i < tabl; i++){
        for(j = 0; j < tabl-1; j++){
            if(tabs.at(j) < tabs.at(j+1)){
                n = tabs.at(j);
                tabs.at(j) = tabs.at(j+1);
                tabs.at(j+1) = n;
                strn = tab[j];
                tab[j] = tab[j+1];
                tab[j+1] = strn;
            }
        }
    }
    tab2[0] = tab[0];
    for(i = 0; i < tabl; i++){
        if(tab[i] != tab[i+1]){
            tab2[i] = tab[i+1];
        }
    }
    k = 1;
    l++;
    for(i = 0; i < tabl; i++){
        if(!tab2[i].empty()){
            l++;
        }
    }

    for(i = 0; i < 1; i++){
        if(!tab2[i].empty() && k <= 20 ){
            cout<< tab2[i]<< "  " <<
            tabs.at(i+1)<<endl;
        }
    }

}
void cdavg(){ //call duration average
    string fn="1_cd.txt";
int totalNumbers = 0;
    float sum = 0, avg = 0, n;

    stringstream ss;


    ifstream inputFile(fn.c_str());

    if (inputFile) {
        while (inputFile) {
            getline(inputFile, fn);
            ss.clear(); ss.str(fn);
            while (ss >> n) {
                ++totalNumbers;
                sum += n;
            }
        }
        inputFile.close();
        avg = sum / totalNumbers;
        cout << "number of Total call is " << totalNumbers << endl;
        //cout << "the sum of the numbers is " << sum << endl;
        cout << "the average average duration of all call is " << avg << endl;
    } else {
        cout << "Error opening file.\n";
    }

}
void tamt(){ //tomal amount cost
    string fn="1_cd.txt";
int totalNumbers = 0;
    float sum = 0, avg = 0, n;

    stringstream ss;


    ifstream inputFile(fn.c_str());

    if (inputFile) {
        while (inputFile) {
            getline(inputFile, fn);
            ss.clear(); ss.str(fn);
            while (ss >> n) {
                ++totalNumbers;
                sum += n;
            }
        }
        inputFile.close();

       cout<<"Total Call cost "<<sum<<"TK"<<endl;
    } else {
        cout << "Error opening file.\n";
    }

}
void load(){ //loading bar
        system("color 0a");

         cout<<"\n\n\n\t\t\t\tLoading Menu\n\n";
         char a=177, b=219;
         cout<<"\t\t\t\t";
         for (int i=0;i<=4;i++)
         cout<<a;
         cout<<"\r";
         cout<<"\t\t\t\t";
         for (int i=0;i<=4;i++)
         {
          cout<<b;
          for (int j=0;j<=1e8;j++);
         }


}



void mese(){

    mclass mc1;

        cout<<"Select sim To send Message"<<endl;
        for(int b=0;b<regn.size();++b){
                    int c=b+1;
                        cout<<"Press "<<c<<" for sim "<<c<<endl;


                    }

        int snm;
        cin>>snm;
        if(snm>=1&& snm<=regn.size()){
        cout<<"Enter receivers Number"<<endl;
        string an,m2;
        cin>>an;
         if(is_digits(an)==1){
          cin.ignore();
        mc1.sendme();
        /*cout<<"Type Your Message Below"<<endl;
        char input[160];
        cin.getline(input,sizeof(input));*/
        cout <<"A Message has been sent From sim "<<snm<<" to "<<an<<endl;
        cout<<"Charged tk 1"<<endl;}

    else{
        cout<<"Invalid Input"<<endl;
        Sleep(300);
        mese();
    }}
    else
    {
        cout<<"Invalid Input"<<endl;
        mese();
    }

        }
    void menu(){
             system ("CLS");
             cout<<"-----------------------------------"<<endl;
             cout<<"----------------MENU---------------"<<endl;
             cout<<"-----------------------------------"<<endl;
             cout<<"1)Make Call"<<endl;
             cout<<"2)Send Message"<<endl;
             cout<<"3)Registered sim list"<<endl;
             cout<<"4)call Logs"<<endl;
             cout<<"5)Total Call cost"<<endl;
             cout<<"6)Most often Called"<<endl;
             cout<<"7)Average length"<<endl;
             cout<<"Enter choice"<<endl;
            int choice;

            cin>>choice;
            cin.ignore();
             switch(choice){

                case 1: caller();
                            bm();
                            break;
                case 2:mese();
                            bm();
                            break;
                case 3:   for(int b=0;b<regn.size();++b){
                            cout<<"Your Registered Number of Sim "<< b+1<<" : "<<regn[b]<<endl;

                        }
                        bm();
                        break;
                case 4: hall();
                           bm();
                            break;
                case 5: tamt();
                           bm();
                            break;
                case 6: mostcalled();
                           bm();
                            break;
                case 7: cdavg();
                           bm();
                           break;
                default:
                    cout<<"Invalid Input,Input again"<<endl;

                    Sleep(300);
                    menu();


            }



             }


};

int main()
{
         system("color 0a");//sets loader color
         cout<<"\n\t\t\t"<<"    Wellcome to Mobile Phone Bills APP \n\n";
         cout<<"\n\n\n\t\t\t\tPlease wait while loading\n\n";
         char a=177, b=219;
         cout<<"\t\t\t\t";
         for (int i=0;i<=23;i++)
         cout<<a;
         cout<<"\r";
         cout<<"\t\t\t\t";
         for (int i=0;i<=23;i++)
         {
          cout<<b;
          for (int j=0;j<=1e8;j++);
         }
         cout<<endl;
         //system("cls");
         person p1;

            p1.simreg();


 return 0;
}




