#include<bits/stdc++.h>
using namespace std;
class Task{
public:
    int id;
    string description;
    string dueDate;
    bool isCompleted;
    
    Task(int id,const string& description,const string&dueDate,
	bool isCompleted=false):id(id),description(description),dueDate(dueDate),
	isCompleted(isCompleted) {}

    void display()const{
       cout<<"ID:"<<id<<"|"<<description<<"|Due:"<<dueDate
        <<"|Status:"<<(isCompleted?"Completed":"Pending")<<endl;
    }
};

class TaskManager{
private:
    vector<Task>tasks;
    int nextId=1;
    const string fileName="tasks.txt";

    void loadTasks(){
        ifstream file(fileName);
        if(file.is_open()){
            int id;
            string description,dueDate;
            bool isCompleted;
            while(file>>id>>ws){
                getline(file,description);
                file>>dueDate>>isCompleted;
                tasks.push_back(Task(id,description,dueDate,isCompleted));
                nextId=max(nextId,id+1);
            }
            file.close();
        }
    }

    void saveTasks()const{
        ofstream file(fileName,ios::trunc);
        for(const auto&task:tasks) {
            file<<task.id<<endl<<task.description<<endl<<task.dueDate
                <<endl<<task.isCompleted <<endl;
        }
        file.close();
    }

public:
    TaskManager(){
        loadTasks();
    }
    ~TaskManager(){
        saveTasks();
    }
    void addTask(const string& description,const string& dueDate){
        tasks.push_back(Task(nextId++,description,dueDate));
        cout<<"Task added successfully!\n";
    }

    void removeTask(int id){
        auto it=remove_if(tasks.begin(),tasks.end(),[id](const Task& task){
            return task.id==id;
        });
        if(it!=tasks.end()){
            tasks.erase(it,tasks.end());
            cout<<"Task removed successfully!\n";
        }else{
            cout<<"Task not found!\n";
        }
    }

    void markTaskCompleted(int id){
        for(auto& task:tasks){
            if(task.id==id){
                task.isCompleted=true;
                cout<<"Task marked as completed!\n";
                return;
            }
        }
    	cout<<"Task not found!\n";
    }

    void editTask(int id,const string& newDescription,const string& newDueDate){
        for(auto& task:tasks){
            if (task.id==id){
                task.description=newDescription;
                task.dueDate=newDueDate;
                cout<<"Task updated successfully!\n";
                return;
            }
        }
        cout<<"Task not found!\n";
    }

    void displayTasks()const{
        if(tasks.empty()){
            cout<<"No tasks available!\n";
        }else{
            for(const auto& task:tasks){
                task.display();
            }
        }
    }
};

int main(){
    TaskManager manager;
    int choice;
    string description,dueDate;
    int taskId;
    do{
        cout<<"\nPersonal Task Manager\n";
        cout<<"1.Add Task\n";
        cout<<"2.Remove Task\n";
        cout<<"3.Mark Task as Completed\n";
        cout<<"4.Edit Task\n";
        cout<<"5.Display Tasks\n";
        cout<<"6.Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice){
            case 1:
                cin.ignore();
                cout<<"Enter task description:";
                getline(cin,description);
                cout<<"Enter task due date (YYYY-MM-DD):";
                getline(cin,dueDate);
                manager.addTask(description,dueDate);
                break;
            case 2:
                cout<<"Enter task ID to remove:";
                cin>>taskId;
                manager.removeTask(taskId);
                break;
            case 3:
                cout<<"Enter task ID to mark as completed:";
                cin>>taskId;
                manager.markTaskCompleted(taskId);
                break;
            case 4:
                cout<<"Enter task ID to edit:";
                cin>>taskId;
                cin.ignore();
            	cout<<"Enter new description:";
                getline(cin,description);
                cout<<"Enter new due date(YYYY-MM-DD):";
                getline(cin,dueDate);
                manager.editTask(taskId,description,dueDate);
                break;
            case 5:
                manager.displayTasks();
                break;
            case 6:
                cout<<"Exiting program...\n";
                break;
            default:
                cout<<"Invalid choice,please try again.\n";
        }
    }while(choice!=6);
}
