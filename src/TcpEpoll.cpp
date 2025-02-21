#include "TcpServer.h"
#include"EchoServer.h"
using namespace std;

int main(int argc,char* argv[]){
    EchoServer *server = new EchoServer("192.168.1.60",8086);
    server->Start();
   
    return 0;
}