
// // Esse código foi retirado de 
// // https://www.fernandok.com/2018/11/como-gravar-arquivos-em-microsd-com.html#include 
// // Desenvolvido para um módulo com Display TFT incluso

// #include "..\src\include\aplication.h"

// // Nome do arquivo em que os registros serão salvos
// String fileName;

// // Ponteiro do arquivo
// ext::File pFile;

// /* ############################## Importante ##############################

// O registro tem tamanho FIXO de 3 caracteres e seus valores são de:

// 001
// 002
// 003
// 004
// 005
// ...
// 999

// ########################################################################## */
// // Tamanho do registro (default 3)
// int sizeOfRecord = 5; 
// // Exemplo: 
// // 001\r\n = 5 caracteres

// // Construtor que seta o nome do arquivo e o tamanho do registro
// SD_File_Record::SD_File_Record(String _fileName, int _sizeOfRecord)
// { 
//   fileName = _fileName;
//   sizeOfRecord = _sizeOfRecord+2; 
// }

// // Construtor que seta somente o nome do arquivo deixando o tam do registro default
// SD_File_Record::SD_File_Record(String _fileName){ fileName = _fileName; }

// // Funcao de inicialização que configura o Cartão SD com os pinos recebidos por parametro
// bool SD_File_Record::init(int _MICROSD_PIN_CHIP_SELECT, int _MICROSD_PIN_MOSI, int _MICROSD_PIN_MISO, int _MICROSD_PIN_SCK)
// {  return SD.begin(_MICROSD_PIN_CHIP_SELECT, _MICROSD_PIN_MOSI, _MICROSD_PIN_MISO, _MICROSD_PIN_SCK); }

// // Lê a próxima linha do arquivo
// bool SD_File_Record::readFileNextLine(String *line, String *errorMsg)
// {
//   // Se o ponteiro estiver nulo
//   if(!pFile)
//   {
//     // Abre arquivo para leitura
//     pFile = SD.open(fileName.c_str(), FILE_READ);

//     // Se aconteceu algum erro 
//     if(!pFile)
//     {
//       // Guarda msg de erro
//       *errorMsg = "Failed to open the file";
//       // Retorna falso
//       return false;  
//     }
//   }

//   // Se for possível ler o arquivo
//   if(pFile.available())
//   {
//     // Lê arquivo
//     *line = pFile.readStringUntil('\n');
//     // Retorna true
//     return true;
//   }
  
//   // Se não for possível ler o arquivo retorna falso
//   return false;
// }

// //Posiciona ponteiro do arquivo na posição "pos"
// bool SD_File_Record::seekFile(int pos)
// {
//   // Se o ponteiro estiver nulo  
//   if(!pFile)
//     pFile = SD.open(fileName.c_str(), FILE_READ); // Abre o arquivo para leitura

//   // Posiciona o ponteiro na posição multiplicando pelo tamanho do registro
//   return pFile.seek(sizeOfRecord*pos);
// }

// // Escreve no arquivo
// bool SD_File_Record::writeFile(String line, String *errorMsg)
// {
//   // Abre arquivo para escrita
//   pFile = SD.open(fileName.c_str(), FILE_WRITE);

//   // Se foi possível abrir
//   if (pFile) 
//   {
//     // Escreve registro
//     pFile.println(line);
//     // Fecha arquivo
//     pFile.close();
//     // Retorna true
//     return true;
//   }
  
//   // Se não foi possível abrir guarda mensagem de erro e retorna false
//   *errorMsg = "Failed to open the file: "+String(fileName);
//   return false;  
// }
// // Posiciona ponteiro no início do arquivo
// void SD_File_Record::rewind()
// {
//   pFile.seek(0);
// }

// // Lê o último registro do arquivo
// bool SD_File_Record::readFileLastLine(String *line, String *errorMsg)
// {
//   // Variável que guardará o tamanho do arquivo
//   int sizeArq;

//   // Limpa string
//   *errorMsg = "";

//   // Se o arquivo está aberto, fecha
//   if(pFile)
//     pFile.close();

//   // Abre o arquivo para leitura
//   pFile = SD.open(fileName.c_str(), FILE_READ);

//   // Se não foi possível abrir o arquivo
//   if(!pFile)
//   {
//     // Guarda mensagem de erro e retorna false
//     *errorMsg = "Failed to open the file: "+String(fileName);
//     return false;
//   }
    
//   // Obtém o tamanho do arquivo
//   sizeArq = pFile.size();

//   // Se existe ao menos um registro
//   if(sizeArq >= sizeOfRecord)
//     pFile.seek(sizeArq-sizeOfRecord); // Posiciona o ponteiro no final do arquivo menos o tamanho de um registro (sizeOfRecord)

//   // Lê registro retornando o resultado da função "readFileNextLine"
//   return readFileNextLine(*&line, *&errorMsg);  
// }
// // Exclui arquivo
// bool SD_File_Record::destroyFile()
// {
//   // Se o arquivo estiver aberto, fecha
//   if(pFile)
//     pFile.close();

//   // Exclui arquivo e retorna o resultado da função "remove"  
//   return SD.remove((char*)fileName.c_str());
// }


// // Função que busca um registro
// // "pos" é a posição referente ao registro buscado
// String SD_File_Record::findRecord(int pos) 
// {
//   // Linha que receberá o valor do registro buscado
//   String line = "", errorMsg = "";

//   // Posiciona na posição desejada
//   // Obs. A posição se inicia com zero "0" 
//   if(!seekFile(pos))
//     return "Seek error"; 
    
//   // Lê o registro
//   if(!readFileNextLine(&line, &errorMsg))
//     return errorMsg;

//   return line;    
// }

// // Verifica se o arquivo existe
// bool SD_File_Record::fileExists()
// {
//   return SD.exists((char*)fileName.c_str());
// }

// // Cria um novo arquivo, se já existir o arquivo será removido antes
// void SD_File_Record::newFile()
// {
//   if(pFile)
//     pFile.close();

//   SD.remove((char*)fileName.c_str());
//   pFile = SD.open(fileName.c_str(), FILE_WRITE);
//   pFile.close();
// }

// // Obtém o nome do arquivo
// String getFileName()
// {  return fileName; }

// // Seta o nome do arquivo
// void setFileName(String _fileName)
// {  fileName = _fileName; }

// // Obtém o tamanho do registro
// int getSizeRecord()
// { return sizeOfRecord-2; }

// // Seta o tamanho do registro
// void setSizeRecord(int _sizeOfRecord)
// { sizeOfRecord = _sizeOfRecord+2; }