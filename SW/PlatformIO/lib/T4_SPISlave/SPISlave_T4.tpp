//changes
#include "configuration/globalConfig.h"
#include "configuration/cameraAnalysisConfig.h"

#define SLAVE_CR spiAddr[4]
#define SLAVE_FCR spiAddr[22]
#define SLAVE_IER spiAddr[6]
#define SLAVE_CFGR0 spiAddr[8]
#define SLAVE_CFGR1 spiAddr[9]
#define SLAVE_TDR spiAddr[25]
#define SLAVE_RDR spiAddr[29]
#define SLAVE_SR spiAddr[5]
#define SLAVE_TCR_REFRESH spiAddr[24] = (0UL << 27) | LPSPI_TCR_FRAMESZ(bits - 1)
#define SLAVE_PORT_ADDR volatile uint32_t *spiAddr = &(*(volatile uint32_t*)(0x40394000 + (0x4000 * _portnum)))
#define SLAVE_PINS_ADDR volatile uint32_t *spiAddr = &(*(volatile uint32_t*)(0x401F84EC + (_portnum * 0x10)))

 
void lpspi4_slave_isr() {
  _LPSPI4->SLAVE_ISR();
}


SPISlave_T4_FUNC SPISlave_T4_OPT::SPISlave_T4() {
  if ( port == &SPI ) {
    _LPSPI4 = this;
    _portnum = 3;
    CCM_CCGR1 |= (3UL << 6);
    nvic_irq = 32 + _portnum;
    _VectorsRam[16 + nvic_irq] = lpspi4_slave_isr;

    /* Alternate pins not broken out on Teensy 4.0/4.1 for LPSPI4 */
    SLAVE_PINS_ADDR;
    spiAddr[0] = 0; /* PCS0_SELECT_INPUT */
    spiAddr[1] = 0; /* SCK_SELECT_INPUT */
    spiAddr[2] = 0; /* SDI_SELECT_INPUT */
    spiAddr[3] = 0; /* SDO_SELECT_INPUT */
    IOMUXC_SW_MUX_CTL_PAD_GPIO_B0_03 = 0x3; /* LPSPI4 SCK (CLK) */
    IOMUXC_SW_MUX_CTL_PAD_GPIO_B0_01 = 0x3; /* LPSPI4 SDI (MISO) */
    IOMUXC_SW_MUX_CTL_PAD_GPIO_B0_02 = 0x3; /* LPSPI4 SDO (MOSI) */
    IOMUXC_SW_MUX_CTL_PAD_GPIO_B0_00 = 0x3; /* LPSPI4 PCS0 (CS) */
  } 
}


SPISlave_T4_FUNC void SPISlave_T4_OPT::swapPins(bool enable) {
  SLAVE_PORT_ADDR;
  SLAVE_CR &= ~LPSPI_CR_MEN; /* Disable Module */
  SLAVE_CFGR1 = (SLAVE_CFGR1 & 0xFCFFFFFF) | (enable) ? (3UL << 24) : (0UL << 24);
  SLAVE_CR |= LPSPI_CR_MEN; /* Enable Module */
  if ( sniffer_enabled ) sniffer();
}


SPISlave_T4_FUNC void SPISlave_T4_OPT::sniffer(bool enable) {
  SLAVE_PORT_ADDR;
  sniffer_enabled = enable;
  if ( port == &SPI ) {
    if ( sniffer_enabled ) {
      if ( SLAVE_CFGR1 & (3UL << 24) ) { /* if pins are swapped */
        IOMUXC_SW_MUX_CTL_PAD_GPIO_B0_03 = 0x3; /* LPSPI4 SCK (CLK) */
        IOMUXC_SW_MUX_CTL_PAD_GPIO_B0_01 = 0x0; /* LPSPI4 SDI (MISO) */
        IOMUXC_SW_MUX_CTL_PAD_GPIO_B0_02 = 0x3; /* LPSPI4 SDO (MOSI) */
        IOMUXC_SW_MUX_CTL_PAD_GPIO_B0_00 = 0x3; /* LPSPI4 PCS0 (CS) */
      }
      else {
        IOMUXC_SW_MUX_CTL_PAD_GPIO_B0_03 = 0x3; /* LPSPI4 SCK (CLK) */
        IOMUXC_SW_MUX_CTL_PAD_GPIO_B0_01 = 0x3; /* LPSPI4 SDI (MISO) */
        IOMUXC_SW_MUX_CTL_PAD_GPIO_B0_02 = 0x0; /* LPSPI4 SDO (MOSI) */
        IOMUXC_SW_MUX_CTL_PAD_GPIO_B0_00 = 0x3; /* LPSPI4 PCS0 (CS) */
      }
    }
    else {
      IOMUXC_SW_MUX_CTL_PAD_GPIO_B0_03 = 0x3; /* LPSPI4 SCK (CLK) */
      IOMUXC_SW_MUX_CTL_PAD_GPIO_B0_01 = 0x3; /* LPSPI4 SDI (MISO) */
      IOMUXC_SW_MUX_CTL_PAD_GPIO_B0_02 = 0x3; /* LPSPI4 SDO (MOSI) */
      IOMUXC_SW_MUX_CTL_PAD_GPIO_B0_00 = 0x3; /* LPSPI4 PCS0 (CS) */
    }
  }
}


