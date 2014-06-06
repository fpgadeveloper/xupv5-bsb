#define TESTAPP_GEN

/* $Id: xpcie_tapp_example.c,v 1.1.2.2 2011/03/24 10:15:29 svemula Exp $ */
/****************************************************************************
*
* (c) Copyright 2011 Xilinx, Inc. All rights reserved.
*
* This file contains confidential and proprietary information of Xilinx, Inc.
* and is protected under U.S. and international copyright and other
* intellectual property laws.
*
* DISCLAIMER
* This disclaimer is not a license and does not grant any rights to the
* materials distributed herewith. Except as otherwise provided in a valid
* license issued to you by Xilinx, and to the maximum extent permitted by
* applicable law: (1) THESE MATERIALS ARE MADE AVAILABLE "AS IS" AND WITH ALL
* FAULTS, AND XILINX HEREBY DISCLAIMS ALL WARRANTIES AND CONDITIONS, EXPRESS,
* IMPLIED, OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF
* MERCHANTABILITY, NON-INFRINGEMENT, OR FITNESS FOR ANY PARTICULAR PURPOSE;
* and (2) Xilinx shall not be liable (whether in contract or tort, including
* negligence, or under any other theory of liability) for any loss or damage
* of any kind or nature related to, arising under or in connection with these
* materials, including for any direct, or any indirect, special, incidental,
* or consequential loss or damage (including loss of data, profits, goodwill,
* or any type of loss or damage suffered as a result of any action brought by
* a third party) even if such damage or loss was reasonably foreseeable or
* Xilinx had been advised of the possibility of the same.
*
* CRITICAL APPLICATIONS
* Xilinx products are not designed or intended to be fail-safe, or for use in
* any application requiring fail-safe performance, such as life-support or
* safety devices or systems, Class III medical devices, nuclear facilities,
* applications related to the deployment of airbags, or any other applications
* that could lead to death, personal injury, or severe property or
* environmental damage (individually and collectively, "Critical
* Applications"). Customer assumes the sole risk and liability of any use of
* Xilinx products in Critical Applications, subject only to applicable laws
* and regulations governing limitations on product liability.
*
* THIS COPYRIGHT NOTICE AND DISCLAIMER MUST BE RETAINED AS PART OF THIS FILE
* AT ALL TIMES.
*
*****************************************************************************/
/****************************************************************************/
/**
* @file xpcie_tapp_example.c
*
* This file contains an example for testing PCIe IP (v4.03) and its
* Level_1 driver.
*
* The example handles PCIe IP when it is configured as an end point. It
* shows how to use the standalone driver interface to write test application
* example.
*
* @note
*
*
*<pre>
* MODIFICATION HISTORY:
*
* Ver   Who  Date     Changes
* ----- ---- -------- -----------------------------------------------
* 3.00a MH  03/18/09  original code
* 4.01a rkv 03/03/11  Fixed compiler warnings
*</pre>
*****************************************************************************/

/***************************** Include Files ********************************/

#include "xparameters.h"    /* Defines for XPAR constants */
#include "xpcie.h"          /* XPcie level 1 interface */
#include "stdio.h"

#ifdef XPAR_XUARTNS550_NUM_INSTANCES
#include "xuartns550.h"
#endif

/************************** Constant Definitions ****************************/

/*
 * Define the offset of 32-bit location within the configuration space from
 * the beginning of the configuration space.
 */

#define PCIE_CFG_ID_REG           0x0000  /* Vendor ID/Device ID offset */
#define PCIE_CFG_CMD_STATUS_REG   0x0001  /* Command/Status Register Offset */

/*
 * Cache Line/Latency Timer/Header
 * Type/BIST Register Offset
 */
#define PCIE_CFG_CAH_LAT_HD_REG   0x0003
#define PCIE_CFG_BAR_ZERO_REG     0x0004  /* Bar 0 offset */

/*
 * Define the location of different
 * needed bits/registers
 * within their 32-bit offset
 * in the configuration space.
 */

#define PCIE_CFG_CMD_IO_EN        0x01000000    /* I/O access enable */
#define PCIE_CFG_CMD_MEM_EN       0x02000000    /* Memory access enable */
#define PCIE_CFG_CMD_BUSM_EN      0x04000000    /* Bus master enable */
#define PCIE_CFG_CMD_PARITY       0x40000000    /* parity errors response */
#define PCIE_CFG_CMD_SERR_EN      0x00010000    /* SERR report enable */
#define PCIE_CFG_CMD_INTR_DISA    0x00040000    /* Interrupt Disable */


