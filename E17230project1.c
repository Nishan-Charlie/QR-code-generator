#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
////////////////////// Defining Colors
#define white "\x1b[47m"


///////////////// Ascii value>>>>>> Return Ascii value
int Asc(int s){
	return s;
}

int cmp(char a[],char b[]){ ///comaring with out case sensitivity
	int count=0,res=1;
	if(strlen(a)==strlen(b)){ //// string will be same only the length are same
	for(int i=0;i<strlen(a);i++){
			if(toupper(a[i])==toupper(b[i])) { // checking without case sensitivity
				count++;
			}
	}
	if(count==strlen(a)){ ///// Every characters are same
		res=0;
	}
}
 return res; //// if both string are same return 0
}

////////////// Position Squres
void squre(int c,char index[3]){ ////////// position squre>>>>>> Printing the position squres
	for(int j=0;j<6;j++){

                        if(j==0||j==5){
                         printf("\x1b[%s""            ",index);
                                     }
                                else if(j==1 ||j==4){
                              printf("\x1b[%s""  "white"        ""\x1b[%s""  ",index,index);
		} else{
			printf("\x1b[%s""  "white"  ""\x1b[%s""    "white"  ""\x1b[%s""  ",index,index,index);
			}
			if(j==5){
				break;
			}
			printf("\n");
			printf("\x1b[%dC",c);
}
}
//////////////////////////// White frame
void frame(int c){////>>>>>>Printing the squre frame
	  //printing the frame
        for(int k=0;k<c;k++){

        for(int j=0;j<c;j++){
                   printf(white"  ");
                        }
												printf("\x1b[0m");///////Reseting colors
         printf("\n");
	}
	 printf("\x1b[0m");
}

/////////////////// Prining One binary bit squre
void Cha(int bin[9],int c,char index[3]){			//printing every character
	 for(int j=0;j<9;j++){
		if((j!=0) && (j%3==0)){
		printf("\n\x1b[%dC",c);//////>>>>>>>>Moving the curser
		}
                if(bin[j]==1){//////if the binary =1;;print colour squres

			printf("\x1b[%s""  ",index);
                }else{
                        printf(white"  ");////// if 0 print white squre
                }

	 }
	 printf("\x1b[%dA",2);//REturn the curser 2 line above to start the next squres
}

////////////////////////////////////Printing Every character squre
void Bin(int x,int c,char index[3]){//////// Input the one number from the hashed String
	int rem, dec;
        int bin[9];//creating the nine bit as an array
        dec=x;

        for(int j=8;j>=0;j--){// Change into binary array
                rem=dec%2;
                bin[j]=rem;
                dec=(dec-rem)/2;
        }
                Cha(bin,c,index);//////// Calling the cha function to prin Every no in the array
}

//printing whole URL
void URL(int r,int asci[r],char index[3]){
	int c=14;
if(r==24){ //////////////////// For 24 asci codes

        printf("\x1b[%dA",11);
	///////////////////////////////////

	  for(int i=0;i<16;i++){ //first 16 characters
        if((i!=0) && (i%4==0)){
		printf("\x1b[%dB\x1b[%dD",3,24);
		c=14;
	}
         Bin(asci[i],c,index);
                c=c+6;

	}

///////////Moving Cursor
	  printf("\x1b[%dA\x1b[%dD",15,24);
	  c=14;

//////////////////////////////////////////////////// 17 to 20
	 for(int i=16;i<20;i++){
	if(i==18){
		printf("\x1b[%dB\x1b[%dD",3,12);
		c=14;
	}
	 Bin(asci[i],c,index);
                c=c+6;

} printf("\x1b[%dB\x1b[%dD",3,24);
c=2;
/////////////////////////////////////////////////21 to 24

   for(int i=20;i<24;i++){
        if(i==22){
                printf("\x1b[%dB\x1b[%dD",3,12);
                c=2;
        }
         Bin(asci[i],c,index);
                c=c+6;
   }

printf("\x1b[0m\x1b[%dB\x1b[%dD",11,14);

}else{
printf("\x1b[%dA",29);
c=14;
/////////////////////////////////////////////////// First 100
for(int i=0; i<100;i++){
	if(i!=0 && i%10==0){
		printf("\x1b[%dB\x1b[%dD",3,60);
		c=14;
	}
	Bin(asci[i],c,index);
	c=c+6;
}
c=14;
///////////////////////////////////////////////// 101 t0 116
printf("\x1b[%dA\x1b[%dD",33,60);
for(int i=100;i<116;i++){
	if(i==108){
		printf("\x1b[%dB\x1b[%dD",3,48);
		c=14;
	}
	Bin(asci[i],c,index);
	c=c+6;
}

//////////////////////////////////////////////117 t0 132
c=2;
printf("\x1b[%dB\x1b[%dD",3,60);

for(int i=116;i<132;i++){
	if(i%2==0 && i!=116){
		printf("\x1b[%dB\x1b[%dD",3,12);
		c=2;
	}
	Bin(asci[i],c,index);
	c=c+6;
}
printf("\x1b[%dB\x1b[%dD",11,14);///// move the curser out of Qr codes

}

printf("\x1b[0m"); // Rseting the colour
}





