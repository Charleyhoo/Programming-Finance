#include "randGen.h"
int debugLevel=1;

void randGen(std::string strR, std::string strN){
    int randRange;
    int randNum;
    DebugPrint dbug;
    std::stringstream ss;
    ss<<strR;
    ss>>randRange;
    ss.clear();
    //randRange++
    dbug.print(1,"randRange=" + std::to_string(randRange));
    ss.str(strN);
    ss>>randNum;
    dbug.print(1,"randNum=" + std::to_string(randNum));
    for(int idx=0; idx<randNum; idx++){
        int myRand=1+(rand()%randRange);
        std::cout<<"rand number"<<idx<<":"<<myRand<<std::endl;

    }
}
void debugPring(int dL, std::string statement){
    //std::cout<<"debugLevel= "<< debuglevel <<'\n';
    if (dL <debugLevel){
        return;

    }
    if (dL==1){
        std::cout<<GREEN<<"DEBUG: "<<statement<<RESET<<std::endl;
    }
    else if(dL==2){
        std::cout<<BOLDCYAN<<"TNED:"<<statement<<RESET<<std::endl;
    }
    else if(dL==3){
        std::cout<<WHITE<<"WHITE:"<<statement<<RESET<<std::endl;
    }
    return;
}