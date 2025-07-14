#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool isCompleted;
};

vector<Task> todoList;

// Function to display the menu
void showMenu() {
    cout << "\n====== TO-DO LIST MANAGER ======" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. View Tasks" << endl;
    cout << "3. Mark Task as Completed" << endl;
    cout << "4. Remove Task" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
}

// Add a new task
void addTask() {
    Task newTask;
    cout << "Enter task description: ";
    cin.ignore(); // Clear input buffer
    getline(cin, newTask.description);
    newTask.isCompleted = false;
    todoList.push_back(newTask);
    cout << "Task added successfully!" << endl;
}

// Display all tasks
void viewTasks() {
    if (todoList.empty()) {
        cout << "No tasks found." << endl;
        return;
    }

    cout << "\n------ To-Do List ------" << endl;
    for (size_t i = 0; i < todoList.size(); ++i) {
        cout << i + 1 << ". " << todoList[i].description;
        cout << " [" << (todoList[i].isCompleted ? "Completed" : "Pending") << "]" << endl;
    }
}

// Mark a task as completed
void markTaskCompleted() {
    viewTasks();
    if (todoList.empty()) return;

    int taskNum;
    cout << "Enter task number to mark as completed: ";
    cin >> taskNum;

    if (taskNum > 0 && taskNum <= todoList.size()) {
        todoList[taskNum - 1].isCompleted = true;
        cout << "Task marked as completed!" << endl;
    } else {
        cout << "Invalid task number." << endl;
    }
}

// Remove a task
void removeTask() {
    viewTasks();
    if (todoList.empty()) return;

    int taskNum;
    cout << "Enter task number to remove: ";
    cin >> taskNum;

    if (taskNum > 0 && taskNum <= todoList.size()) {
        todoList.erase(todoList.begin() + (taskNum - 1));
        cout << "Task removed!" << endl;
    } else {
        cout << "Invalid task number." << endl;
    }
}

int main() {
    int choice;

    do {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                markTaskCompleted();
                break;
            case 4:
                removeTask();
                break;
            case 5:
                cout << "Exiting To-Do List Manager. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Try again!" << endl;
        }

    } while (choice != 5);

    return 0;
}