//MAIN FUNCTION////////////////////////////////////////////////////////////////////////

int main(int argc ,char *argv[]){
	//Initializing the wanted variables
	int len=0,r,n,check=0;

	char text[200],*col[]={"black","red","magenta","green","yellow","cyan","blue"};/////////////Creating color array to compare with the argument
	char *ind[]={"40m","41m","45m","42m","43m","46m","44m"};/////////// Ansi color code array to choise the colors


if(argc==1){///// If no command line arguments then print black
	n=0;
	check=1; ////////////// Using check to print the error msg or Qr code deppend on the value
}
/////////////////////////////////////////
else if(argc==2){//////// if one argument >>>>>> "-c" or "-h" else print error message
	if(argv[1][0]=='-' && toupper(argv[1][1])=='H' ){

printf("usage :\n./project1v1.1 -c [black|red|green|yellow|blue|magenta|cyan]\n./project1v1.1 -h for the help about the program\n");
check=2;

}
///////////////

else if(argv[1][0]=='-' && toupper(argv[1][1])=='C'){
	n=0;
check=1;
}
}
///////////////////////////////////////

else if(argc==3 && argv[1][0]=='-' && toupper(argv[1][1])=='C'){

				for(int i=0;i<7;i++) { /////////// LOoping in the color array

			if(cmp(argv[2],col[i])==0){///////////////comparing without case sensitivity
			n=i;
			check=1;
			}
			}
		}
if(check==0){////////////////check=0 then printing error message
printf("Incorrect usage of arguments.\nusage :\n./project1v1.1 -c [black|red|green|yellow|blue|magenta|cyan]\n./project1v1.1 -h for the help about the program\n");}
	else if(check==1)
{

		//Getting input from the user
		printf("Enter the URL:");
		scanf("%s",text);


		//Finding length of the string
		len=strlen(text);


		//checking the length of the string
//>>>>>>>>>>>>>>>> Deviding into 4 cases
		if (len<3){
			printf("String is too short. Not supported by available QR versions\n");


	        }else if(len>120){
			printf("string is too long. Not supported by available QR versions\n");
		}

		else{
			///printf("\x1b[2J"); //cearing screen
system("clear");/////////////////clearing the screen
			if(len<=20){

	                        r=24;
	                        frame(20);

	                        //printing the Three position squres
	                        printf("\x1b[%dA\x1b[%dC",19,2);
	                        squre(2,ind[n]);
	                        printf("\x1b[%dA\x1b[%dC",5,12);
	                        squre(26,ind[n]);
	                        printf("\x1b[%dB\x1b[%dD",7,36);
	                        squre(2,ind[n]);
				}

		else{

			r=132;
///////////////////////////printing the frame and the 3 Position Squres
			frame(38);
			printf("\x1b[%dA\x1b[%dC",37,2);
			squre(2,ind[n]);
			printf("\x1b[%dA\x1b[%dC",5,48);
			squre(62,ind[n]);
			printf("\x1b[%dB\x1b[%dD",25,72);
			squre(2,ind[n]);

				}
		printf("\x1b[0m");//reset color
		int asci[r],hel[r-len-1]; //initializing the hash sting

		//first value of Hased String
		asci[0]=50+len;

		//adding the other character's asci value
		for(int i=1;i<=len;i++){
			asci[i]=Asc(text[(i-1)%len]);
		}
		int p=0;///>>>>>>>>> Adding p after one cycle
		for(int j=0;j<r-len;j++){
			if(j%len-1==0){
				p++;///////////p increase by one in every cycle
			}
			hel[j]=Asc(text[(j-1)%len])+p;

		}
///////// Ading the reverse of the hel array(array which contain the hashed string ) to the asci array
		int m=len+1;
		for(int i=r-len-1;i>=0;i--){ //Reversing and adding the values

			asci[m]=hel[i];
			m++;
		}
		URL(r,asci,ind[n]); ///Calling the URL function to print the QRL

					}

}
return 0;
}
