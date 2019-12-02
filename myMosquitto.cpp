#include "myMosquitto.h"

#include <iostream>

myMosquitto::myMosquitto(const char* _id, const char* _host, int _port) :
    mosquittopp(_id)
{
    int ret;
    mosqpp::lib_init();

    this->keepalive = 60;
    // const char *mosquitto_strerror(int mosq_errno);
    // if (username_pw_set("sampleuser", "samplepass") != MOSQ_ERR_SUCCESS) {
    //     std::cout << "setting passwd failed" << std::endl;
    // }
    this->id = _id;
    this->port = _port;
    this->host = _host;
    connect_async(host,port, keepalive);
    // std::cout << "connect ret " << ret << mosqpp::strerror(ret) << std::endl;
    // ret = subscribe(NULL, topic, 1);
    // std::cout << "subcribe ret" << ret << mosqpp::strerror(ret) << std::endl;

    // if (loop_start() != MOSQ_ERR_SUCCESS) {
    //     std::cout << "loop_start failed" << std::endl;
    // }
    loop_start();
}

myMosquitto::~myMosquitto()
{
    // std::cout << "1" << std::endl;
    // if (loop_stop() != MOSQ_ERR_SUCCESS) {
    //     std::cout << "loop_stop failed" << std::endl;
    // }
    // std::cout << "2" << std::endl;
    // mosqpp::lib_cleanup();
    // std::cout << "3" << std::endl;
    loop_stop();
    mosqpp::lib_cleanup();
}

void myMosquitto::on_message(const struct mosquitto_message *message){
    std::string payload = std::string(static_cast<char *>(message->payload));
    std::string topic = std::string(message->topic);

    std::cout << "payload: " << payload << std::endl;
    std::cout << "topic: " << topic << std::endl;
    std::cout << "On message( QoS: " << message->mid 
                    << " topic: " << std::string(message->topic) << " - message: "
                    << std::string((char *)message->payload, message->payloadlen) << ")" << std::endl;
    }


void myMosquitto::on_connect(int rc){
    // std::cout << "Connected success " << rc << std::endl;
    if ( rc == 0 ) {
        std::cout << "Connected success with server: "<< this->host << std::endl;
        // std::cout << "Enter message: ";
        // std::getline(std::cin,mess);
    }
    else{
        std::cout << "Cant connect with server(" << rc << ")" << std::endl;
    }
}
void myMosquitto::on_disconnect(int rc){
   std::cout << "Disconnected (" << rc << ")" << std::endl;
}

// void myMosquitto::on_publish(int mid) {
//     std::cout << "Published message succesful" << std::endl;
// }

// void myMosquitto::on_subscribe(int mid, int qos_count, const int *granted_qos){
//     std::cout << "Subscribed successful(" << mid << ")" << std::endl;
// }

// void myMosquitto::on_unsubscribe(int mid){
//     std::cout << "Unsubscribed successful(" << mid << ")" << std::endl;
// }

void myMosquitto::myPublish(std::string topic, std::string mess){
    // std::cout << "Topic: ";
    // std::getline(std::cin,topic);
    // std::cout << "Enter message: ";
    // std::getline(std::cin,mess);
    int ret = publish(NULL, topic.c_str(), mess.size(), mess.c_str(), 1, false);
    if (ret != MOSQ_ERR_SUCCESS){
        std::cout << "Send failed." << std::endl;
    }
    else std::cout << "Send success " << std::endl;
    // << mess << " >>> published to: " << topic << std::endl;
}
void myMosquitto::subscribe_to_topic(std::string topic){
    int ret = subscribe(NULL, topic.c_str());
    if (ret != MOSQ_ERR_SUCCESS){
        std::cout << "Subcribe failed" << std::endl;
    }
    else std::cout << "Subcribe success " << std::endl;
}
void myMosquitto::unsubscribe_from_topic(std::string topic){
    int ret = unsubscribe(NULL, topic.c_str());
    if (ret != MOSQ_ERR_SUCCESS){
        std::cout << "Unsubcribe topic " << topic << std::endl;
    }
    else std::cout << "Unsubcribe failed." << std::endl;
    // return (MOSQ_ERR_SUCCESS);
}

// void myMosquitto::receive_from_topic(){

// }