#include<bits/stdc++.h> 
using namespace std;

struct HealthData{
    string date;
    double weight;
    int calories;
};

class HealthTracker{
    private:
        vector<HealthData>records;

    public:
        void addRecord(const string&date,double weight,int calories){
            records.push_back({date,weight,calories});
            cout<<"Added record for "<<date<<endl;
        }

        void saveToFile(const string&filename)const{
            ofstream file(filename);
            if(!file.is_open()){
                cerr<<"Error:Could not open file for writing!"<<endl;
                return;
            }
            for(const auto&record:records){
                file<<record.date<<" "<<record.weight<<" "<<record.calories<<"\n";
            }
            file.close();
            cout<<"Data saved to "<<filename<<endl;
        }

        void loadFromFile(const string&filename){
            ifstream file(filename);
            if(!file.is_open()){
                cerr<<"Error:Could not open file for reading!"<<endl;
                return;
            }
            records.clear();
            HealthData record;
            while(file>>record.date>>record.weight>>record.calories){
                records.push_back(record);
            }
            file.close();
            cout<<"Data loaded from "<<filename<<endl;
        }

        void displayDailyReport(const string&date)const{
            bool found=false;
            for(const auto&record:records){
                if(record.date==date){
                    cout<<"Daily Report for "<<date<<":\n";
                    cout<<"Weight: "<<record.weight<<" kg\n";
                    cout<<"Calories: "<<record.calories<<" kcal\n";
                    found=true;
                    break;
                }
            }
            if(!found){
                cout<<"No data found for "<<date<<endl;
            }
        }

        void displayAllRecords()const{
            cout<<left<<setw(12)<<"Date"<<setw(10)<<"Weight"<<setw(10)<<"Calories"<<endl;
            cout<<"----------------------------------\n";
            for(const auto&record:records){
                cout<<setw(12)<<record.date<<setw(10)<<record.weight<<setw(10)<<record.calories<<endl;
            }
        }
};

int main(){
    HealthTracker tracker;
    string filename="health_data.txt";

    int choice;
    do{
        cout<<"\nHealth Tracker\n";
        cout<<"1.Add Health Record\n";
        cout<<"2.Save Records\n";
        cout<<"3.Load Records\n";
        cout<<"4.Display Daily Report\n";
        cout<<"5.Display All Records\n";
        cout<<"6.Exit\n";
        cout<<"Choose an option: ";
        cin>>choice;

        switch(choice){
            case 1:{
                string date;
                double weight;
                int calories;
                cout<<"Enter date (YYYY-MM-DD): ";
                cin>>date;
                cout<<"Enter weight (kg): ";
                cin>>weight;
                cout<<"Enter calories (kcal): ";
                cin>>calories;
                tracker.addRecord(date,weight,calories);
                break;
            }
            case 2:
                tracker.saveToFile(filename);
                break;
            case 3:
                tracker.loadFromFile(filename);
                break;
            case 4:{
                string date;
                cout<<"Enter date (YYYY-MM-DD): ";
                cin>>date;
                tracker.displayDailyReport(date);
                break;
            }
            case 5:
                tracker.displayAllRecords();
                break;
            case 6:
                cout<<"Exiting...\n";
                break;
            default:
                cout<<"Invalid option. Please try again.\n";
        }
    }while(choice!=6);

    return 0;
}

