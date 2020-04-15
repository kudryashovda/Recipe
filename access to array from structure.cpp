#include <iostream>

u_int8_t packet[] = {0xAA,0xFF,0xCA,0xFF};

struct pkt_st
{   
 u_int16_t head;
 u_int16_t data;
};


int main()
{
    pkt_st* p = ( pkt_st* )packet;

    std::cout << "head: " << p->head << std::endl;
    std::cout << "data: " << p->data << std::endl;
    
    return 0;
}
