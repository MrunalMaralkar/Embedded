#include <reg51.h>
sbit RS=P3^1;
sbit RW=P3^2;
sbit EN=P3^3;
sbit r0=P1^0;
sbit r1=P1^1;
sbit r2=P1^2;
sbit r3=P1^3;
sbit c0=P1^4;
sbit c1=P1^5;
sbit c2=P1^6;
sbit c3=P1^7;
sbit led=P3^4;
#define dataline P2
void lcd_string(unsigned char *);
void lcd_init(void);
void lcd_cmd(unsigned char);
void lcd_data(unsigned char);
void delay(int);
void main()
{
	int i,pass[4],pass1[4]={1,4,8,7};
	lcd_init();
	while (1)
	{
		i=0;
		lcd_cmd(0x80);
	lcd_string("ENTER PASSWORD");
		lcd_cmd(0xC0);
		while(i<4)
		{
r0=0;
		r1=r2=r3=1;
		if(c0==0)
		{
lcd_data('1');
			pass[i]=1;
			i++;
}
r0=0;
		r1=r2=r3=1;
		if(c1==0)
		{
lcd_data('2');
			pass[i]=2;
			i++;
}
r0=0;
		r1=r2=r3=1;
		if(c2==0)
		{
lcd_data('3');
			pass[i]=3;
			i++;
}
r1=0;
		r0=r2=r3=1;
		if(c0==0)
		{
lcd_data('4');
			pass[i]=4;
			i++;
}
r1=0;
		r0=r2=r3=1;
		if(c1==0)
		{
lcd_data('5');
			pass[i]=5;
			i++;
}
r1=0;
		r0=r2=r3=1;
		if(c2==0)
		{
lcd_data('6');
			pass[i]=6;
			i++;
}
r2=0;
		r0=r1=r3=1;
		if(c0==0)
		{
lcd_data('7');
			pass[i]=7;
			i++;
}
r2=0;
		r0=r1=r3=1;
		if(c1==0)
		{
lcd_data('8');
			pass[i]=8;
			i++;
}
r2=0;
		r0=r1=r3=1;
		if(c2==0)
		{
lcd_data('9');
			pass[i]=9;
			i++;
}
r3=0;
		r0=r2=r1=1;
		if(c1==0)
		{
lcd_data('0');
			pass[i]=0;
			i++;
}
delay(120);
}
if((pass[0]==pass1[0])&&(pass[1]==pass1[1])&&(pass[2]==pass1[2])&&(pass[3]==pass1[3]))
{
	lcd_cmd(0x01);
	lcd_cmd(0x80);
	lcd_string("Access Granted");
	led=1;
	delay(5000);
}
else 
{
	lcd_cmd(0x01);
	lcd_cmd(0x80);
	lcd_string("Wrong Password");
	led=0;
	delay(5000);
}
}
}
void lcd_init(void)
{
	lcd_cmd(0x38);
	lcd_cmd(0x01);
	lcd_cmd(0x80);
	lcd_cmd(0x0F);
}
void lcd_string(unsigned char *p)
{
while(*p!='\0')
{
	lcd_data(*p);
	p++;
}
}
void lcd_cmd(unsigned char c)
{
	dataline=c;
	RS=0;
	RW=0;
	EN=1;
	delay(10);
	EN=0;
}
void lcd_data(unsigned char c)
{
	dataline=c;
	RS=1;
	RW=0;
	EN=1;
	delay(10);
	EN=0;
}
void delay (int t)
{
	int i,j;
	for(i=0;i<t;i++)
	{
		for(j=0;j<200;j++)
		{
		}
	}
}