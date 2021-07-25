#include "SimpleSerial.h"


char com_port[] = "\\\\.\\COM3";
DWORD COM_BAUD_RATE = CBR_9600;
SimpleSerial Serial(com_port, COM_BAUD_RATE);
string read_in;

void Stealth();
void Stealth()
{
  HWND Stealth;
  AllocConsole();
  Stealth = FindWindowA("ConsoleWindowClass", NULL);
  ShowWindow(Stealth,0);
}
int main()
{
 if(Serial.isConnected()) {
	//do whatever
 //Stealth();
	 char i;int key_stroke;int y;int m;int o;int j;
	
	 cout<<"This is Bongo Cat on Oled"<<endl;
	
	 cout<<"!!!Do not exit this window!!!"<<endl;
	
	 cout<<"Feel free to minimize this window"<<endl;
	 while (1)
	 {
	  // for(i = 0; i <= 390; i++) 	// all Virtual-Key Codes
	  for(i = 32; i <= 126; i++)	//only keyboard 	
	  {
	  	if (GetAsyncKeyState(i) == -32767)
		{
			key_stroke=i;
			if (key_stroke == 67)                              //c
		 	{
				if(m==10)
				{
					y=y+1;m=m+5;o=0;j=0;
				}
				else
					{
						y=y+1;m=0;o=0;j=0;
					}
		 	}
			else if (key_stroke == 77)                         //m
			{
				if(y==1)
			 	{
					y=y+2;m=1;o=0;j=0;
				}
				else
					{
						y=0;m=1;o=0;j=0;
					}
			}
		 	else if (key_stroke == 68)                         //d
		 	{
		 		if(y==3||j==1)
		 			{
		 				y=y+3;m=0;o=0;j=j+2;
		 			}
		 		else
		 			{
		 				y=0;m=0;o=0;j=0;
		 			}
		 	}
/////////////////////////////////////
			if( 32 <= key_stroke <= 126 )
			{	
				read_in = key_stroke;
				
				char *to_send = &read_in[0];
				bool is_sent = Serial.WriteSerialPort(to_send);
					
				if (is_sent) {
					cout<<"Send\n";
				}
			}
/////////////////////////////////////			 	
		else
		{
			y=0;m=0;j=0;o=0;
		 //cout<<key_stroke;
		 //printf(" %s", &key_stroke);
		}
		 //cout<<"\n";
//------------------------------------------------------------------------------
		
//------------------------------------------------------------------------------     
//------------------------------------------------------------------------------
		// if (y==6)
		// {
		// 	system("start C:\\Windows\\System32\\cmd.exe"); 
		// 	y=0;m=0;j=0;o=0;
		// }
					   
	//------------------------------------------------------------------------------
	   }
	  }
	 }
	 system ("PAUSE");
	 return EXIT_SUCCESS;
	}
}
/*//     else if (key_stroke == 85)
//     m=2;
//     else if (key_stroke == 83)
//     m=3;
//     else if (key_stroke == 73)
//    m=4;*/
/*
00
*/