SPISlave_T4_FUNC bool SPISlave_T4_OPT::active() {
  SLAVE_PORT_ADDR;
  return ( !(SLAVE_SR & (1UL << 9)) ) ? 1 : 0;
}


SPISlave_T4_FUNC bool SPISlave_T4_OPT::available() {
  SLAVE_PORT_ADDR;
  return ( (SLAVE_SR & (1UL << 8)) ) ? 1 : 0;
}


SPISlave_T4_FUNC void SPISlave_T4_OPT::pushr(uint32_t data) {
  SLAVE_PORT_ADDR;
  SLAVE_TDR = data;
}


SPISlave_T4_FUNC uint32_t SPISlave_T4_OPT::popr() {
  SLAVE_PORT_ADDR;
  uint32_t data = SLAVE_RDR;
  SLAVE_SR = (1UL << 8); /* Clear WCF */
  return data;
}

//changes
extern volatile int spiBufferIdx;
extern volatile int spiTransferComplete;
extern volatile int imageAnalysIsComplete;

#ifndef ANALYSIS_ON_CAMERA
extern uint32_t spiRx[VIDEO_RESOLUTION_X*NUMBER_OF_LINES];
extern uint32_t spiFrontBuffer[VIDEO_RESOLUTION_X*NUMBER_OF_LINES];
extern uint32_t spiBackBuffer[VIDEO_RESOLUTION_X*NUMBER_OF_LINES];
#endif

#ifdef ANALYSIS_ON_CAMERA
extern uint32_t spiRx[SPI_BUFFER_WIDTH];
extern uint32_t spiFrontBuffer[SPI_BUFFER_WIDTH];
extern uint32_t spiBackBuffer[SPI_BUFFER_WIDTH];
#endif

extern uint32_t* spiBufferToRead;

uint32_t* spiBufferToWrite = spiFrontBuffer;

int test = 0;


/**
 * spi interrupt method taken from the library
 * and enriched with swap Buffer implementation and modification for own array
 */
SPISlave_T4_FUNC void __attribute__((section(".fustrun"))) SPISlave_T4_OPT::SLAVE_ISR() {

  SLAVE_PORT_ADDR;

#if 0
  if ( _spihandler ) {
    _spihandler();
    SLAVE_SR = 0x3F00;
    asm volatile ("dsb");
    return;
  }
#endif

  if ( SLAVE_SR & (1UL << 11) ) {
    /* transmit error, clear flag, check cabling */
    SLAVE_SR = (1UL << 11);
    transmit_errors++;
  }

  //incoming data
  if ( (SLAVE_SR & (1UL << 1)) ) {
    //write data to array
    spiBufferToWrite[spiBufferIdx] = SLAVE_RDR;
    
    //increment index depending on array size
    #ifndef ANALYSIS_ON_CAMERA
      if (spiBufferIdx < VIDEO_RESOLUTION_X*NUMBER_OF_LINES-1) spiBufferIdx++;
    #endif
    
    #ifdef ANALYSIS_ON_CAMERA
      if(VIDEO_RESOLUTION_X == 320) {
        spiBufferToWrite[spiBufferIdx] = spiBufferToWrite[spiBufferIdx] * 320 / 253; //mapping back from 0-253 to 0 - 320
      }
      if (spiBufferIdx < SPI_BUFFER_WIDTH-1) { 
        spiBufferIdx++; //incremet buffer until 239 ()
      }
    #endif
    
    SLAVE_SR = (1UL << 1);
  }

  if ( (SLAVE_SR & (1UL << 0)) ) {
    SLAVE_TDR = 0x34;
  }

  //tansfer complete
  if ( (SLAVE_SR & (1UL << 9)) ) {
    
    if(!spiTransferComplete) { 
    	
      //if image analysis is completed swap the buffers for read an write
      if(imageAnalysIsComplete) {
        if (spiBufferToWrite == spiFrontBuffer) {
          spiBufferToWrite = spiBackBuffer;
          spiBufferToRead = spiFrontBuffer;
        }
        else {
          spiBufferToWrite = spiFrontBuffer;
          spiBufferToRead = spiBackBuffer;
        }
      }
      spiTransferComplete = 1;
    }
  }
  SLAVE_SR = 0x3F00;
  asm volatile ("dsb");
}



SPISlave_T4_FUNC void SPISlave_T4_OPT::begin() {
  SLAVE_PORT_ADDR;
  SLAVE_CR = LPSPI_CR_RST; /* Reset Module */
  SLAVE_CR = 0; /* Disable Module */
  SLAVE_FCR = 0;    //x10001; /* 1x watermark for RX and TX */
  SLAVE_IER = 0x01 | 0x200; /* Interrupt enable bits */
  SLAVE_CFGR0 = 0;
  SLAVE_CFGR1 = 0;
  SLAVE_CR |= LPSPI_CR_MEN | LPSPI_CR_DBGEN; /* Enable Module, Debug Mode */
  SLAVE_SR = 0x3F00; /* Clear status register */
  SLAVE_TCR_REFRESH;
  SLAVE_TDR = 0x0; /* dummy data, must populate initial TX slot */
  NVIC_ENABLE_IRQ(nvic_irq);
  NVIC_SET_PRIORITY(nvic_irq, 1);
}