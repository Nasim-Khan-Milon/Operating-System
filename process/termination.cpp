#include <iostream>
#include <unistd.h>   // for fork(), getpid(), getppid()
#include <sys/wait.h> // for wait()
#include <cstdlib>    // for exit()

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
        cout << "Child PID = " << getpid() 
             << ", Parent PID = " << getppid() << endl;

        cout << "Child is terminating now..." << endl;
        exit(0);  // terminate child process
        //_exit(0);
    }
    else {
        // Parent process
        cout << "Parent process continues..." << endl;
        cout << "Parent PID = " << getpid() 
             << ", Child PID = " << pid << endl;

        wait(NULL);  // parent waits until child finishes
        //waitpid(pid, nullptr, 0);
        cout << "Child has terminated, parent is also terminating..." << endl;
    }

    return 0;
}
