#include <iostream>
#include <fstream>
#include <string>



class Logger { /* Abstract Logger Class */
protected:
    virtual void log(const std::string&) = 0;
    virtual ~Logger() {}
};

/* FileLogger and ConsoneLogger both have log method, so it will be more cool to use abstract Logger class */

class FileLogger : public Logger {
public:
    //constructor with parameter
    FileLogger(const std::string& filename) : m_filename(filename) {}
    //method
    void log(const std::string& message) override {
        std::ofstream file(m_filename);
        if (file.is_open()) {
            file << message << std::endl;
            file.close();
        }
    }

private:
    std::string m_filename;
};

class ConsoleLogger {
public:
    void log(const std::string& message) override{
        std::cout << message << std::endl;
    }
};

class User {
public:
    User(const std::string& name) : m_name(name) {}

    void login() {
        // Simulate user login
        std::string message = "User " + m_name + " has logged in.";

        // Log the message to a file
        FileLogger fileLogger("log.txt");
        fileLogger.log(message);

        // Log the message to the console
        ConsoleLogger consoleLogger;
        consoleLogger.log(message);
    }

private:
    std::string m_name;
};

int main() {
    User user("John");
    user.login();

    return 0;
}
