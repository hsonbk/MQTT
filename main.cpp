#include "myMosquitto.h"
#include <cstdlib>
#include <signal.h>


const char *id;
std::string _topic;
const char *host = "test.mosquitto.org";
int port = 1883;
std::string mess;

myMosquitto* mqtt;

void signalHandle(int signum){
    std::cout << " Catch signal " << signum << std::endl << "Exit program" << std::endl;
    exit(signum);
}

int main(int argc, char *argv[])
{   
    // myMosquitto* mqtt;
    signal(SIGINT, signalHandle);
    while(1){
        mqtt = new myMosquitto(id, host, port);
        sleep(2);
        std::cout << "Topic: ";
        std::getline(std::cin,_topic);
        mqtt->subscribe_to_topic(_topic);
        sleep(2);
        std::cout << "Enter message: ";
        std::getline(std::cin,mess);
        mqtt->myPublish(_topic, mess);
        sleep(2); 
        //mqtt->unsubscribe_from_topic(_topic);
        // std::cout << "About to delete mqtt" << std::endl;
        //delete mqtt;
        // std::cout << "Mqtt deleted" << std::endl;
        sleep(2);
        }
    return 0;
}