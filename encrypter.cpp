/*
ID: ajeet gupta
LANG: C++
LISTEN: dont compile with gcc but with g++
*/
#include<iostream>
#include<stdio.h>
#include<fstream>
#include<string>
#include<cstring>
#include<random>
#include<cstdlib>
#include<cstdio> 
#include<cmath>
#include<time.h>


#define nline   endl
#define INF     1e18
clock_t         start_time;
clock_t         end_time;
typedef long long ll;
typedef unsigned long long ull;


class CYPHER{
    private:
    int SIZE;

    public:
        
    void Caesor(char key, std::ifstream &inputFile, std::ofstream &outputFile, bool encrypt);
    void Vigenere(std::string keyFileName, std::ifstream &inputFile, std::ofstream &outputFile, bool encrypt);

};

void CYPHER :: Caesor (char key, std::ifstream &inputFile, std::ofstream &outputFile, bool encrypt) { 
      start_time = clock(); 

      char letter = 'A';
      int Encoded_Byte = 0;

      while(inputFile.read(&letter, 1)){
        // using uint8_t cause we only want to deal with 8bit of data which is 2^8 = 256 (ASCII RANGE)
         uint8_t result = (encrypt)? letter + key : letter - key;   
         outputFile << result;
         Encoded_Byte++;
    }     
    end_time = clock();

      (encrypt) ? std :: cout <<
       ":-:-:ENCRYPTED:-:-:"<<std::nline : std::
      cout << ":-:-:DECRYPTED:-:-:"<<std::nline;

      std::cout<< " ENCODED-BYTES: " << Encoded_Byte << std::nline;

      double time_taken = ((double) end_time - start_time);
      printf("Calculation Time: %f seconds\n", time_taken);

}

void CYPHER:: Vigenere( std::string keyFileName, std::ifstream &inputFile, std::ofstream &outputFile, bool encrypt){
       unsigned long long keyseed = 0;
       bool USE_GENERATOR = false;
       
       std::ifstream keyFile;
       keyFile.open(keyFileName.c_str(), std::ios::binary);

       if(keyFile.fail()){
          
          keyseed = strtoull(keyFileName.c_str(), NULL, 10);

          if(keyseed == 0){
            std::cerr << "cannot open keyfile: " << keyFileName << std::nline;
            std::cerr << "Enter a valid keyfile or a valid number" << std::nline;
            return;  
          }

          USE_GENERATOR = true;
       }


       std::mt19937 key(keyseed);

       uint8_t keyValue = 0;
       char inputValue = 0;
       int ENCODED_BYTE = 0;
       

       while(inputFile.read(&inputValue, 1)){

          if(USE_GENERATOR){
                
                keyValue = key()%255;
          }else{
               // if keyfile reached to end then it need to restart from beginning 
                if(!(keyFile >> keyValue)){
                    keyFile.clear();
                    keyFile.seekg(0);
                    keyFile >> keyValue;
                }
          }

           uint8_t outputValue = (encrypt)?inputValue + keyValue : inputValue - keyValue;
           outputFile << outputValue;
           ENCODED_BYTE++;

       }
    (encrypt)? std::cout <<  "Encrypted: " << std::nline 
    : std::cout << "Decrypted: "<<std::nline;
    std::cout << ENCODED_BYTE << " bytes" << std::endl;
       
       
 }

int main(int argc, char* argv[]){

       if(argc != 6){
        std::cerr<<"Use: ./EXECUTABLE [type] [encrypt/decrypt] [plain].txt [encrypted].txt key"<<std::nline;
        return EXIT_FAILURE;
        }
     
     std::string ALGORITHM_TYPE = argv[1];
     std::string ENCRYPT_OR_DECRYPT = argv[2];
     std::string INPUT_FILE_NAME = argv[3];
     std::string OUTPUT_FILE_NAME = argv[4];


     std::ifstream inputFile;
     inputFile.open(INPUT_FILE_NAME, std::ios::binary);
     if(inputFile.fail()){
        std::cerr<<"CANNOT OPEN INPUT-FILE: "<< INPUT_FILE_NAME << std::nline;
        return EXIT_FAILURE;
     }
     
     std::ofstream outputFile;
     outputFile.open(OUTPUT_FILE_NAME, std::ios::binary);
     if(outputFile.fail()){
        std::cerr<<"CANNOT OPEN OUTPUT-FILE" << OUTPUT_FILE_NAME << std::nline;
        return EXIT_FAILURE;
     }


   CYPHER cipher;

   if(ALGORITHM_TYPE == "caesar" && ENCRYPT_OR_DECRYPT == "encrypt"){
        cipher.Caesor(argv[5][0], inputFile, outputFile, true);
   }else if(ALGORITHM_TYPE == "caesar" && ENCRYPT_OR_DECRYPT == "decrypt"){
        cipher.Caesor(argv[5][0], inputFile, outputFile, false);
   }else if(ALGORITHM_TYPE =="vigenere" && ENCRYPT_OR_DECRYPT == "encrypt"){
         cipher.Vigenere(argv[5], inputFile, outputFile, true);
    }else if(ALGORITHM_TYPE == "vigenere" && ENCRYPT_OR_DECRYPT == "decrypt"){
           cipher.Vigenere(argv[5], inputFile, outputFile, false);
    }else{
        std::cerr << "Use: ./EXECUTABLE [type] [encrypt/decrypt] [plain].txt [encrypted].txt key" << std::nline;
   }


   inputFile.close();
   outputFile.close();

    return EXIT_SUCCESS;
}