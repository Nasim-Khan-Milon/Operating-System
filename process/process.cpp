#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        std::cerr << "Fork failed." << std::endl;
        return 1;
    } else if (pid == 0) {
        // Child process
        std::cout << "Child process created. PID: " << getpid() << std::endl;
        // Child process terminates
        _exit(0);
    } else {
        // Parent process
        std::cout << "Parent process. PID: " << getpid() << std::endl;
        // Wait for child to terminate
        waitpid(pid, nullptr, 0);
        std::cout << "Child process terminated." << std::endl;
    }

    return 0;
}