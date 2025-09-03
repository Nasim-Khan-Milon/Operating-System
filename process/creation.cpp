#include <iostream>
#include <unistd.h>   // for fork(), getpid(), getppid()

using namespace std;

int main() {
    pid_t pid;

    cout << "Before fork: I am process with PID = " << getpid() << endl;

    pid = fork();  // create a new process

    if (pid < 0) {
        // Error in process creation
        perror("fork failed");
        return 1;
    }
    else if (pid == 0) {
        // Child process
        cout << "Child process created!" << endl;
        cout << "Child PID = " << getpid() << ", Parent PID = " << getppid() << endl;
    }
    else {
        // Parent process
        cout << "Parent process continues..." << endl;
        cout << "Parent PID = " << getpid() << ", Child PID = " << pid << endl;
    }

    return 0;
}
