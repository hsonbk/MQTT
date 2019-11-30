#include <iostream>
#include <unistd.h>
#include <mosquittopp.h>
#include <string>

class myMosquitto : public mosqpp::mosquittopp
{
public:
    myMosquitto(const char* id, const char* _host, int port_);
    ~myMosquitto();

    void subscribe_to_topic(std::string topic);
    void unsubscribe_from_topic(std::string topic);
    void myPublish(std::string topic, std::string mess);
private:
    void on_connect(int rc);
    // void on_publish(int mid);
    void on_disconnect(int rc);
    // void on_subscribe(int mid, int qos_count, const int *granted_qos);
    // void on_unsubscribe(int mid);

    const char* host;
    const char* id;
    const char* topic;
    int port;
    int keepalive;
    std::string mess;
};