#include<avr/io.h>
#define F_CPU 12000000
#include<util/delay.h>

int f[10],w[10],q[10],v[10];
int s;
void lcdcmd(char x)
{
PORTB=x;
PORTA=0b00000100;
_delay_ms(100);
PORTA=0b00000000;
}
void lcddata(char y)
{
PORTB=y;
PORTA=0b00000101;
_delay_ms(100);
PORTA=0b00000001;
}
void lcdstring(char y[])
{
for(int i=0;y[i]!='\0';i++)
{
lcddata(y[i]);
}
}
void main()
{
DDRB=0b11111111;

DDRC=0b00000000;
DDRA=0b11111111;
DDRD=0b11111111;
lcdcmd(0X38);
lcdcmd(0X0E);
lcdcmd(0X01);
lcdcmd(0X80);
lcdstring("WELCOME PLS VOTE");
int aa,bb=0,z=0,pp=0;
while(1)
{
if(PINC==0b00000001)
{
lcdstring("BJP");
itoa(aa,f,10);
lcdstring(f);
_delay_ms(100);

aa++;
lcdcmd(0X01);

}
if(PINC==0b00000010)
{
lcdstring("congress");
itoa(bb,w,10);
lcdstring(w);
lcdcmd(0X01);
bb++;
}

}
}
