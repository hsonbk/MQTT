#include "myMosquitto.h"
#include <cstdlib>
#include <signal.h>


const char *id;
std::string _topic1 = "topic/sub";
std::string _topic2 = "topic/pub";
const char *host = "test.mosquitto.org";
int port = 1883;
std::string mess;

myMosquitto* mqtt;
// mqtt = new myMosquitto(id, host, port);
// mqtt->subscribe_to_topic(_topic1);
// mqtt->subscribe_to_topic(_topic2);

void signalHandle(int signum){
    std::cout << " Catch signal " << signum << std::endl << "Exit program" << std::endl;
    exit(signum);
}

int main(int argc, char *argv[])
{   
    mqtt = new myMosquitto(id, host, port);
    sleep(2);
    mqtt->subscribe_to_topic(_topic1);
    mqtt->subscribe_to_topic(_topic2);
    // mqtt = new myMosquitto(id, host, port);
    signal(SIGINT, signalHandle);
    while(1){
        //----------------------------Enter topic and message to sub and pub-----------------------
        // std::cout << "Topic: ";
        // std::getline(std::cin,_topic);
        // mqtt->subscribe_to_topic(_topic);
        // sleep(2);
        // std::cout << "Enter message: ";
        // std::getline(std::cin,mess);
        mqtt->myPublish(_topic1, "hi from client");
        sleep(10); 
        //mqtt->unsubscribe_from_topic(_topic);
        // std::cout << "About to delete mqtt" << std::endl;
        //delete mqtt;
        // std::cout << "Mqtt deleted" << std::endl;
        // sleep(2);
    }
    return 0;
}