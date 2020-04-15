#include <iostream>

u_int8_t packet[] = {0xAA,0xFF,0xCA,0xFF};

struct pkt_st
{   
 u_int16_t header;
 u_int8_t data;
 u_int8_t crc;
};


int main()
{
    pkt_st* p = ( pkt_st* )packet;
    
    std::cout << "head: " << (int)p->header << std::endl;
    std::cout << "data: " << (int)p->data << std::endl;
    std::cout << "crc:  " << (int)p->crc  << std::endl;
    
    return 0;
}
