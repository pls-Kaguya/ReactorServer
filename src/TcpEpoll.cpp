#include "TcpServer.h"
using namespace std;

int main(int argc,char* argv[]){
    TcpServer *server=new TcpServer();
    server->Start();
   
    return 0;
}