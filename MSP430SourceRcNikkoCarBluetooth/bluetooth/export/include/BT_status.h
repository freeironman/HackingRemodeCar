
/**
 *  @file BT_status.h
 *
 *  This file lists all the macros and APIs that are exported
 *  to get/set the EtherMind Status Flag.
 */

/*
 *  Copyright (C) 2000-2010. MindTree Ltd.
 *  All rights reserved.
 */

#ifndef _H_BT_STATUS_
#define _H_BT_STATUS_

/* ----------------------------------------- Header File Inclusion */
#include "BT_common.h"


/* ----------------------------------------- Global Definitions */
/*
 *  EtherMind Status Flag
 *  ---------------------
 *      31 30 29            12 11 10 09 08 07 06 05 04 03 02 01 00
 *     ___________________________________________________________
 *     |  |  |  |  ....... |  |  |  |  |  |  |  |  |  |  |  |  |  |
 *     |__|__|__|__________|__|__|__|__|__|__|__|__|__|__|__|__|__|
 *
 *     <-------------------------------------------><------------->
 *                           |                            |
 *                           |                            |
 *                           v                            v
 *               Reserved for future use        Defined Status Bits
 *
 *  Status Bit Definitions
 *  ----------------------
 *       04 03 02 01 00
 *      _______________
 *      |  |  |  |  |  |
 *      |__|__|__|__|__|
 *        |  |  |  |  |
 *        |  |  |  |  |____ Memory Allocation Failed
 *        |  |  |  |
 *        |  |  |  |_______ HCI/L2CAP Data Buffer Full
 *        |  |  |
 *        |  |  |__________ HCI Command Queue Full
 *        |  |
 *        |  |_____________ Timer Entity Unavailable
 *        |
 *        |________________ Write/EtherMind Task Entity Unavailable
 */

/** Count of maximum defined bit in Status Flag */
#define STATUS_NUM_DEFINED_BITS                 5

/** Status Bit Definitions */
#define STATUS_BIT_MEM_ALLOC_FAILED             0
#define STATUS_BIT_DATA_BUFFER_FULL             1
#define STATUS_BIT_HCI_COMMAND_Q_FULL           2
#define STATUS_BIT_TIMER_ENTITY_FULL            3
#define STATUS_BIT_WT_ENTITY_FULL               4

/** Set/Reset Status Flag Bits */
#define STATUS_BIT_SET                          0x01
#define STATUS_BIT_RESET                        0x00


/* ----------------------------------------- Structures/Data Types */


/* ----------------------------------------- Function Declarations */
#ifdef __cplusplus
extern "C"{
#endif

#ifdef BT_STATUS

/** Initialization of EtherMind Status Flag */
void status_init (void);
void status_bt_init (void);

/**
 *  \fn BT_status_get_flag
 *
 *  \par Description
 *  This function returns the value of the EtherMind Status Flag.
 *  The EtherMind Status Flag is reset to zero after returning the
 *  current value.
 *
 *  \param flag_val (OUT)
 *         Caller allocated UINT32 variable, where the current value
 *         of the EtherMind Status Flag needs to be copied.
 *
 *  \return None
 */
void BT_status_get_flag
     (
         OUT UINT32 *    flag_val
     );

/**
 *  \fn BT_status_get_bit
 *
 *  \par Description
 *  This API returns the value of a bit of EtherMind Status Flag.
 *  The value of bit in EtherMind Status Flag is reset to zero
 *  after returning the current value.
 *
 *  \param bit_no (IN)
 *         The position of the bit in the EtherMind Status Flag
 *  \param bit_val (OUT)
 *         Caller allocated UCHAR variable, where the current value
 *         of the specified bit of EtherMind Status Flag needs to be
 *         copied.
 *
 *  \return None
 */
void BT_status_get_bit
     (
         IN  UCHAR      bit_no,
         OUT UCHAR *    bit_val
     );

/**
 *  \fn BT_status_set_bit
 *
 *  \par Description
 *  This API sets/resets the value of a bit of EtherMind Status Flag.
 *  Upon a change in EtherMind Status Flag, this function calls the
 *  platform specific function to handle change in flag value.
 *
 *  \param bit_no (IN)
 *         The position of the bit in the EtherMind Status Flag
 *  \param op (IN)
 *         STATUS_BIT_SET or STATUS_BIT_RESET
 *
 *  \return None
 */
void BT_status_set_bit
     (
         IN  UCHAR      bit_no,
         IN  UCHAR      op
     );

/* Platform specific handling of change in Status Flag */
void status_set_bit_pl
     (
         IN  UINT32    flag
     );

#else  /* BT_STATUS */

#define status_init()
#define status_bt_init()

#define BT_status_get_flag(x)
#define BT_status_get_bit(x, y)
#define BT_status_set_bit(x, y)

#endif /* BT_STATUS */

/** Shutdown of EtherMind Status Flag */
#define status_bt_shutdown()

#ifdef __cplusplus
};
#endif


#endif /* _H_BT_STATUS_ */

