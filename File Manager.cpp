#include<bits/stdc++.h>
using namespace std;

class FileManager{
    public:
        void viewFile(const string&fileName){
            ifstream file(fileName);
            if(!file.is_open()){
                cout<<"Error: Could not open file "<<fileName<<"\n";
                return;
            }
            cout<<"Contents of "<<fileName<<":\n";
            string line;
            while(getline(file,line)){
                cout<<line<<"\n";
            }
            file.close();
        }

        void editFile(const string&fileName){
            ofstream file(fileName,ios::app);
            if(!file.is_open()){
                cout<<"Error: Could not open file "<<fileName<<"\n";
                return;
            }
            cout<<"Enter text to append (type \"exit\" to stop):\n";
            string input;
            cin.ignore(); 
            while(true){
                getline(cin,input);
                if(input=="exit")break;
                file<<input<<"\n";
            }
            file.close();
            cout<<"Changes saved to "<<fileName<<"\n";
        }

        void overwriteFile(const string&fileName){
            ofstream file(fileName); 
            if(!file.is_open()){
                cout<<"Error: Could not open file "<<fileName<<"\n";
                return;
            }
            cout<<"Enter text to overwrite the file (type \"exit\" to stop):\n";
            string input;
            cin.ignore(); 
            while(true){
                getline(cin,input);
                if(input=="exit")break;
                file<<input<<"\n";
            }
            file.close();
            cout<<"File "<<fileName<<" has been overwritten.\n";
        }
};

int main(){
    FileManager manager;
    int choice;
    string fileName;

    do{
        cout<<"\nFile Manager\n";
        cout<<"1. View File\n";
        cout<<"2. Edit File (Append)\n";
        cout<<"3. Overwrite File\n";
        cout<<"4. Exit\n";
        cout<<"Choose an option: ";
        cin>>choice;

        switch(choice){
            case 1:
                cout<<"Enter file name to view: ";
                cin>>fileName;
                manager.viewFile(fileName);
                break;
            case 2:
                cout<<"Enter file name to append: ";
                cin>>fileName;
                manager.editFile(fileName);
                break;
            case 3:
                cout<<"Enter file name to overwrite: ";
                cin>>fileName;
                manager.overwriteFile(fileName);
                break;
            case 4:
                cout<<"Exiting program.\n";
                break;
            default:
                cout<<"Invalid choice. Please choose again.\n";
        }
    }while(choice!=4);
}

