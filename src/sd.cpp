#include "ff.h"			/* Obtains integer types */
#include "diskio.h"
#include <SPI.h>
#include "Sd2Card.h"

Sd2Card card;

extern "C" DSTATUS SD_disk_status() {
    // SD detect
    return 0;
}

extern "C" DSTATUS SD_disk_initialize() {
    if (card.init(SPI_SPEED)) {
        return 0;
    }
    else {
        return STA_NOINIT;
    }
}

extern "C" DSTATUS SD_disk_read(BYTE *buff, LBA_t sector, UINT count) {
    for (UINT i = 0; i < count; i++) {
        if (card.readBlock(sector, buff) == 0) 
            return 1;
        buff += 512;
        sector++;
    }
    return 0;
}

extern "C" DSTATUS SD_disk_write(BYTE *buff, LBA_t sector, UINT count) {
    for (UINT i = 0; i < count; i++) {
        if (card.writeBlock(sector, buff) == 0) 
            return 1;
        buff += 512;
        sector++;
    }
    
    return 0;
}

bool mounted = false;
FATFS fs;
void mountDisk() {
    if (mounted) return;
    
    if (f_mount(&fs, (TCHAR const *)"/", 1) == FR_OK) {
      /* FatFs Initialization done */
      mounted = true;
    }
    else {
        mounted = false;
    }
}

void SDSetup() {
    SPI.setMISO(SDCARD_MISO_PIN);
    SPI.setMOSI(SDCARD_MOSI_PIN);
    SPI.setSCLK(SDCARD_SCK_PIN);
}