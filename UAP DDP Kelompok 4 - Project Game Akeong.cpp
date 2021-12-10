//        UAP PROJECT AKHIR 
//         PEMBUATAN GAME
// 
//     KELOMPOK 4
//  	1. NAMA : ZIKWAN ISMAIL 
//	   NPM  : 2117051051
//	
//	2. NAMA : AMELIA AGUSTINA NAINGGOLAN
//	   NPM  : 2117051080
//	   	
//	3. NAMA : WALIID ILHAM RAMADHAN
//	   NPM  : 2117051094

#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

void delay (){
	int delay;
	delay = 1;
	while (delay<100000000){
	delay++;
	}
}

void slmt_dtg (){
	int i, panjang_char;
	char pesan[] = {'S','E','L','A','M','A','T',' ','D','A','T','A','N','G',' ','D','I',' ','G','A','M','E',' ','A','K','E','O','N','G','\0'};
	i = 0;
	panjang_char = strlen(pesan);
	cout <<"\n\t ";
	while (i<panjang_char){
	cout<<pesan[i];
	delay ();
	i++;
	}
	pesan[i] = 0;
	cout<<" "<<endl;
}

void garis (){
	int i;
	for(i=1; i<=24; i++){
	cout<<"<> ";
	delay();
	}
	cout<<" "<<endl;
}

void fungsi (){
	garis ();
	slmt_dtg ();
	garis ();
	system ("cls");
	cout<<"      "<<endl;
}

void nama (){
	string nama;
	cout<<"NAMA PEMAIN : ";
    getline(cin,nama);
    cout<<" "<<endl;
    cout<<nama<<" AYO BANTU @ MENEMUI TEMANNYA YAITU SI ! "<<endl;
}

int main (){
	
	fungsi ();
	
	char Map[20][20] = 	{"###############",
               		    	"#   ##  #   #!#",
             			"######    #   #",
                   		"#   #  ########",
                 		"#     ## $#   #",
                   		"#         #  ?#",
                   		"######        #",
                   		"##   #  ###   #",
                   		"##     #% #  ##",
                   		"#  #  #       #",
                   		"# ####    #####",
                   		"# # #      #  #",
                   		"# #    ###    #",
                   		"#@#         *##",
                   		"###############",
						};
	int Gamespeed = 100;
	int Level = 0;
	//bool adalah tipe data boolean yang hanya berisi true dan false
	bool stopgame = false;
	 nama ();
	 system("pause");
    while (stopgame == false && Level == 0)
    {
          system("cls");
     
          for (int y=0; y<20; y++){
              cout<<Map[y]<<endl;
          }
          for (int y=0; y<20; y++){
              for (int x=0; x<20; x++){
                switch (Map[y][x]){
		case '#':
		{
		 Map[y][x] = 219;
		}
		break;
					
		case '@':
					{
                    	if (GetAsyncKeyState(VK_UP) !=0){
                        	int y2 = (y-1);
				switch (Map[y2][x]){
                            case ' ' :
                            {
                                Map[y][x] = ' ';
                                y-=1;
                                Map[y2][x]='@';
                                } 
				break;
                                 
				case '!' :
                           	{
                            		Level = 1;
                                	} 
					break;
				}
			}
							
                        if (GetAsyncKeyState(VK_DOWN) !=0){
                            int y2 = (y+1);
                            switch (Map[y2][x]){
                            	case ' ' :
				{
                                Map[y][x] = ' ';
                                y+=1;
                                Map[y2][x]='@';
				} 
				break;
										
                          	case '!' :
				{
					Level = 1;
					}
					break;
                            }
                        }
                        
                        if (GetAsyncKeyState(VK_RIGHT) !=0){
                            int x2 = (x+1);
                            switch (Map[y][x2]){
                            case ' ' :
                            {
                                Map[y][x] = ' ';
                                x+=1;
                                Map[y][x2]='@';
                                }
				break;
                                      
			case '!' :
                        {
                             	Level = 1;
                            	}
				break;
                            }
                        }
                          
				if (GetAsyncKeyState(VK_LEFT) !=0){
                        		int x2 = (x-1);
                            		switch (Map[y][x2]){
                            		case ' ' :
                            {
                                Map[y][x] = ' ';
                                x-=1;
                                Map[y][x2]='@';
                                }
				break;
								
                            case '!' :
                            {
                                Level = 1;
                                } 
				break;
                            }
                        }
                          
                    }
			break;
                  }
              }
          }
          Sleep(Gamespeed);
    }
    
    while  (stopgame == false && Level==1)
    {
		system ("cls");
		cout<<"=============== KAMU BERHASIL !!! =============== "<<endl;
		cout<<"=============== KAMU BERHASIL !!! =============== "<<endl;
		cout<<"=============== KAMU BERHASIL !!! =============== "<<endl;
		cout<<" "<<endl;
		cout<<"* * * * * * * * LEVEL 2 COMING SOON * * * * * * * * "<<endl;
		system ("pause"); 
		return EXIT_SUCCESS;       
    }
    exit (1);
    getch ();
}
