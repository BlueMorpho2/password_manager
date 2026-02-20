#include<iostream>
#include<string>
#include<fstream>
using namespace std;

void viewpass();
string encryptdecrpyt(string &data){
    const char key='k';
    for (int i = 0; i < data.length(); i++){
        data[i]=data[i]^key;
    }
    return data;
}

void addpass(){    //private   
    string site,user,pass;
    ofstream in("file.txt");
    if (!in.is_open()){
        cout<<"file not opened";
    }else{
        cout<<"enter website name:";
        cin>>site;
        cout<<"enter username:";
        cin>>user;
        cout<<"enter password:";
        cin>>pass;
        in<<site<<" "<<encryptdecrpyt(user)<<" "<<encryptdecrpyt(pass);
    }
    in.close();
    cout<<"Saved";
}

void menu(){
    int choice;
    do{
    cout<<"\n1.Add Password \n2.View Passwords \n3.exit\n";
    cout<<"Enter choice";
    cin>>choice;
    switch (choice){
        case 1:
        addpass();
        // addpass;
        break;

        case 2:
        viewpass();
        break;

        case 3:
        cout<<"Exiting the file";
        break;

    default:
    cout<<"invalid option";
        break;
}
    } while (choice !=3);
}

void login(){
    string pass="admin@123";
    string input;
    cout<<"enter master password:";
    cin>>input;
    if (input != pass){
        cout<<"Access denied";
        
    }
    cout<<"Login successfull"<<endl;
    menu();
}
void viewpass(){
    string site,user,pass;
    ifstream out("file.txt");
    while (out>>site>>user>>pass)
    {
        cout<<"site : "<<site<<endl;
        cout<<"user : "<<encryptdecrpyt (user)<<endl;
        cout<<"password : "<<encryptdecrpyt (pass)<<endl;
    }
    out.close();
}
int main(){
    login();
    
 return 0;
}
