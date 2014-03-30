
#ifndef SERIAL_H
#define SERIAL_H

#include "mvirt.h"
#include "ringbuffer.h"

extern HARD_Serial_t Serial0;

class HARD_Serial_t : public Stream
{
	public:
	DEVICE_UartRegs* uart; 
	
HARD_Serial_t(DEVICE_UartRegs* p, uint32_t tx_size,uint32_t rx_size) {uart = p; 
tx = new  ring_buffer(tx_size); 	
rx = new  ring_buffer(rx_size); 	
transmitting=0;
};
HARD_Serial_t(){};
	
struct ring_buffer *tx; 	
struct ring_buffer *rx;		
void begin();

size_t write(uint8_t c);
 int available();
 int read();
 int peek();
 void flush();
 void send();
 
void begin(uint32_t baud);
boolean transmitting;

	
 using Stream::write; // pull in write(str) and write(buf, size) from Print
 operator bool() { return true; }

};




#endif