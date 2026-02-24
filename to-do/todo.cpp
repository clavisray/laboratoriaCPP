#include <iostream>
#include <sstream>
#include <vector>

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

    public:
        void print() const {
            for(const Task& t : tasks_){
                std::cout << t.toString() << '\n';
            }
        };

        void addTask(const std::string& title){
            tasks_.push_back(Task(nextId_++, title));
        };
};

int main(){
    TodoList lista;
    lista.addTask("wynieś śmieci");
    lista.addTask("poodkurzaj");

    lista.print();

    Task zadanie(1, "wyniesienie smieci");
    Task zadanko(2, "poodkurzanie");

    zadanie.toString();
    zadanko.toString();

    lista.print();
    return 0;
}