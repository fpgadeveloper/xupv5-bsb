/*
 *
 * Xilinx, Inc.
 * XILINX IS PROVIDING THIS DESIGN, CODE, OR INFORMATION "AS IS" AS A 
 * COURTESY TO YOU.  BY PROVIDING THIS DESIGN, CODE, OR INFORMATION AS
 * ONE POSSIBLE   IMPLEMENTATION OF THIS FEATURE, APPLICATION OR 
 * STANDARD, XILINX IS MAKING NO REPRESENTATION THAT THIS IMPLEMENTATION 
 * IS FREE FROM ANY CLAIMS OF INFRINGEMENT, AND YOU ARE RESPONSIBLE 
 * FOR OBTAINING ANY RIGHTS YOU MAY REQUIRE FOR YOUR IMPLEMENTATION
 * XILINX EXPRESSLY DISCLAIMS ANY WARRANTY WHATSOEVER WITH RESPECT TO 
 * THE ADEQUACY OF THE IMPLEMENTATION, INCLUDING BUT NOT LIMITED TO 
 * ANY WARRANTIES OR REPRESENTATIONS THAT THIS IMPLEMENTATION IS FREE 
 * FROM CLAIMS OF INFRINGEMENT, IMPLIED WARRANTIES OF MERCHANTABILITY 
 * AND FITNESS FOR A PARTICULAR PURPOSE.
 */

/*
 * 
 *
 * This file is a generated sample test application.
 *
 * This application is intended to test and/or illustrate some 
 * functionality of your system.  The contents of this file may
 * vary depending on the IP in your system and may use existing
 * IP driver functions.  These drivers will be generated in your
 * SDK application project when you run the "Generate Libraries" menu item.
 *
 */


#include <stdio.h>
#include "xparameters.h"
#include "xil_cache.h"
#include "xintc.h"
#include "intc_header.h"
#include "xbasic_types.h"
#include "xgpio.h"
#include "gpio_header.h"
#include "xemaclite.h"
#include "xemaclite_example.h"
#include "emaclite_header.h"
#include "iic_header.h"
#include "uartlite_header.h"
#include "pcie_header.h"
#include "xsysace.h"
#include "sysace_header.h"


int main() 
{

   static XIntc intc;

   Xil_ICacheEnable();
   Xil_DCacheEnable();

   print("---Entering main---\n\r");

   

   {
      int status;
      
      print("\r\n Running IntcSelfTestExample() for xps_intc_0...\r\n");
      
      status = IntcSelfTestExample(XPAR_XPS_INTC_0_DEVICE_ID);
      
      if (status == 0) {
         print("IntcSelfTestExample PASSED\r\n");
      }
      else {
         print("IntcSelfTestExample FAILED\r\n");
      }
   } 
	
   {
       int Status;

       Status = IntcInterruptSetup(&intc, XPAR_XPS_INTC_0_DEVICE_ID);
       if (Status == 0) {
          print("Intc Interrupt Setup PASSED\r\n");
       } 
       else {
         print("Intc Interrupt Setup FAILED\r\n");
      } 
   }
   

   {
      u32 status;
      
      print("\r\nRunning GpioInputExample() for dip_switches_8bit...\r\n");

      u32 DataRead;
      
      status = GpioInputExample(XPAR_DIP_SWITCHES_8BIT_DEVICE_ID, &DataRead);
      
      if (status == 0) {
         xil_printf("GpioInputExample PASSED. Read data:0x%X\r\n", DataRead);
      }
      else {
         print("GpioInputExample FAILED.\r\n");
      }
   }
   

   {
      u32 status;
      
      print("\r\nRunning GpioOutputExample() for leds_8bit...\r\n");

      status = GpioOutputExample(XPAR_LEDS_8BIT_DEVICE_ID,8);
      
      if (status == 0) {
         print("GpioOutputExample PASSED.\r\n");
      }
      else {
         print("GpioOutputExample FAILED.\r\n");
      }
   }
   

   {
      u32 status;
      
      print("\r\nRunning GpioOutputExample() for leds_positions...\r\n");

      status = GpioOutputExample(XPAR_LEDS_POSITIONS_DEVICE_ID,5);
      
      if (status == 0) {
         print("GpioOutputExample PASSED.\r\n");
      }
      else {
         print("GpioOutputExample FAILED.\r\n");
      }
   }
   

   {
      u32 status;
      
      print("\r\nRunning GpioInputExample() for push_buttons_5bit...\r\n");

      u32 DataRead;
      
      status = GpioInputExample(XPAR_PUSH_BUTTONS_5BIT_DEVICE_ID, &DataRead);
      
      if (status == 0) {
         xil_printf("GpioInputExample PASSED. Read data:0x%X\r\n", DataRead);
      }
      else {
         print("GpioInputExample FAILED.\r\n");
      }
   }
   

   {
      int status;
      
      print("\r\nRunning EmacLitePolledExample() for ethernet_mac...\r\n");
      status = EmacLitePolledExample(XPAR_ETHERNET_MAC_DEVICE_ID);
      if (status == 0) {
         print("EmacLite Polled Example PASSED\r\n");
      }
      else {
         print("EmacLite Polled Example FAILED\r\n");
      }
   }
   

   {
      int status;
            
      
      print("\r\n Running IicSelfTestExample() for iic_eeprom...\r\n");
      
      status = IicSelfTestExample(XPAR_IIC_EEPROM_DEVICE_ID);
      
      if (status == 0) {
         print("IicSelfTestExample PASSED\r\n");
      }
      else {
         print("IicSelfTestExample FAILED\r\n");
      }
   }
   

   {
      int status;
      
      print("\r\nRunning UartLiteSelfTestExample() for mdm_0...\r\n");
      status = UartLiteSelfTestExample(XPAR_MDM_0_DEVICE_ID);
      if (status == 0) {
         print("UartLiteSelfTestExample PASSED\r\n");
      }
      else {
         print("UartLiteSelfTestExample FAILED\r\n");
      }
   }
   
   /*
    * Peripheral SelfTest will not be run for rs232_uart_1
    * because it has been selected as the STDOUT device
    */

   

   {
      int status;
      
      print("\r\nRunning UartLiteSelfTestExample() for rs232_uart_2...\r\n");
      status = UartLiteSelfTestExample(XPAR_RS232_UART_2_DEVICE_ID);
      if (status == 0) {
         print("UartLiteSelfTestExample PASSED\r\n");
      }
      else {
         print("UartLiteSelfTestExample FAILED\r\n");
      }
   }
   

   {
      XStatus status;
            
      
      print("\r\n Running PCIeTestAppExample for pcie_bridge...\r\n");
      
      status = PCIeTestAppExample(XPAR_PCIE_BRIDGE_DEVICE_ID);
      
      if (status == 0) {
         print("PCIeTestAppExample PASSED\r\n");
      }
      else {
         print("PCIeTestAppExample FAILED\r\n");
      }
   }
   

   {
      int status;
      
      print("\r\nRunning SysAceSelfTestExample() for sysace_compactflash...\r\n");
      status = SysAceSelfTestExample(XPAR_SYSACE_COMPACTFLASH_DEVICE_ID);
      if (status == 0) {
         print("SysAceSelfTestExample PASSED\r\n");
      }
      else {
         print("SysAceSelfTestExample FAILED\r\n");
      }
   }

   print("---Exiting main---\n\r");

   Xil_DCacheDisable();
   Xil_ICacheDisable();

   return 0;
}

