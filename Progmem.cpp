/* 
 * File:   Progmem.cpp
 * Author: doltsa
 * 
 * Created on 5. juin 2014, 12:41
 */

#include "Progmem.h"
#include "Menu.h"

#include <plib.h>
#include <p32xxxx.h>

//extern "C"
//{
unsigned int eedata_addr[PAGE_SIZE]__attribute__((aligned(4096), space(prog)));
//}
const uint32_t PROGMEM_MAGIC = 0x0F1E2D3C;


#define NVM_PROGRAM_PAGE (&eedata_addr[0])
//#define NVM_PROGRAM_PAGE 0xbd008000

void progmem_save_data(S_ParamGen * data)
{
    
    unsigned int PageBuffer[1024];
    NVMProgram((void*) NVM_PROGRAM_PAGE, data, sizeof(S_ParamGen), PageBuffer);
}

void progmem_load_data(S_ParamGen * data)
{
// Cette fonction lis la mémoire programme à l'adresse progmem_addr
// puis vérifie la validité des données. Si tous ce passe bien, les données
// sont copiées dans la stucture data passée par référence

    uint32_t *pDest;
    uint32_t *pNVM;
    int ReadSize;

    S_ParamGen read_data;

    ReadSize = 0;
    pDest = (uint32_t *) &read_data;
    pNVM = (uint32_t *) NVM_PROGRAM_PAGE;

    while(ReadSize < sizeof(S_ParamGen))
    {
        *pDest = *pNVM;
        pDest++;
        pNVM++;
        ReadSize += 4;
    }

    if(read_data.Magic == PROGMEM_MAGIC)
   {
        memcpy(data, &read_data, sizeof(S_ParamGen));
   }


}