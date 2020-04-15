#include <iostream>

unsigned char packet[] = {0x00,0xFF,0xAA,0xBB};

struct pkt_st
{   
 unsigned short header;
 unsigned char data;
 unsigned char crc;
};

int main()
{
    pkt_st * p = ( pkt_st * )packet;
    
    std::cout << "head: " << (int)p->header << std::endl; // 0xFF00
    std::cout << "data: " << (int)p->data   << std::endl;
    std::cout << "crc:  " << (int)p->crc    << std::endl;
    
    return 0;
}
