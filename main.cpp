#include "sniffer.h"
#include <iostream>
using namespace std;


int main()
{
    sniffer A(htons(ETH_P_IP));
  if(  A.sniffer_init()){
       cout<<"init_OK"<<endl;
       A.sniffer_start();
  }
 
}