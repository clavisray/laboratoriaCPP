#include <iostream>
#include <sstream>
#include <vector>
#include <limits>

class Task{
    private:
        int id_;
        std::string title_;
        bool done_;
        int priority_;

    public:
        Task(int id, std::string title)
            : id_(id), title_(title), done_(false), priority_(1) {}
        
        int id() const { return id_; }
        const std::string& title() const { return title_; }
        bool done() const { return done_; }
        
        void toggleDone() { done_ = !done_; }
        void markDone() { done_ = true; }
        
        int priority() const { return priority_; }

        std::string toString() const {
            std::ostringstream out;

            out << "(" << id_ << ")" << " Task: " << title_ << " | prio: " << priority_ << " " << (done_ ? "[x]" : "[ ]");
            return out.str();
        }
};

class TodoList{
    private:
        std::vector<Task> tasks_;
        int nextId_ = 1;
        Task* findByID(int id) {
            for (Task& t : tasks_) {
                if(t.id() == id){
                    return &t;
                }
            }
            return nullptr;
        }

    public:
        void print() const {
            for(const Task& t : tasks_){
                std::cout << t.toString() << '\n';
            }
        };

        void addTask(const std::string& title){
            tasks_.emplace_back(Task(nextId_++, title));
        };

        bool markDone(int id) {
            Task* t = findByID(id);
            if(!t) return false;
            t->markDone();
            return true;
        }

        bool removeTask(int id) {
            for (size_t i = 0; i < tasks_.size(); i++) {
                if (tasks_[i].id() == id) {
                    tasks_.erase(tasks_.begin() + i);
                    return true;
                }
            }
            return false;
        }

        // dodać void setTitle && bool editTitle
};

int main(){
    std::cout << "==== TO-DO APP ====\n";
    TodoList lista;

    bool loopStatus = true;

    while (loopStatus){
        std::cout << "1. View the entire tasks list\n" ;
        std::cout << "2. Add new task\n" ;
        std::cout << "3. Delete task\n" ;
        std::cout << "4. Edit task\n" ;
        std::cout << "5. Quit\n" ;

        int userInput;
        std::cin >> userInput;

        switch (userInput) {
        case 1: 
            lista.print();
            break;
        case 2: {
            // zrobić obsługę nie znalezienia taska i pomyślnego dodania taska
            std::string title;
            
            std::cout << "Insert name for a new task\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            getline(std::cin, title);

            lista.addTask(title);
            break;
        }
        case 3: {
            // zrobić obsługę nie znalezienia taska i pomyślnego usunięcia
            int id;

            std::cout << "Insert task ID that needs to be deleted\n";
            std::cin >> id;
            lista.removeTask(id);
            break;
        }
        case 4:
            break;
        case 5:
            loopStatus = false;
            break;
        default:
            std::cout << "Invalid option. Choose between 1-5\n";
        }
    }

    return 0;
}