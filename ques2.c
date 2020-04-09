include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
 
int main( int argumentc, char* argvariable[] ) {
    int filedone[2];
    pid_t childid;
 
    char readBuffer[50];
    char writeBuffer[50];
    int readCounter;
 
    pipe( filedone );
 
    if( argumentc < 3 ) {
        printf( "Atleast need 2 params " );
        exit(1);
    }
 int fileOpen = open( argvariable[1], 0 );
    int targetFile = open( argvariable[2], 0666 );
     
    if ( fileOpen == -1 || targetFile == -1 ) {
        printf( "Opening file failed " );
        exit(1);
    }
    childid = fork();
 
    if( childid == 0 ) {
        // inside the child prcocess
        close( filedone[1] );
 
        read( filedone[0], readBuffer, sizeof( readBuffer ) );
        printf( "The recived string is : %s", readBuffer);
 
        //Writing to the target fileOpen
        write( targetFile, readBuffer, strlen( readBuffer) + 1 );
    } else {
 // inside the parent process
        close( filedone[0] );
        // code to read from a text file
 
        while( (readCounter = read( fileOpen, readBuffer, sizeof( readBuffer) ) > 0 ) )  {
        write( filedone[1], readBuffer, sizeof( readBuffer ) );
        }
        close( filedone[1] );
    }
}
