# Eurydice
//Program to create a voting machine in AVR

#include<avr/io.h>
#include<util/delay.h>

int f[10],w[10],q[10],v[10];
int s;
void lcdcmd(char x)
{
PORTD=x;
PORTC=0b00000100;
_delay_ms(100);
PORTC=0b00000000;
}
void lcddata(char y)
{
PORTD=y;
PORTC=0b00000101;
_delay_ms(100);
PORTC=0b00000001;
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
DDRB=0b00000000;

DDRC=0b11111111;

DDRD=0b11111111;
lcdcmd(0X38);
lcdcmd(0X0E);
lcdcmd(0X01);
lcdcmd(0X80);
lcdstring("WELCOME PLS VOTE");
int aa=0,bb=0,z=0,pp=0;
while(1)
{
if(PINB==0b00000001)
{
lcdstring("BJP");
itoa(aa,f,10);
lcdstring(f);
lcdcmd(0X01);
aa++;
}
if(PINB==0b00000010)
{
lcdstring("congress");
itoa(bb,w,10);
lcdstring(w);
lcdcmd(0X01);
bb++;
}
if(PINB==0b00000100)
{
lcdstring("BSPA");
itoa(pp,q,10);
lcdstring(q);
lcdcmd(0X01);
pp++;
}
if(PINB==0b00001000)
{
lcdstring("SPA");
itoa(z,v,10);
lcdstring(v);
lcdcmd(0x01);
z++;
}
if(PINB==0b00010000)
{
if((aa>bb)&&(aa>pp)&&(aa>z))
{
lcdstring("WINNER BJP");
lcdcmd(0X01);
_delay_ms(100);
}
if((bb>aa)&&(bb>pp)&&(bb>z))
{
lcdstring("WINNER CONGRESS");
lcdcmd(0X01);
_delay_ms(100);
}
if((pp>bb)&&(pp>aa)&&(pp>z))
{
lcdstring("WINNER BSPA");
lcdcmd(0X01);
_delay_ms(100);

}
if((z>bb)&&(z>pp)&&(z>aa))
{
lcdstring("WINNER BJP");
lcdcmd(0X01);
_delay_ms(100);
}
}
}


}