/*
 * Bridge Bus Master Interr.
 */
#define PCIE_CFG_BUS_MASTER_ENABLED    0x00004000

/*
 * The Base Address of the Bridge
 */

#define PCIE_BASE_ADDR      mParPcie(BASEADDR)

#define PCIE_NAME           XPAR_PCIE_BRIDGE_
#define mCat(prefix,value)  prefix ## value
#define mXcat(x,y)          mCat(x,y)
#define mParPcie(x)         mXcat(XPAR_PCIE_BRIDGE_,x)

/**************************** Type Definitions ******************************/


/***************** Macros (Inline Functions) Definitions ********************/


/************************** Function Prototypes *****************************/
#ifndef TESTAPP_GEN
#ifdef XPAR_XUARTNS550_NUM_INSTANCES
int Setup_Uart (XUartNs550 *XlnxUart550Ptr, u16 UartID);
#endif
#endif

int PCIeTestAppExample(u16 EndPointID);


/************************** Variable Definitions ****************************/

XPcie XlnxEndPoint;         /* Allocate PCIe End Point IP Instance */

#ifndef TESTAPP_GEN
#ifdef XPAR_XUARTNS550_NUM_INSTANCES
XUartNs550 UartNs550;       /* Allocate UART 16550 IP Instance */
#endif
#endif

/****************************************************************************/
/**
* This function is the entry point for PCIe End Point Enable Example
*
* @param none
*
* @return XST_SUCCESS if successful, XST_FAILURE if unsuccessful
*
* @note none.
*
*
*****************************************************************************/
#ifndef TESTAPP_GEN
int main(void)
{
	int Status;

#ifdef XPAR_XUARTNS550_NUM_INSTANCES
   /* initialize Uart 16550 */
	Status = Setup_Uart(&UartNs550, XPAR_UARTNS550_0_DEVICE_ID);


	if (Status != XST_SUCCESS) {
		return (1);
	}
#endif

	/* initialize End Point */
	Status = PCIeTestAppExample(XPAR_PCIE_0_DEVICE_ID);

	if ( Status != XST_SUCCESS) {
		return (1);
	}
	else {
		return (0);
	}
}
#endif

/****************************************************************************/
/**
* This function sets up the UART 16550 to its default settings 19K, 8b, 1S, 0P
*
* @param XlnxUart550Ptr is a pointer to an instance of XUarNs550 data
*        structure represents a UART 16550 IP.
*
* @param UartID is UART 16550 IP unique ID
*
* @return XST_SUCCESS if successful, XST_FAILURE if unsuccessful
*
* @note none.
*
*
*****************************************************************************/
#ifndef TESTAPP_GEN
#ifdef XPAR_XUARTNS550_NUM_INSTANCES
int Setup_Uart (XUartNs550 *XlnxUart550Ptr, u16 UartID)
{
	int Status;

	Status = XUartNs550_Initialize(XlnxUart550Ptr, UartID);

	if (Status != XST_SUCCESS)
	{
		return XST_FAILURE;
	}

	return XST_SUCCESS;
}
#endif
#endif
/****************************************************************************/
/**
* This function initializes a PCIe IP built as an end point.
*
* @param XlnxEndPointPtr is a pointer to an instance of XPcie data
*        structure represents an end point IP.
*
* @param EndPointID is PCIe IP unique ID
*
* @return XST_SUCCESS if successful, XST_FAILURE if unsuccessful
*
* @note None.
*
*
******************************************************************************/
int PCIeTestAppExample(u16 EndPointID)
{
	int Status;
	XPcie_Config *ConfigPtr;
	XPcie *XlnxEndPointPtr = &XlnxEndPoint;


#ifndef TESTAPP_GEN
	xil_printf("PcieEndPointExample\r\n");
#endif

	ConfigPtr = XPcie_LookupConfig(EndPointID);

	Status = XPcie_CfgInitialize(XlnxEndPointPtr, ConfigPtr,
	                                               ConfigPtr->BaseAddress);

	if (Status != XST_SUCCESS) {
#ifndef TESTAPP_GEN
		xil_printf("Failed to initialize PCIe End Point Instance\r\n");
#endif
		return Status;
	}

	/* Enable the bridge so that TLP transactions can go through */
	XPcie_EnablePCIeConnection(XlnxEndPointPtr, 3);

#ifndef TESTAPP_GEN
	xil_printf("PCIeTestAppExampleEnd\r\n");
#endif

	return XST_SUCCESS;
}

